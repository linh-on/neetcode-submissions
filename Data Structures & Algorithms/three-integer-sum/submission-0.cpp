class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size(); i++){
            if (nums[i] > 0) break; 
            if (i > 0 && nums[i] == nums[i-1]) continue;

            //now you have teh firt value
            int begin = i+1;
            int end = nums.size()-1;
            while (begin < end){
                int threeSum = nums[i] + nums[begin] + nums[end];
                if (threeSum < 0){
                    begin++;
                } else if (threeSum > 0){
                    end--;
                } else {
                    result.push_back({nums[i], nums[begin], nums[end]});
                    begin++;
                    while (begin < end && nums[begin] == nums[begin-1]) begin++;
                }
            }
        }
        return result;
        
    }
};
