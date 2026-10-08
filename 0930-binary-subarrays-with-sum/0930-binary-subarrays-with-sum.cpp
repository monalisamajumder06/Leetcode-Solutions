class Solution {
public:
    int atmost(vector<int>&nums , int goal){
        if (goal<0) return 0;
        int l  = 0 , r = 0 , count = 0, sum = 0;
        while(r<nums.size()){
            sum = sum + nums[r];
            while (sum > goal){
                sum = sum - nums[l];
                l++;
            }
            count = count + r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal) - atmost(nums,goal-1);
    }
};