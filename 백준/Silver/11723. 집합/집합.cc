#include <iostream>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<21> S;
    string order;
    int M, x;

    cin >> M;
    while (M--) {
        cin >> order;

        if (order == "add") {
            cin >> x;
            S.set(x);  // x 위치를 1로 설정 (O(1))
        }
        else if (order == "remove") {
            cin >> x;
            S.reset(x);  // x 위치를 0으로 설정 (O(1))
        }
        else if (order == "check") {
            cin >> x;
            cout << S.test(x) << "\n";  // x 위치의 값 출력 (O(1))
        }
        else if (order == "toggle") {
            cin >> x;
            S.flip(x);  // x 위치를 반전 (O(1))
        }
        else if (order == "all") {
            S.set();  // 전체를 1로 설정 (O(1))
        }
        else if (order == "empty") {
            S.reset();  // 전체를 0으로 설정 (O(1))
        }
    }

    return 0;
}
