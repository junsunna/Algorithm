#include <iostream>
using namespace std;

int main() {
    long long n;
    while (cin >> n) {
        bool arr[10] = { 0 };
        long long index = 1;
        while (true) {
            bool result = true;
            long long tmp = n * index;
            while (tmp > 0) {
                arr[tmp % 10] = true;
                tmp /= 10;
            }
            for (int i = 0; i < 10; i++) {
                if (!arr[i]) {
                    result = false;
                    break;
                }
            }
            if (result) break;
            index++;
        }
        cout << index << '\n';
    }
    return 0;
}