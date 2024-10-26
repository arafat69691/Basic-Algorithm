

#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[10005][10005];
bool vis[10005][10005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c) {
        return false;
    }
    if (a[x][y] == '.' || a[x][y] == 'B') {
        return true;
    }
    return false;
}


bool DFS(int x, int y) {
    if (a[x][y] == 'B') return true;
    vis[x][y] = true;

    for (auto dir : d) {
        int ci = x + dir.first;
        int cj = y + dir.second;
        
        if (valid(ci, cj) && vis[ci][cj] == false) {
            if (DFS(ci, cj)) return true;
        }
    }
    return false;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    bool jabe = false;

  
    for (int i = 0; i < r && jabe ==false; i++) {
        for (int j = 0; j < c && jabe==false; j++) {
            if (a[i][j] == 'A') {
                jabe = DFS(i, j);
            }
        }
    }

    
    if(jabe==true) cout<<"YES";
    else cout<<"NO";
    return 0;
}
