class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,count=0;
        map<int,int> mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
                mpp[s[l]]--;
                l++;
            }
            count = count + l;
            r++;
        }
        return count;
    }
};