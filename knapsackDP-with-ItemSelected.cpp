#include<bits/stdc++.h>

using namespace std;

int main()
{
    //using dynamic programming
  //  int p[]={1,2,5,6};
   //int w[]={2,3,4,5};
   //int cap =8;
    int p[] = {10, 5, 15, 7, 6};
    int w[] = {2, 3, 5, 7, 11};
      int cap=15;
      int n=sizeof(w)/sizeof(w[0]);
      cout<<"Capacity of weight bag : "<<cap<<endl;
    int dp[n+1][cap+1];
    
    
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        
        
        }
        for(int j=0;j<=cap;j++)
        {
        
            dp[0][j]=0;
        
        }
    
    
    
  for(int i=1;i<=n;i++)
  {
  
      for(int j=1;j<=cap;j++)
      { 
            if(w[i-1]<=j)
            {
                 dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+p[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
                
            }

      }
  
  }
    
       for(int i=0;i<=n;i++)
    {
    
      for(int j=0;j<=cap;j++)
      {
            cout<<dp[i][j]<<" ";
      
      }
            cout<<endl;
  
        }
        
        int profitM=dp[n][cap];
        int i=n-1;
        int j=cap-1;
        
        while(i>=0 && profitM>0)
        {  
        int t=dp[i][j];
        //int w=w[i-1];
        if(profitM!=t && profitM-w[i]>=0)
        {   
               cout<<"Item selected :"<<i+1<<endl;
            profitM-=w[i];
            j=j-w[i];
            
        }
        i--;
        
           
        }
        
        
        cout<<endl;
        cout<<"Max Profit  : "<<dp[n][cap]<<endl;
        
        
        
        

  return 0;
}
