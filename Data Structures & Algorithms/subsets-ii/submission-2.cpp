class Solution {
private:
    vector<vector<int>> result;
    vector<int> curr;

        
    void backtrack(vector<int>& nums, int i){
        if (i == nums.size()){
            result.push_back(curr);
            return;
        }
        // take nums[i]
        curr.push_back(nums[i]);
        backtrack(nums, i+1);

        // dont take nums[i]

        curr.pop_back();
        
        int j = i+1;
        while (j < nums.size() && nums[i] == nums[j]){
            j++;
        }
        backtrack(nums, j);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
        
    }
};
