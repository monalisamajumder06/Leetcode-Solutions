class Solution {
public:
    string minWindow(string s, string t) {

        int minlen = 1e9;
        int l = 0, r = 0;
        int sindex = -1, count = 0;
        int m = t.size();

        int hash[256] = {0};

        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }

        while(r < s.size()){

            if(hash[s[r]] > 0){
                count++;
            }

            hash[s[r]]--;

            while(count == m){

                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sindex = l;
                }

                hash[s[l]]++;

                if(hash[s[l]] > 0)
                    count--;

                l++;
            }

            r++;
        }

        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};