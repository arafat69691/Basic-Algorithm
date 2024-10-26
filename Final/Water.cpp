#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++)
            {
                cin >> ar[i];
            }
        int m1 = -1;
        int m2 = -1;
        int l = -1;
        int  r = -1;

        for (int i = 0; i < n; i++)
        {
            if (ar[i] > m1)
            {
                m2 = m1;
                r = l;
                m1 = ar[i];
                l = i;
            }
            else if (ar[i] > m2)
            {
                m2 = ar[i];
                r = i;
            }
        }
        if (l > r)
            swap(l, r);

        cout << l << " " << r << endl;
    }

    return 0;
}
