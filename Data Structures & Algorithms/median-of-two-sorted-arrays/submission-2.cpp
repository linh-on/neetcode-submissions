class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        //we gonna work with the smaller size array
        int m = nums1.size();
        int n = nums2.size();
        int half = (m+n+1)/2;

        int lo = 0, hi = m;
        while (lo <= hi){
            int i = lo + (hi - lo) / 2; //amount to take from nums1
            int j = half - i; //amount to take from nums2

            int left1 = (i==0) ? INT_MIN : nums1[i-1];
            int right1 = (i==m) ? INT_MAX : nums1[i];

            int left2 = (j==0) ? INT_MIN : nums2[j-1];
            int right2 = (j==n) ? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1){
                if ((m+n) % 2 == 0){
                    //even number
                    return (max(left1, left2) + min(right1, right2)) /2.0;

                } else{
                    //odd number
                    return max(left1, left2);

                }
            }
            if (left1 > right2) hi = i - 1;   // took too many from nums1
            else lo = i + 1;

        }
        return 0.0;


        
    }
};
