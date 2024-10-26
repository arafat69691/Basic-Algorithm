#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visited[1005];
void BFS(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;

        

        if (par == des)
            cout << level;
        else cout<<"NO VALUE";
        for (int child : v[par])
        {
            if (visited[child] == false)
            {
                q.push({child, level + 1});
                visited[child] = true;
            }
        }
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(visited, false, sizeof(visited));
    BFS(src, 6);

    return 0;
}
/*
7 8
0 1
1 2
0 4
1 3
2 0
3 4
1 5
3 6
0
*/