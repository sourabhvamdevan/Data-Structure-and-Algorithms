import os
import re
import subprocess
from datetime import datetime

ROOT = os.path.dirname(os.path.abspath(__file__))
README = os.path.join(ROOT, "README.md")

extensions = {
    ".cpp": 0,
    ".java": 0,
    ".c": 0,
    ".py": 0
}

problems = 0

ignore = {
    ".git",
    ".github",
    "__pycache__",
    ".idea",
    ".vscode"
}

for root, dirs, files in os.walk(ROOT):
    dirs[:] = [d for d in dirs if d not in ignore]

    for file in files:
        ext = os.path.splitext(file)[1].lower()
        if ext in extensions:
            extensions[ext] += 1
            problems += 1

try:
    commits = subprocess.check_output(
        ["git", "rev-list", "--count", "HEAD"],
        text=True
    ).strip()
except:
    commits = "Unknown"

goal = ((problems // 100) + 1) * 100
percentage = round((problems / goal) * 100, 2)

stats = f"""
## Repository Statistics

| Metric | Value |
|---------|------:|
| Total Problems | {problems} |
| C++ Solutions | {extensions['.cpp']} |
| Java Solutions | {extensions['.java']} |
| C Solutions | {extensions['.c']} |
| Python Solutions | {extensions['.py']} |
| Total Commits | {commits} |
| Last Updated | {datetime.now().strftime('%d %B %Y')} |

## Progress

{problems} / {goal} Problems ({percentage}%)
"""

with open(README, "r", encoding="utf-8") as f:
    content = f.read()

pattern = r"<!-- STATS_START -->(.*?)<!-- STATS_END -->"

replacement = (
    "<!-- STATS_START -->\n"
    + stats +
    "\n<!-- STATS_END -->"
)

if re.search(pattern, content, flags=re.S):
    content = re.sub(pattern, replacement, content, flags=re.S)
else:
    content += "\n\n" + replacement

with open(README, "w", encoding="utf-8") as f:
    f.write(content)

print("README statistics updated successfully.")
