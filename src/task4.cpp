#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            minHeap.push(matrix[i][j]);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    return minHeap.top();
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = kthSmallest(matrix, k);
    cout << result << endl;

    return 0;
}
