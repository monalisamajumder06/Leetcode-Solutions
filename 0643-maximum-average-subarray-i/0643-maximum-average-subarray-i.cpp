class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0  , r = k-1 , sum=0, maxsum=0;
        double maxaverage = 0;
        for(int i = 0 ; i<k ; i++){
            sum = sum + nums[i];
        }
        maxsum = sum;
        while ( r < nums.size()-1){
            r++;
            sum = sum + nums[r];
            while ( r-l+1 > k){
                sum = sum - nums[l];
                l++;
            }
            maxsum = max(maxsum , sum);
        }
        return maxaverage = (double)maxsum / k;
    }
};