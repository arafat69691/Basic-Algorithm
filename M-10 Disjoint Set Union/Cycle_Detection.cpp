/*
Author: Yeasin Arafat
Date: 10-3-2024
Source:
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int group_size[N];
int parent[N];
int level[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        group_size[i] = 1;
        parent[i] = -1;
        level[i]=0;
    }
}
int find(int node)
{
    if (parent[node] == -1)
        return node;

    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderA] += group_size[leaderB];
    }
}
void dsu_union_by_rank(int node1, int node2)
{
    int leaderA=find(node1);
    int leaderB = find(node2);

    if(level[leaderA]>level[leaderB])
    {
        parent[leaderA] = leaderB;
    }
    else if (level[leaderB]>level[leaderA])
    {
        parent[leaderA]=leaderB;
    }
    else
    {
        parent[leaderA]=leaderB;
        level[leaderB]++;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    bool cycle=false;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        int leaderA = find(a);
        int leaderB = find(b);

        if(leaderA==leaderB) cycle = true;

        else dsu_union_by_rank(a,b);
    }
    if(cycle) cout<<"Cycle found";
    else cout<<"Not cycle";
    return 0;
}