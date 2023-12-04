#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int expected = 1;
    int missingCount = 0;

    for (int i = 0; i < n; ++i) {
        while (arr[i] != expected) {
            missingCount++;
            if (missingCount == k) {
                return expected;
            }
            expected++;
        }
        expected++;
    }

    return arr[n - 1] + k - missingCount;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = findKthPositive(arr, k);
    cout << result << endl;

    return 0;
}


//O(n^2)