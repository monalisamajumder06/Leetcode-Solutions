#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        // If n <= 3, changing 2 elements makes all remaining elements equal (score = 0)
        if (n <= 3) return 0;

        sort(nums.begin(), nums.end());

        // Case 1: Change the 2 smallest elements
        int option1 = nums[n - 1] - nums[2];
        
        // Case 2: Change the 2 largest elements
        int option2 = nums[n - 3] - nums[0];
        
        // Case 3: Change the 1 smallest and 1 largest element
        int option3 = nums[n - 2] - nums[1];

        return min({option1, option2, option3});
    }
};