#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 5;
ll Infinity = 1e18 + 5;

vector<pair<int, int>> v[N];

ll dis[N];

class compare
{
public:
    bool operator()(pair<int, ll> a, pair<int, ll> b)
    {
        return a.second > b.second;
    }
};
void Dijkstra(int src)
{
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, compare> pq;

    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<ll, ll> parent = pq.top();
        pq.pop();
        ll node = parent.first;
        ll cost = parent.second;

        for (pair<int, ll> child : v[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
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
    }

    for (int i = 1; i <= n; i++)
       {
         dis[i] = Infinity;
       }

    int src;
    cin >> src;
    Dijkstra(src);

    int q;
    cin >> q;
    while (q--)
    {
        int p, pt;
        cin >> p >> pt;

        if (dis[p] <= pt)
        
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}