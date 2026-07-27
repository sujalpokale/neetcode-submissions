class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    void solve(int index,vector<int> & nums,int target){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        
        if(index == nums.size()){
            return;
        }

        if(nums[index] <= target){
            current.push_back(nums[index]);

            solve(index,nums,target - nums[index]);

            current.pop_back();
        }
        solve(index + 1,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(0,nums,target);

        return ans;
    }
};
