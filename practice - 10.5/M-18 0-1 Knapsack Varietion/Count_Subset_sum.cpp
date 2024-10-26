/*
Author: Yeasin Arafat
Date: 10 - 10 -2024
Source:
*/

#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int Subset_top_down(int n , int ar[] , int sum)

{
    if(n==0)
    {
        if(sum==0) return 1;
        else return 0;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    if(ar[n-1] <= sum)
    {
        int op1 = Subset_top_down(n-1 , ar , sum - ar[n-1]);
        int op2 = Subset_top_down(n-1,ar,sum);
        return dp[n][sum] = op1+op2;
    }
    else
    {
        int op2 = Subset_top_down(n-1,ar,sum);
        return dp[n][sum]= op2;
    }
}
int main (){
    int n ;
    cin>>n;
    int ar[n];
    for(int i = 0 ; i<n ; i++)
    {
        cin>>ar[i];
    }  
    int sum;
    cin>>sum;
    memset(dp,-1,sizeof(dp));
   dp[0][0] = 1;
   for(int  i = 1; i<=sum ; i++)
   {
        dp[0][i]=0;
   }
   for (int i = 1 ; i<=n ; i++)
   {
        for(int j = 0 ; j<=sum ; j++)
        {
            if(ar[i-1] <= j)
            {
                int op1 = dp[i-1][j-ar[i-1]];
                int op2 = dp[i-1][j];
                dp[i][j] = op1 + op2;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
   }
   for( int i = 0 ; i<= n ; i++)
   {
        for(int j = 0 ; j<=sum ; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
   }
    return 0;
}