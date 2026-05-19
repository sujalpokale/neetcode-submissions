class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for(char ch : s){
            if(isalnum(ch)){
                temp += tolower(ch);
            }
        }
        int l = 0;
        int r = temp.size() - 1;

        while(l<r){
            if(temp[l] != temp[r]){
                return false;
            }
            l++;
            r--;
    }
    return true;
    }
};
