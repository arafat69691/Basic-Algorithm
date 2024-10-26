/*
Author: Yeasin Arafat
Date:
Source:
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        s += ar[i];
    }
    int dif;
    cin>>dif;
    int dp[n + 1][s + 1];

    // initialize
    dp[0][0] = 1;
    for (int i = 1; i <= s; i++)
        dp[0][i] = 0;

    int different=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
           if(ar[i-1]<=j)
           {
                int op1 = dp[i-1][j-ar[i-1]];
                int op2 = dp[i-1][j];
                
                
           }
           else int op2 = dp[i-1][j];
        }
    }
   
}