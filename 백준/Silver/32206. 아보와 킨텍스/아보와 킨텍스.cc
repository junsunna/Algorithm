#include <iostream>
using namespace std;

int main() {
    int N;
    char input[1000];
    cin >> N >> input;
    cout << (26 * (N + 1)) - (N);

    return 0;
}