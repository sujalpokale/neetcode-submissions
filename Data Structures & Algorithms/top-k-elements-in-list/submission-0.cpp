class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int i : nums){
            freq[i]++;
        }
       vector<pair<int,int>>arr;
       
       for(auto it: freq){
        arr.push_back({it.second,it.first});
       }

        sort(arr.rbegin(),arr.rend());

        vector<int> ans;

        for(auto i =0;i<k;i++){
            ans.push_back(arr[i].second);
        }    

        return ans;
    }
};
