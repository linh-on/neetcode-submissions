class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1, result = 0;
        while (right < prices.size()){
            if (prices[right] < prices[left]){
                left = right;
                right++;
            }
            else{
                result = max(prices[right] - prices[left], result);
                right++;
            }
        }
        return result;
    }
};
