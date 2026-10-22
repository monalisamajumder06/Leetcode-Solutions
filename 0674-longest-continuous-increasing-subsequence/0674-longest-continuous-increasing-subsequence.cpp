class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int r=0 , count = 1 , maxcount = 1;
        while(r<nums.size()-1){
            if(nums[r+1]>nums[r]){
                count = count + 1;
                maxcount = max(maxcount , count);
            }
            else count = 1;
            r++;
        }
        return maxcount;
    }
};