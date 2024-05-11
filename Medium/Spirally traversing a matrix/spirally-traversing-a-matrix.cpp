//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>res;
        int up=0, right=c-1, down=r-1, left=0, i;
        while(up<=down && left<=right )
        {
            for(i=up;i<=right;i++)
            {
                res.push_back(matrix[up][i]);
            }
            up++;
            for(i=up;i<=down;i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if(up<=down)
            {
                for(i=right;i>=left;i--)
                {
                    res.push_back(matrix[down][i]);
                }
            down--;
            }
            if(left<=right)
            {
                for(i=down;i>=up;i--)
                {
                    res.push_back(matrix[i][left]);
                }
            left++;
            }
        
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends