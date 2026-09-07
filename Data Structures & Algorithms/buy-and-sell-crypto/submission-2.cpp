class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, result = 0;
        while (r < (int)prices.size()){
            if (prices[r] < prices[l]){
                l = r;
            }
            else{
                result = max(prices[r] - prices[l], result);
            }
            r++;
        }
        return result;
    }
};
