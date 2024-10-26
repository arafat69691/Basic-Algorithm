#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m;
char a[N][N];

bool visited[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int valid(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m || a[r][c] == '-')
        return false;
    return true;
}
void DFS(int r, int c)
{
    visited[r][c] = true;

    for (int i = 0; i < 4; i++)
    {

        int childRow = r + d[i].first;
        int childCol = c + d[i].second;

        if (valid(childRow, childCol) && !visited[childRow][childCol])
            DFS(childRow, childCol);
    }
}
int main()
{
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)

            cin >> a[i][j];
    }

    int ai, aj, si, sj;
    cin >> ai >> aj >> si >> sj;

    DFS(ai, aj);
    if (visited[si][sj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}