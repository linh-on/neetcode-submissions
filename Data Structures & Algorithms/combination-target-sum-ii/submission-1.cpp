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
        backtrack(nums, target - nums[i], i+1);

        // do not take nums[i]
        curr.pop_back();
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]){
            j++;
        }
        backtrack(nums, target, j);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return result;
        
    }
};
