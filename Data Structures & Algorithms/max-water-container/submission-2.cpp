class Solution {
public:
    int maxArea(vector<int>& heights) {
        int begin = 0;
        int end = (int)heights.size()-1;
        // int left, right = heights[begin], heights[end]; 
        int result = (end-begin) *min(heights[begin],heights[end]);
        while (begin < end){
            if ((end-begin) *min(heights[begin],heights[end]) > result){
                result = (end-begin) * min(heights[begin],heights[end]);
            }
            if (heights[begin] < heights[end])
                begin++;
            else{
                end--;
            }
        }
        return result;
        
    }
};
