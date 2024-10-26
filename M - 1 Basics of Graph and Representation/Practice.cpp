// /*
//     Adjacency Matrix
// */

// #include<bits/stdc++.h>
// using namespace std;
// int main (){
//     int n,e;
//     cin>>n>>e;
//     int mat[n][n];
//     memset(mat,0,sizeof(mat));
//     while(e--){
//         int a,b;
//         cin>>a>>b;
//         mat[a][b] = 1;
//         mat[b][a] = 1;

//     }
//     for(int i=0; i<n ; i++){
//         for(int j = 0; j<n ; j++){
//             cout<<mat[i][j]<<" ";

//         }
//         cout<<endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main (){
//     int n,e;
//     cin>>n>>e;
//     int mat[n][n];
//     memset(mat,0,sizeof(mat));
//     while(e--){
//         int a,b;
//         cin>>a>>b;
//         mat[a][b]=1;
//     }
//      for(int i=0; i<n ; i++){
//         for(int j = 0; j<n ; j++){
//             cout<<mat[i][j]<<" ";

//         }
//         cout<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,e;
    cin>>n>>e;
    vector<int> ar[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);

    }
    for(int x : ar[0]){
        cout<<x<<" ";
    }
    return 0;
}