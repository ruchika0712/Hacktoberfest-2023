#include <iostream>
#include <vector>

using namespace std;

int kadaneAlgorithm(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        // Update the current sum by either extending the subarray or starting a new one
        currentSum = max(nums[i], currentSum + nums[i]);

        // Update the maximum sum encountered so far
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = kadaneAlgorithm(nums);
    
    cout << "Maximum subarray sum is: " << maxSum << endl;
    
    return 0;
}
