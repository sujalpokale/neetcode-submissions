class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];

        for(int i =1;i<nums.size();i++){
            int curr = nums[i];

            int tempmax = max({curr,curr*maxprod,curr*minprod});
            int tempmin = min({curr,curr*maxprod,curr*minprod});

            maxprod = tempmax;
            minprod = tempmin;

            ans = max(ans,maxprod);
        }
        return ans;
    }
};
