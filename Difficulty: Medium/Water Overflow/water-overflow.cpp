class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        // code here
  vector<vector<double>> memo(R, vector<double>(R, 0.0));
    
 
    memo[0][0] = K;
    
  
    for (int row = 0; row < R - 1; row++) {
        for (int col = 0; col <= row; col++) {
            
        
            double excess = max(0.0, memo[row][col] - 1.0);
            

            if (excess > 0) {
                
            
                memo[row][col]=1.0;
                
            
                memo[row + 1][col] += excess / 2.0;
                memo[row + 1][col + 1] += excess / 2.0;
            }
        }
    }
    

    return min(1.0, memo[R - 1][C - 1]);
         
         
    }
};