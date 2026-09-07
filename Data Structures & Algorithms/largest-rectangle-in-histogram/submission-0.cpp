class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> indexes;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++){
            int id = i;
            while (!indexes.empty() && heights[i] < indexes.top().second){
                id = indexes.top().first;
                maxArea = max(maxArea, indexes.top().second * (i - id));
                indexes.pop();
            }
            indexes.push(make_pair(id, heights[i]));
        }
        while (!indexes.empty()){
                int id = indexes.top().first;
                maxArea = max(maxArea, indexes.top().second * ((int)heights.size() - id));
                indexes.pop();
            }
        return maxArea;
        
    }
};
