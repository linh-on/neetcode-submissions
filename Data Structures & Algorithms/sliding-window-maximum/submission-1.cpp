class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> deck;  // store indexes

        int right = 0;

        while (right < nums.size()){
            //kick all numbers that is smaller than newcomer
            while (!deck.empty() && nums[deck.back()] < nums[right])
                deck.pop_back();
            
            deck.push_back(right);

            if (deck.front() <= right - k){
                deck.pop_front();
            }
            if (right >= k - 1)
                result.push_back(nums[deck.front()]);
            right++;

        }
        return result;


        
    }
};
