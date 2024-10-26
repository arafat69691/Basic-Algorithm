/*
Author: Yeasin Arafat
Date: 10-7-2024
Source:
*/

#include<bits/stdc++.h>
using namespace std;
int knapsack(int n , int weight[], int value[], int W)
{
    if(n<0 || W==0) return 0;
    if(weight[n] <= W)
    {
        // 2 ta option
        // 1 Nibo 2 nibo na
        int op1 = knapsack(n-1 , weight,value,W-weight[n])+value[n];
        int op2 = knapsack(n-1 , weight,value , W);
        return max(op1,op2);

    }
    else
    {
        // 1 ta option na niye dekhte hobe
        int op2 = knapsack(n-1,weight,value,W);
        return op2;
    }
}
int main (){
     int n;
     cin>>n;
     int weight[n],value[n];
     for(int i = 0; i<n ; i++)
     {
        cin>>weight[i];
     }
     for(int i = 0 ; i< n ; i++)
     {
        cin>>value[i];
     }
     int W;
     cin>>W;
     cout<<knapsack(n-1,weight,value,W);
    return 0;
}