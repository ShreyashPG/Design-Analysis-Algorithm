
#include <bits/stdc++.h>
using namespace std;


	void mySort(vector<pair<int,int> > &v)
	{
		for(int i=1;i<v.size();i++)
		{
			int j=i-1;
			double t=(double)v[i].first/v[i].second;
			pair<double,double> p1=v[i];
			while(j>=0)
			{
				double a=(double)v[j].first/v[j].second;
				if(a>t)
				{
				v[j+1]=v[j];
				}
			else{break;}
				j--;
			}
			v[j+1]=p1;
		}	
	}

int main() {
    //int p[] = {10, 5, 15, 7, 6, 18, 3}; // Profits
    int p[] = {1,2, 3, 4, 5, 6, 7}; // Profits
  //  int w[] = {2, 3, 5, 7, 1, 4, 1};   // Weights
  //  int w[] = {15, 15, 15, 15, 15, 15, 15};   // Weights
      int w[] = {2, 3, 5, 7, 1, 4, 1};   // Weights
    int capacity = 15;
    vector<pair<int, int>> v;

    for (int i = 0; i < 7; i++) {
        v.push_back(make_pair(p[i], w[i]));
    }

    double ans = 0;
   // sort(v.begin(), v.end(), compare);
   mySort(v);
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
   	cout<<(double)v[i].first/v[i].second<<" ";
   
   }
   cout<<endl;
    for (int i = v.size()-1; i >= 0; i--) {
        if (capacity >= v[i].second) {
            ans += v[i].first;
            capacity -= v[i].second;
        } else {
            double fraction = (double)v[i].first / v[i].second;
            ans += capacity * fraction;
            break;
        }
    }
    cout <<"Max Profit : "<< ans << endl;

    return 0;
}
