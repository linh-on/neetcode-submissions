class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (int num : nums){
            count[num]++;
        }
        vector<vector<int>> freqBucket(n+1);
        for (auto & [value, freq] : count){
            freqBucket[freq].push_back(value);
        }

        vector<int> result;
        for (int i = n; i >= 1; i--){
            for (int val : freqBucket[i]){
                result.push_back(val);
                if ((int)result.size() == k){
                    return result;
                }
            }
        }
        return result;

        
    }
};
