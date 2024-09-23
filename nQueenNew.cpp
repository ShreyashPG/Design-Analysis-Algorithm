#include<bits/stdc++.h>

using namespace std;

void printBoard(vector<string> board) {
    for ( auto cell : board) {
       
            cout << cell << " ";
       cout<<endl;
    }
    
    cout << endl;
}






void solve(int n, vector<vector<string>> &ans,vector<string> &board,int col,
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
                //board[row]=(col+1);
                board[row][col]='Q';
                solve(n,ans,board,col+1,lrow,d1,d2);
                //board[row]=0;
                board[row][col]='.';
                lrow[row]=0;
                d1[n-1+col-row]=0;
                d2[row+col]=0;
            }
        }
    }



    vector<vector<string>> nQueen(int n) {
        // code here
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> d1(2*n-1,0);
        vector<int> d2(2*n-1,0);
        vector<int> lrow(n,0);
        solve(n,ans,board,0,lrow,d1,d2);
        sort(ans.begin(),ans.end());
        return ans;
       
       
       
    }
    
    
    int main()
    {
        int n;
        cout<<"Enter value of n : ";
        cin>>n;
        cout<<endl;
        if(n<=3)
        {
            cout<<"Value of n should be greater than 3"<<endl;
            return 0;
        }
        vector<vector<string>> ans=nQueen(n);
        
          // Print results
    cout << "Total solutions: " << ans.size() << endl;
    for (auto solution : ans) {
        printBoard(solution);
    }

    return 0;
        
    
    
    }
    
    
