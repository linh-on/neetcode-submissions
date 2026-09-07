class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int result = 0;
        for (int num : nums){
            if (numSet.count(num-1)) continue; //if there is a number smaller than this by 1, skip
            else{
                int length = 0;
                while (numSet.count(num+length)) length++;
                if (result < length) {
                    result = length;
                }
            }
        }
        return result;

        
    }
};
