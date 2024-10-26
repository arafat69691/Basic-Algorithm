#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> val = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c) {
        return false;
    }
    if (a[x][y] == '.' && vis[x][y]==false) {
        return true;
    }
    return false;
}

void DFS(int x, int y) {
    vis[x][y] = true;
    for (auto v : val) {
        int ci = x + v.first;
        int cj = y + v.second;
        if (valid(ci, cj)) {
            DFS(ci, cj);
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int cnt = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '.' && vis[i][j]==false) {
                DFS(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
