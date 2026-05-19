class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length()) {
        return false;
       }
       unordered_map<int,int>f1;
       for(int i : s){
            f1[i]++;
       }
       for(int j : t){
            f1[j]--;
       }
       for (auto it : f1){
        if(it.second == 0){
            return true;
        }
        else{
            return false;
        }
       }
    }
};
