class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix = 0;
        int subarray = 0;
        for (int i = 0; i < nums.size(); i++){
            prefix = prefix + nums[i];
            int needed = prefix - k;
            if ( mp.find(needed) != mp.end()){
                subarray = subarray + mp[needed];
               
            }
             mp[prefix]++;
        }
    return subarray;
    }
};