class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int r = 0 , count = 0, maxcount = 0;
        while(r<nums.size()){
            if(nums[r]==1){
                count = count + 1;
                maxcount = max(maxcount,count);
            }
            else count = 0;
            r++;
        }
        return maxcount;
    }
};