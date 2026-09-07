class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            int mid = (right+left)/2;
            if (target == nums[mid]){
                return mid;
            } else if (nums[mid] >= nums[right]){
                // left half is sorted
                if (nums[left] <= target && target < nums[mid]){
                    //in first half
                    right = mid-1;
                } else{
                    //in second half
                    left=mid+1;
                }
            } else{
                // right half is sorted
                if (nums[mid] < target && target <= nums[right]){
                    //in second half
                    left=mid+1;
                } else{
                    //in first half
                    right = mid-1;
                }
            }
        } 
        return -1;
                                              
        
    }
};
