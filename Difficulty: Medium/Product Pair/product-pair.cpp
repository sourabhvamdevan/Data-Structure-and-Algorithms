class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        
        unordered_set<long long> seen;

        for (int i = 0; i < arr.size(); i++) {
            long long current = arr[i];

    
            if (target == 0)
            
            {
          
                if (current == 0 && !seen.empty()) {
                    return true;
                }
           
                if (seen.count(0))
                
                {
                    return true;
                }
                
                
            } 
   
            else if (current != 0 && target % current == 0) {
                long long complement = target / current;
                if (seen.count(complement)) {
                    return true;
                }
            }

    
            seen.insert(current);
        }

        return false;
        
    }
};