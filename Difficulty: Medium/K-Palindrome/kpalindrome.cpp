

class Solution {
public:
    bool kPalindrome(string &s, int k) {
        int n = s.size();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
      
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
    
        for (int i = 1; i <= n; ++i)
        
        {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == rev_s[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else
                
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            
            
            
            prev=curr;
        }
        
        int lps=prev[n];
        int min_deletions=n - lps;
        
        return min_deletions<=k;
    }
};