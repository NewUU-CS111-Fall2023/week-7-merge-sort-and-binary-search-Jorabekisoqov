#include <iostream>

using namespace std;

double recursivePow(double x, int n) {
    if (n == 0) {
        return 1.0; 
    }

    double half = recursivePow(x, n / 2);
    if (n % 2 == 0) {
        return half * half; 
    } else {
        return x * half * half; 
    }
}

int main() {
    double x;
    int n;
    cin >> x >> n;

    double result = recursivePow(x, n);
    cout << result << endl;

    return 0;
}
