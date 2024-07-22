
#include <bits/stdc++.h>
using namespace std;
int partition(vector<pair<double,double>> &arr,int low,int high)
{
  
			//double pivot=(double)arr[high].first/arr[high].second;
		double p=arr[high].first;
		int i=low-1;
		//
		//	

  
  
  for(double j=low;j<=high-1;j++)
  {
      	//double a=(double)arr[j].first/arr[j].second;
        double a=(double)arr[j].first;
    if(a<=p)
    {
 
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

           
void quickSort(vector<pair<double,double>> &arr,int low,int high)
{
  if(low<high)
  {

    
    int pi=partition(arr,low,high);
    
  
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}



int main() {
   double p[] = {10, 5, 15, 7, 6, 18, 3}; // Profits
   // double p[] = {1,2, 3, 4, 5, 6, 7}; // Profits
   // double w[] = {2, 3, 5, 7, 1, 4, 1};   // Weights
   // double w[] = {16, 17, 18, 19, 20, 16, 17};   // Weights
      double w[] = {2, 3, 5, 7, 11, 4, 6};   // Weights
    double capacity = 15;
    int n=7;
    vector<pair<double, double>> v(n);

    for (int i = 0; i < 7; i++) {
        v[i].first=(double)p[i]/w[i];
        v[i].second=i;
        //v.push_back(make_pair(p[i], w[i]));
    }

    double ans = 0;
   // sort(v.begin(), v.end(), compare);.0
   quickSort(v,0,n-1);
   cout<<"Profit: ";
     for(int i=0;i<7;i++)
   {
   	cout<<p[i]<<" ";
   
   }
   cout<<endl;
      cout<<"Weight: ";
     for(int i=0;i<7;i++)
   {
   	cout<<w[i]<<" ";
   
   }
    cout<<endl;
     cout<<"Profit / Weight Ratio : ";
   
   for(int i=0;i<7;i++)
   {
   	cout<<(double)v[i].first<<" ";
   
   }
   cout<<endl;
    for (int i = v.size()-1; i >= 0; i--) {
    int p1=v[i].second;
        if (capacity >= w[p1]) {
            ans += p[p1];
            capacity -= w[p1];
          cout<<"Item selected : "<<v[i].second<<" ";
            //cout<<endl;
            cout<<"Remaining capacity : "<<capacity<<" ";
            cout<<endl;
        } else if(capacity!=0){
            //double fraction = (double)v[i].first / v[i].second;
            ans += capacity * v[i].first;
            cout<<"Item selected : "<<v[i].second<<" ";
            //cout<<endl;
            cout<<"Remaining capacity : "<<0<<" ";
            cout<<endl;
            break;
        }
    }
    cout <<"Max Profit : "<< ans << endl;

    return 0;
}























