class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int fcol = 0;
        int frow = 0;
        int lcol = matrix[0].size()-1;
        int lrow = matrix.size()-1;
        
        vector<int> ans;
        while(frow <= lrow and fcol <= lcol)
        {
            for(int j = fcol; j <= lcol; j++)
                ans.push_back(matrix[frow][j]);
                frow++; 

            for(int i = frow; i <= lrow; i++)
                ans.push_back(matrix[i][lcol]);
                lcol--; 
            
            if(frow<=lrow)  
            {
               for(int j = lcol; j>= fcol; j--)
               ans.push_back(matrix[lrow][j]);
               lrow--;  
            }
            
            if(fcol<=lcol) 
            {
                for(int i = lrow; i >= frow; i--)
                ans.push_back(matrix[i][fcol]);
                fcol++; 
            } 
        }
        return ans;
    }
};