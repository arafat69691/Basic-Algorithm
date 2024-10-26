#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> val = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


bool valid(int i, int j) {
    
    if (i < 0 || i >= r || j < 0 || j >= c) {
        return false;
    }
    
    if (a[i][j] == '.' && vis[i][j]==false) {
        return true;
    }
  
    return false;
}


int DFS(int i, int j) {
    vis[i][j] = true;
    int cnt = 1; 
    for (auto v : val) {
        int ci = i + v.first;
        int cj = j + v.second;
        if (valid(ci, cj)) {
            cnt = cnt+DFS(ci, cj);
        }
    }
    return cnt;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    vector<int> ap;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '.' && vis[i][j]==false) {
                int size = DFS(i, j);
                ap.push_back(size);
            }
        }
    }

    if (ap.empty())
     {
        cout << "0" << endl;
    }
     else
      {
        sort(ap.begin(), ap.end());
        for (int sz : ap) {
            cout << sz << " ";
        }
        cout << endl;
    }

    return 0;
}
