/*
 Author : YEASIN ARAFAT
 DATE : 10-2-2024
 SOURCE : https://cses.fi/problemset/task/1193/
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool isValid(int x, int y, int n, int m, vector<vector<char>>& labyrinth, vector<vector<bool>>& visited) {
    return (x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y]);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> labyrinth(n, vector<char>(m));
    Point start, end;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> level(n, vector<int>(m, -1));
    vector<vector<Point>> parent(n, vector<Point>(m, {-1, -1}));
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;
    level[start.x][start.y] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (isValid(nx, ny, n, m, labyrinth, visited)) {
                visited[nx][ny] = true;
                level[nx][ny] = level[p.x][p.y] + 1;
                parent[nx][ny] = p;
                q.push({nx, ny});
            }
        }
    }

    if (visited[end.x][end.y]) {
        cout << "YES" << endl;
        cout << level[end.x][end.y] << endl;
        string path;
        Point p = end;
        while (p.x != start.x || p.y != start.y) {
            Point par = parent[p.x][p.y];
            if (par.x == p.x - 1) path += 'D';
            if (par.x == p.x + 1) path += 'U';
            if (par.y == p.y - 1) path += 'R';
            if (par.y == p.y + 1) path += 'L';
            p = par;
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}