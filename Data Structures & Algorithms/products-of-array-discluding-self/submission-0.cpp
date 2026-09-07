class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

  
        for (int pre = 1; pre < n; pre++){
            result[pre] *= result[pre-1] * nums[pre-1];
        }
        int suffix = 1;

        for (int post = n-1; post >= 0; post--){
            result[post] *= suffix;
            suffix *= nums[post];
        }
        return result;
    }

    
};
