class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxlen=0;
        map<int,int> mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++; 
        }
        return maxlen;
    }
};