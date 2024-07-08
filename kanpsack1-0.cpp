#include<bits/stdc++.h>
using namespace std;

void sorting (vector<float> &arr)
{
    
    int i,j,key;
    sort(arr.begin(),arr.end());
//   for (i = 1; i < arr.size(); i++) {
//         key = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
}



void solve()
{
    int n;
    cout<<"Enter no of items"<<" ";
     cin>>n;
     cout<<endl;
    int c;
      cout<<"Enter capacity :"<<" ";
    cin>>c;

   
    cout<<endl;
vector<int> p;
vector<int> w;
map<float,int> mpw;
vector<float> pw;

for(int i=0;i<n;i++)
{   cout<< "Enter weight for item "<<i+1<<" : ";
int t;
cin>>t;
w.push_back(t);
  //  cin>>w[i];
   // cout<<endl;
    cout<< "Enter Profit for item "<<i+1<<" : ";
    int t1;
cin>>t1;
p.push_back(t1);
   // cin>>p[i];
    //cout<<endl;
    float r=p[i]/w[i];
    pw.push_back(r);
    mpw[pw[i]]=i;
}

sorting(pw);
    


int k=n-1;
int tp=0;
while(c>0 && k>=0)
{   if(w[mpw[pw[k]]]<=c)
{   
   // cout<<pw[k];
    tp+=p[mpw[pw[k]]];
    c=c-w[mpw[pw[k]]];
}
else{
       tp+=pw[k]*c;
       //c=0;
    cout<<pw[k];

       break; 
}
k--;
}

cout<<endl;
cout<<"Ans :";
cout<<tp;
}



int main()
{
int t=0;
cin>> t;
while(t--)
{   
    solve();
}



}
