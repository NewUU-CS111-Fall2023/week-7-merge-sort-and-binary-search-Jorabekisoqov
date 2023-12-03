#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }

    long long initial_beautifulness = 0;
    for (int i = 0; i < n; ++i) {
        initial_beautifulness += abs(permutation[i] - (i + 1));
    }

    long long max_beautifulness = initial_beautifulness;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {

            swap(permutation[i], permutation[j]);

            long long current_beautifulness = 0;
            for (int k = 0; k < n; ++k) {
                current_beautifulness += abs(permutation[k] - (k + 1));
            }

            max_beautifulness = max(max_beautifulness, current_beautifulness);

            swap(permutation[i], permutation[j]);
        }
    }

    cout << max_beautifulness << endl;

    return 0;
}



// O(n^3)