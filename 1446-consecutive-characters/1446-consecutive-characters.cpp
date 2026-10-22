class Solution {
public:
    int maxPower(string s) {
        int r=0 , count = 1 , maxcount=1;
        while(r<s.size()-1){
            if (s[r] == s[r+1]){
                count = count + 1;
                maxcount =  max(maxcount , count);
            }
            else count = 1;
            r++;
        }
        return maxcount;
    }
};