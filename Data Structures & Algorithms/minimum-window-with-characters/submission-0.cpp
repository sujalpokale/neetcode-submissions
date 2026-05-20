class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> countT;
        unordered_map<char,int> window;

        for(int ch : t){
            countT[ch]++;
        }

        int have =0;
        int need = countT.size();

        int l =0;
        int maxlen = INT_MAX;
        int start = 0;

        for(int r =0;r<s.size();r++){
            char c = s[r];

            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                have++;
            }

            while(have == need){
                
                if((r-l+1) < maxlen){
                    maxlen = r-l+1;
                    start = l;
                }
                window[s[l]]--;

                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }
        if(maxlen == INT_MAX){
            return  "";
        }
        return s.substr(start,maxlen);
    }
};
