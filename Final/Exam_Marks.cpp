#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
bool marks(int n, int s, int ar[])
{
    if (n == 0)
       {
         return s == 0;

       }
    if (dp[n][s] != -1)
       {
         return dp[n][s];
       }
    if (ar[n - 1] <= s)
    {
        return dp[n][s] = marks(n - 1, s - ar[n - 1], ar) || marks(n - 1, s, ar);
    }
    else
    {
        return dp[n][s] = marks(n - 1, s, ar);
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        int ar[n];
        for (int i = 0; i < n; i++)
            cin >> ar[i];

        if (m == 1000)
            cout << "YES" << endl;
        else
        {
            int diffrent = 1000 - m;
            memset(dp, -1, sizeof(dp));
            if (marks(n, diffrent, ar))  cout << "YES" << endl;
               
            else cout << "NO" << endl;
                
        }
    }

    return 0;
}