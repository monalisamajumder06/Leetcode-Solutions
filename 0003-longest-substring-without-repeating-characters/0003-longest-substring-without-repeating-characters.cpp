class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r=0,maxlen=0;
        int hash[256] = {0};
        while (r<s.size()){
            hash[s[r]]++;
            while(hash[s[r]]>1){
                hash[s[l]]--;
                l++;
            }
            maxlen = max(maxlen , r-l+1);
            r++;
        }
        return maxlen;
    }
};