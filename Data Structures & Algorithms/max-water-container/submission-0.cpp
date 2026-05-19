class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int maxval =0;

        while(l<r){
            int w = r - l;
            int h = min(heights[l],heights[r]);
            int area = w * h;
            
            maxval = max(maxval,area);
            
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxval;
    }
};
