class Solution {
public:
    int maxVowels(string s, int k) {
        int l=0, r=0, vcount=0,maxcount=0;
        while(r<s.size()){
            if(s[r]=='a' || s[r]=='e'|| s[r]=='i' || s[r]=='o' || s[r]=='u'){
                vcount = vcount+1;
            }
            while(r-l+1>k){
                if(s[l]=='a' || s[l]=='e'|| s[l]=='i' || s[l]=='o' || s[l]=='u'){
                    vcount--;
                }
                l++;
            }
            maxcount = max(maxcount , vcount);
            r++;
        }
        return maxcount;
    }
};