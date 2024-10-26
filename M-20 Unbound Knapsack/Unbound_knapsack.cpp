/*
Author: Yeasin Arafat
Date:
Source:
*/

#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int Unbound_knapsack(int n, int w, int val[], int weight[])
{
    if (n == 0 || w == 0)
        return 0;
    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (weight[n - 1] <= w)
    {
        int ch1 = val[n - 1] + Unbound_knapsack(n, w - weight[n - 1], val, weight);
        int ch2 = Unbound_knapsack(n - 1, w, val, weight);
        return dp[n][w]= max(ch1, ch2);
    }
    else
    {
        return dp[n][w]= Unbound_knapsack(n - 1, w, val, weight);
    }
}
int main()
{
    int n, w;
    cin >> n >> w;
    int val[n], weight[w];
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cout<<Unbound_knapsack(n,w,val,weight);
    return 0;
}