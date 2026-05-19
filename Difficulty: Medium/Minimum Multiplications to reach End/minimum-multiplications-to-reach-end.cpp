


class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        
     
        const int MOD=1000;
        
        vector<int> dist(MOD, -1);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int num : arr) {
                int next_node = (1LL * node * num) % MOD;
                
                if (dist[next_node] == -1) {
                    dist[next_node] = dist[node] + 1;
                    
                    if (next_node == end) {
                        return dist[next_node];
                    }
                    
                    q.push(next_node);
                }
            }
        }
        
        return -1;
    }
};