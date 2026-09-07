class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int i = 0; 
        int n = (int)height.size()-1;
        int maxLeft = height[i];
        int maxRight = height[n];
        int result = 0;
        while (i < n) {
            if (maxLeft <= maxRight){
                i++;
                maxLeft = max(maxLeft, height[i]);
                result += maxLeft - height[i];
                

            } else{
                n--;
                maxRight = max(maxRight, height[n]);
                result += maxRight - height[n];

            }
        }
        return result;
        

    }
};
