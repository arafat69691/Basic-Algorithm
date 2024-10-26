
#include <bits/stdc++.h>
using namespace std;

int dp[1005][2005];
bool choclate(int n, int ar[],int sum)
{
    if (n == 0)
        return sum == 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (ar[n - 1] <= sum)
    {
        return dp[n][sum] = choclate(n - 1, ar, sum - ar[n - 1]) || choclate(n - 1, ar, sum);
    }
    else
    {
        return dp[n][sum] = choclate(n - 1, ar,sum);
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int ar[n];
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
            s += ar[i];
        }
        if (s % 2 != 0)
            cout << "NO" << endl;
        else
        {
            int sum = s / 2;
            memset(dp, -1, sizeof(dp));
            if (choclate(n,  ar,sum))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}