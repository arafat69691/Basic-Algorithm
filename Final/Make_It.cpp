#include <bits/stdc++.h>
using namespace std;

bool Make_it(int n) {
    if (n == 1) return true; // 1 hole thik

    if (n < 1) return false;

    if (n % 2 == 0) // 
    {
        return Make_it(n / 2);
    }

    
    return Make_it(n - 3); 
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        if (Make_it(n)) 
        {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
