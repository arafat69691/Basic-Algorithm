
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];
int level[1005];
int parent[1005];

void BFS(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty()) {
        int par = q.front();
        q.pop();

        for (int child : adj[par]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--) {
        int src, des;
        cin >> src >> des;

        memset(parent, -1, sizeof(parent));
        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));

        BFS(src);

        if (level[des] == -1) {
            cout << -1 << endl;
        } else {
            cout << level[des] << endl;
        }
    }

    return 0;
}
