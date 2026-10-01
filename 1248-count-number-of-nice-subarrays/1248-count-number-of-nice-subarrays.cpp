class Solution {
public:
    int atmost(vector <int> &nums , int k){
        if ( k<0) return 0;
        int l=0,r=0,sum=0,count=0;
        while(r<nums.size()){
            sum = sum + (nums[r]%2);
            while (sum>k){
                sum = sum - (nums[l]%2);
                l=l+1;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};