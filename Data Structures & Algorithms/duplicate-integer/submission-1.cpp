class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums){
            if (numSet.find(num) == numSet.end()){ //cannot find the value
                numSet.insert(num);
            } else {
                return true;
            }
        }
        return false;
        
    }
};