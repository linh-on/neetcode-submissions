class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m*n;

        while (left < right){
            int mid = left + (right - left) / 2;
            int value = matrix[mid / n][mid % n];
            if (value == target){
                return true;
            } else if (value < target){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return false;
    }
};
