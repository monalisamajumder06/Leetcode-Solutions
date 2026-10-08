class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> st;
        int sum = 0;
        for(int i = 1; i<nums.size();i++){
            sum =  nums[i-1] + nums[i]; 
            if(st.find(sum)!=st.end()){
                return true;
        }
            st.insert(sum);
        }
        return false;
    }
};