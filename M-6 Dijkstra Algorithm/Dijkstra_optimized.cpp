/*
Author: Yeasin Arafat
Date: 9/26/2024
Source:
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> v[N];
int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void Dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int Node = parent.first;
        int Cost = parent.second;
        for (pair<int, int> child : v[Node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (Cost + childCost < dis[childNode])
            {
                dis[childNode] = Cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
   
    Dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << endl;
    }
    return 0;
}
/*
 priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({1,10});
    pq.push({0,5});
    pq.push({2,3});
    pq.push({3,8});
    pq.push({4,2});
    while(!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }

*/