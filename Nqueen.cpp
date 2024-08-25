// time Complexity - O(n2)
//space complexity - O(n2)
// usgin hashing 
 void solve(int n, vector<vector<int>> &ans,vector<int> &board,int col,
            vector<int> &lrow,vector<int> &d1,vector<int> &d2)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(lrow[row]==0 && d1[n-1+col-row]==0 && d2[row+col]==0)
            {
                lrow[row]=1;
                d1[n-1+col-row]=1;
                d2[row+col]=1;
                board[row]=(col+1);
                solve(n,ans,board,col+1,lrow,d1,d2);
                board[row]=0;
                lrow[row]=0;
                d1[n-1+col-row]=0;
                d2[row+col]=0;
            }
        }
    }



    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> board(n,0);
        vector<int> d1(2*n-1,0);
        vector<int> d2(2*n-1,0);
        vector<int> lrow(n,0);
        solve(n,ans,board,0,lrow,d1,d2);
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
