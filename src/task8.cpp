#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums, int n) {
    int expected_sum = n * (n + 1) / 2;  
    int actual_sum = 0;
    for (int num : nums) {
        actual_sum += num;  
    }

    int missing = expected_sum - actual_sum;
    return missing;
}

int main() {
    int n;
    std::cin >> n; 

    std::vector<int> nums(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> nums[i];  
    }

    int result = missingNumber(nums, n);
    for (int i = 0; i < result; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}


//Time complexity O(n)