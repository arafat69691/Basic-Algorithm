/*
Author: Yeasin Arafat
Date:
Source:
*/

#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int cnt;
bool Subset_Sum(int n , int ar[] , int sum)
{
    if(n==0)
    {
        if(sum==0) return true;
        else return false;
    }
    if(dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if(ar[n-1] <= sum)
    {
        bool op1 = Subset_Sum(n-1 , ar , sum - ar[n-1]);
        bool op2 = Subset_Sum(n-1 , ar , sum);
        return dp[n][sum]=op1 || op2;
    }
    else
    {
        bool op2 = Subset_Sum(n-1 , ar , sum-ar[n-1]);
        return dp[n][sum]= op2;
    }
}
int main (){
     int n;
     cin>>n;
     int ar[n];
     for(int i = 0 ; i<n ; i++)
     {
        cin>>ar[i];
     } 
     memset(dp,-1,sizeof(dp));
     int sum;
     cin>>sum;
    if( Subset_Sum(n ,ar,sum)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}