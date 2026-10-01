class Solution {
public:
    int atmost(vector <int> &nums , int k){
        int l=0,r=0,count=0;
        map <int, int> mpp;
        if (k<0) return 0;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if (mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};