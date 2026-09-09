class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i;
        for ( i = 0 ; i<n+1 ; i++){
            bool found = false;
            for ( int j=0; j<nums.size(); j++){
                if ( i == nums[j]){
                    found = true;
                }
                }
            if (!found){
                return i;
            }
        }
        return -1;
        }
};