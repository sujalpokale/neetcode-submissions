class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;
        int l = 0;
        int maxlen = 0;

        for(int r = 0;r<s.size();r++){

            while(ch.find(s[r]) != ch.end()){
                ch.erase(s[l]);
                l++;
            }

            ch.insert(s[r]);
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
