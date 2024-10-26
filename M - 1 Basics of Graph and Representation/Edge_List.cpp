#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> v;   // Array er index e value thakbe pair
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));   // or -> v.push_back({a,b});

    }

    // Print Method
    // for(int i = 0; i<v.size() ; i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }

    // Print Method
    for(pair<int,int> p : v){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}