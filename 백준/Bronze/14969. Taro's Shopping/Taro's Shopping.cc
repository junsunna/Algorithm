#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        vector<int> v;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int a, b;
        int max = 0;
        bool result = false;
        for (int i = n - 1; i > 0; i--) {
            a = v[i];
            for (int j = i - 1; j >= 0; j--) {
                b = v[j];
                if (a + b <= m && max < a + b) {
                    max = a + b;
                    result = true;
                }
            }
        }
        if (!result) cout << "NONE" << '\n';
        else cout << max << '\n';
    }
    return 0;
}