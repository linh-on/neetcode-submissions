class Solution {
public:
    vector<vector<int>> result;
    vector<int> curr;

        
    void backtrack(vector<int> nums, int i){
        if (i == nums.size()){
            result.push_back(curr);
            return;
        }
        // take nums[i]
        curr.push_back(nums[i]);
        backtrack(nums, i+1);

        // dont take nums[i]
        curr.pop_back();
        backtrack(nums, i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
        
    }
};
