#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,e;
    cin>>n>>e;

    vector<int> matrix[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    // cout<<matrix[0].size(); // Index e edge er sonkha jante

    // To print value
    // for(int i = 0;i<matrix[0].size();i++){
    //     cout<<matrix[0][i];
    // }
    
    //To print value
    // for(int v : matrix[0]){
    //     cout<<v<<" ";
    // }

    for(int i = 0; i<matrix[0].size() ; i++){
        cout<<matrix[0][i];
    }
    return 0;
}