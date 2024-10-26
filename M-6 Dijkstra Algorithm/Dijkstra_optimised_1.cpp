/*
Author: Yeasin Arafat
Date:
Source:
*/

#include<bits/stdc++.h>
using namespace std;

int node,edge;
const int N=1e5;
vector<pair<int,int>> adj[N];
long long int dis[N];

void dijkstra(int src)
{
    for(int i = 1 ; i<node ; i++)
    {
        dis[i]=INT_MAX;
    }

    dis[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dis[src],src});

    while(!pq.empty())
    {
        pair<int,int> parent= pq.top();
        pq.pop();
        int parentNode=parent.second;
        int parentCost=parent.first;
        for(auto child : adj[parentNode])
        {
            int childNode=child.second;
            int childCost=child.first;

            if(dis[parentNode]+childCost < dis[childNode])
            {
                dis[childNode]=dis[parentNode]+childCost;
                pq.push({dis[childNode],childNode});
            }
        }
    }

}
int main (){
        cin>>node>>edge;
        while(edge--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({w,v});
            adj[v].push_back({w,v});
        }
        int src;
        cin>>src;
        dijkstra(src);
        for(int i = 1 ; i<node ; i++)
        {
            cout<<dis[i]<<endl;
        }
    return 0;
}