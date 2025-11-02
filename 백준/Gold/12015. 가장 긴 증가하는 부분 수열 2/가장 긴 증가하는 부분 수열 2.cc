#include <iostream>
#include <vector>
// #include <algorithm> // lower_bound를 직접 구현하므로 필요 없습니다.

int main() {
    // C++ 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> lis; // LIS 후보 배열

    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;

        // Case 1: lis가 비어있거나, 현재 숫자가 lis의 마지막 값보다 큰 경우
        if (lis.empty() || lis.back() < num) {
            lis.push_back(num);
        }
        // Case 2: 현재 숫자가 lis의 마지막 값보다 크지 않은 경우
        else {
            // ----- 여기가 std::lower_bound를 대체하는 이분탐색 -----
            
            int low = 0;
            // high를 lis.size()로 설정 (탐색 범위의 exclusive end)
            // 'else' 블록이므로 lis는 절대 비어있지 않습니다.
            int high = lis.size(); 

            // low와 high가 같아질 때까지 반복
            while (low < high) {
                // (low + high) / 2 보다 오버플로우에 안전
                int mid = low + (high - low) / 2; 

                if (lis[mid] < num) {
                    // lis[mid]가 num보다 작으면,
                    // 우리가 찾는 값(num 이상)은 mid보다 오른쪽에 있음
                    low = mid + 1;
                } else {
                    // lis[mid] >= num
                    // lis[mid]가 num 이상이면, 이 값이 '하한'일 수 있음
                    // (혹은 더 왼쪽에 있을 수도 있음)
                    // 따라서 high를 mid로 줄여서 왼쪽 범위를 더 탐색
                    high = mid;
                }
            }
            
            // loop가 끝나면 low(== high)는
            // num보다 크거나 같은 첫 번째 원소의 인덱스가 됩니다.
            lis[low] = num;
            // ------------------------------------------------
        }
    }

    // LIS 배열의 '길이'가 정답
    std::cout << lis.size() << "\n";

    return 0;
}