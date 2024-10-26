#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e3 + 5;
ll Infinity = 1e18 + 5;
ll dis[N];
class edge
{
public:
    int u, v;
    ll c;
    edge(int u, int v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};


int main()
{
    int n, e;
    cin >> n >> e;

    vector<edge> edgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(edge(u, v, c));
    }

    for (int i = 1; i <= n; i++)
        {
            dis[i] = Infinity;
        }

    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (edge ed : edgeList)
        {
            int u = ed.u;
            int v = ed.v;
            ll c = ed.c;
            if (dis[u] < Infinity && dis[u] + c < dis[v])
                dis[v] = dis[u] + c;
        }
    }
    bool cnt = false;
    int q;
    cin >> q;

    for (edge ed : edgeList)
    {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cnt = true;
            break;
        }
    }
    if (cnt)
        cout << "Negative Cycle Detected";
    else
    {
        while (q--)
        {
            int t;
            cin >> t;
            if (dis[t] == Infinity)
                cout << "Not Possible" << endl;
            else
                cout << dis[t] << endl;
        }
    }

    return 0;
}