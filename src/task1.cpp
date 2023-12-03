#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < n - 2; ++i) {
            int oddLength = min(n - i, 3);

            if (oddLength % 2 == 1) {
                vector<int> temp;

                for (int j = i; j < i + oddLength; ++j) {
                    temp.push_back(arr[j]);
                }

                sort(temp.begin(), temp.end());
                int median = temp[oddLength / 2];
                sum += median;

                auto it = find(arr.begin() + i, arr.end(), median);
                if (it != arr.end()) {
                    arr.erase(it);
                    ++cnt;
                }
            }
        }

        int remainingSum = 0;
        for (int i = 0; i < n - cnt; ++i) {
            remainingSum += arr[i];
        }

        cout << remainingSum << endl;
    }

    return 0;
}
