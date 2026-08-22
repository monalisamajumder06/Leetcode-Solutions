// LeetHub test
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        vector<int> ans;
        for ( int i =0; i<nums.size(); i++){
            int count = 0;
            int temp = nums[i];
            while ( temp!=0){
                    temp = temp / 10 ;
                    count ++;
            }
            if ( count % 2 == 0){
                ans.push_back(nums[i]);
            }
        } 
        return ans.size();
            
    }
};