#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> v[N];
bool vis[N];
int parentArray[N];

bool DFS(int src) {
    vis[src] = true;

    for(int child : v[src]) {
        if(vis[child] && parentArray[src] != child) {
            return true;
        }
        if(!vis[child]) {
            parentArray[child] = src;
            if(DFS(child)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    bool ans = false;
    while(e--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        // v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            if(DFS(i)) {
                ans = true;
                break;
            }
        }
    }
    cout << (ans ? "true" : "false") << endl;
    return 0;
}
