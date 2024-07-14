// #include<bits/stdc++.h>
// using namespace std;

// bool compare(pair<int,int> p1,pair<int,int> p2)
// {
//     double a=(double)p1.first/p1.second;
//     double b=(double)p2.first/p2.second;
//     return a>b;
// }

// int main() {
//    double p[]={10,5,15,7,6,18,3};
//     double w[]={2,3,5,7,1,4,1};
//     int capacity=15;
//     vector<pair<int,int>> v;
    
//     for(int i=0;i<7;i++)
//     {   pair<double, double> p1;
//          p1 = make_pair(p[i],w[i]) ;
//         v.push_back(p1);
        
//     }
//     int balance=0;
//     double ans=0;
//     sort(v.begin(),v.end(),compare);
//     for(int i=0;i<7;i++)
//     {
//         if(capacity>=v[i].second)
//         {
//             ans+=v[i].first;
//             capacity-=v[i].second;
//            // continue;
//         }
//         else if(capacity<v[i].second)
//         {   double t=(double)v[i].first/v[i].second;
//             ans+=capacity*t;
//             capacity=0;
//             break;
//         }
//     }
//     cout<<ans<<" ";

// }
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    double a = (double)p1.first / p1.second;
    double b = (double)p2.first / p2.second;
    return a > b;
}

int main() {
    int p[] = {10, 5, 15, 7, 6, 18, 3}; // Profits
    int w[] = {2, 3, 5, 7, 1, 4, 1};   // Weights
    int capacity = 15;
    vector<pair<int, int>> v;

    for (int i = 0; i < 7; i++) {
        v.push_back(make_pair(p[i], w[i]));
    }

    double ans = 0;
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < 7; i++) {
        if (capacity >= v[i].second) {
            ans += v[i].first;
            capacity -= v[i].second;
        } else {
            double fraction = (double)v[i].first / v[i].second;
            ans += capacity * fraction;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}

