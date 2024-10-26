#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

bool CheckConnection(int src, int des) {
    for (int val : v[src]) {
        if (val == des) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    
    while(e--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    
    for (int i = 0; i < n; ++i) {
        v[i].push_back(i);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        if (CheckConnection(a, b)) {
            cout << "YES" << endl;
        } 
        else
         {
            cout << "NO" << endl;
        }

    }
    
    return 0;
}
