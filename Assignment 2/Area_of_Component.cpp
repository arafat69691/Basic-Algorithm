/*
 Author : YEASIN ARAFAT
 DATE : 
 SOURCE : 
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;

int r, c;
char a[N][N];
bool vis[N][N];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool Valid(int i, int j)
 {
    return i >= 0 && i < r && j >= 0 && j < c && a[i][j] == '.' && !vis[i][j];
}

int DFS(int si, int sj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({si, sj});
    vis[si][sj] = true;
    int area = 0;

    while (!pq.empty()) {
        pair<int, int> par = pq.top();
        pq.pop();
        int ci = par.first;
        int cj = par.second;
        area++;

        for (int i = 0; i < 4; i++) {
            int ni = ci + d[i].first;
            int nj = cj + d[i].second;
            if (Valid(ni, nj)) 
            {
                pq.push({ni, nj}); // Valid hole push kori
                // pq.push(ci,cj);
                vis[ni][nj] = true;
            }
        }
    }

    return area;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) 
        
        {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    priority_queue<int, vector<int>, greater<int>> pq;
    bool find = false;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                find = true;
                int area = DFS(i, j);
                pq.push(area);
            }
        }
    }

    if (find) {
        cout << pq.top() << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
