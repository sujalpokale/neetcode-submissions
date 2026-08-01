class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length()){
        return false;
       }
       unordered_map<char,int>f1;
       for(int ch : s){
            f1[ch]++;
       }
       for(int ch : t){
            f1[ch]--;
       }
       for(auto it : f1){
            if(it.second != 0){
                return false;
            }
       }

       return true;
    }
};
