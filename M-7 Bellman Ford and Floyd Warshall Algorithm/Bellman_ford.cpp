// /*
// Author: Yeasin Arafat
// Date: 9/27/2024
// Source:
// */

// #include <bits/stdc++.h>
// using namespace std;
// class Edge
// {
// public:
//     int u, v, w;
//     Edge(int u, int v, int w)
//     {
//         this->u = u;
//         this->v = v;
//         this->w = w;
//     }
// };
// int dis[10005];
// int main()
// {
//     int node, edge;
//     cin >> node >> edge;
//     vector<Edge> edgeList;
//     while (edge--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edgeList.push_back(Edge(u, v, w));
//     }

//     for (int i = 0; i < node; i++)
//     {
//         dis[i] = INT_MAX;
//     }
//     int src;
//     cin >> src;
//     dis[src] = 0;
//     for (int i = 0; i < node - 1; i++)
//     {
//         for (Edge ed : edgeList)
//         {
//             int u = ed.u;
//             int v = ed.v;
//             int w = ed.w ;
//             if (dis[u] < INT_MAX && dis[u] + w < dis[v])
//             {
//                 dis[v] = dis[u] + w;
//             }
//         }
//     }
//    for(int i = 0 ; i<node ; i++)
//    {
//     cout<<i<<"->"<<dis[i]<<endl;
//    }
//     return 0;
// }
/*
Author: Yeasin Arafat
Date:
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
    int dis[10005];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<edge> edgeList;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(edge(u, v, w));
    }
   
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
     dis[0]=0;
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
    bool cycle = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (edge ed : edgeList)
        {
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            if (dis[u] < INT_MAX && dis[u] + w < dis[v])
            {
                cycle = true;
                dis[v] = dis[u] + w;
            }
        }
    }
    
   if(cycle) cout<<"Cycle found";
   else{
     for(int i = 0; i<n ; i++)
    {
        cout<<dis[i]<<endl;
    }
   }
    return 0;
}