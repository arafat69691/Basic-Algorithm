/*
Author: Yeasin Arafat
Date: 10-4-2024
Source: https://cses.fi/problemset/task/1666
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int group_size[N];
int parent[N];
int level[N];

void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        group_size[i] = 1;
        parent[i] = -1;
        level[i] = 0;
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
    if(leaderA == leaderB) return;
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
void dsu_union_by_rank(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);

    if (level[leaderA] > level[leaderB])
    {
        parent[leaderA] = leaderB;
    }
    else if (level[leaderB] > level[leaderA])
    {
        parent[leaderA] = leaderB;
    }
    else
    {
        parent[leaderA] = leaderB;
        level[leaderB]++;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union_by_size(a, b);
    }
    vector<int> leaders;

    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == -1)
        {
            leaders.push_back(i);
        }
    }
    cout << leaders.size() - 1 << endl;
    for (auto i = 1; i < leaders.size(); i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }
    return 0;
}