/*
Author: Yeasin Arafat
Date: 10-8-2024
Source: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W
*/

#include<bits/stdc++.h>
using namespace std;
bool knapsack(long long current,long long target)
{
    if(current==target) return true;
    if(current>target ) return false;

    return knapsack(current*10,target) || knapsack(current*20 ,target);
}

int main (){
     int t;
     cin>>t;
     while(t--)
     {
        long long int n;
        cin>>n;
        if(knapsack(1,n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

     }
    return 0;
}