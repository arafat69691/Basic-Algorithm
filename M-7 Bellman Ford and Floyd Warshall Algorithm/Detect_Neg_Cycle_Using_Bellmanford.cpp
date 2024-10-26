/*
Author: Yeasin Arafat
Date: 9/28/2024
Source:
*/
#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u, v, w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<edge> edgeList;
    int dis[10005];
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(edge(u, v, w));
        // edgeList.push_back(edge(v,u,w)) // For undirected graph
    }
    for (int i = 0; i < n; i++)
    {
        dis[0] = INT_MAX;
    }
    dis[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (edge ed : edgeList)
        {
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            if (dis[u] < INT_MAX && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << endl;
    }
    return 0;
}