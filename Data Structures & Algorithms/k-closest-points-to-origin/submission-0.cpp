class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (vector<int> point : points){
            int x1 = point[0], y1 = point[1];
            int distance = x1 * x1 + y1 * y1;
            maxHeap.push({distance, {x1, y1}});
            if (maxHeap.size() > k){
                maxHeap.pop();
            }
            
        }
        vector<vector<int>> res;
        while (maxHeap.size() > 0){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();

        }
        return res;

        
        
    }
};
