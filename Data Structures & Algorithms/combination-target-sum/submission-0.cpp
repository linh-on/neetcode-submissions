class Solution {
private: 
    vector<vector<int>> result;
    vector<int> curr;

    void backtrack(vector<int> & nums, int target, int i){
        if (target == 0){
            result.push_back(curr);
            return;
        }
        if (i == nums.size() || nums[i] > target){
            return;
        }

        // take nums[i]
        curr.push_back(nums[i]);
        backtrack(nums, target - nums[i], i);

        // do not take nums[i]
        curr.pop_back();
        backtrack(nums, target, i+1);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0);
        return result;
    }
};
