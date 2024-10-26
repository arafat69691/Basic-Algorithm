#include<bits/stdc++.h>
using namespace std;
// class Pair{
// public:
//     int f,s;
//     void make_pair(int a ,int b){
//     f=a;
//     s=b;
//     }
// };
int main (){
    // Pair p;
    // p.make_pair(10,20);
    // cout<<p.f;

    // STL PAIR
    pair<string,int>p;
    p = make_pair("Yeasin",20);
    cout<<p.first<<" "<<p.second;
    return 0;
}