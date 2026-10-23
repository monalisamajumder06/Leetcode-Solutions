class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = ((n*(n+1))/2), actual = 0;
        for ( int r = 0 ; r<nums.size() ; r++){
            actual = actual + nums[r];
        }
        return expected - actual;
    }
};