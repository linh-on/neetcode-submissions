class Solution {
public:
    int hoursEaten(vector<int> & piles, int num){
        int totalHour = 0;
        for (int pile : piles){
            totalHour += (pile + num - 1) / num;
        }
        return totalHour;

    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = 0;

        while (left <= right){
            int mid = (right + left) / 2;
            int hour = hoursEaten(piles, mid);
        
            if (hour <= h){
                right = mid-1;
                result = mid;
            } else{
                left = mid+1;

            }
        }
        return result;
        
    }
};
