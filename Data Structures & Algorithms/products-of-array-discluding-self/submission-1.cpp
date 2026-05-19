class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for(int i = 0;i<n;i++){
            int pro = 1;
            for(int j =0;j<n;j++){
                if(i != j){
                    pro *= nums[j];
                }
            }
            res[i] = pro;
        }
        return res;
    }
};
