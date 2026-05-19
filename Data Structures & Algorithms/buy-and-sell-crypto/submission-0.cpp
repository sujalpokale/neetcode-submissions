class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minval = prices[0];
        int maxval = 0;

        for(int i =1;i<n;i++){  
            int profit = prices[i] - minval;

            maxval = max(maxval , profit);
            minval = min(minval, prices[i]);

        }
        return maxval;
    }
};
