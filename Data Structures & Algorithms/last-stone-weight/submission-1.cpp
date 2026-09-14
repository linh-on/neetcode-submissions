class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int stone : stones){
            maxHeap.push(stone);
        }
        while (maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            int res = x > y ? x - y : y - x;
            if (res != 0){
                maxHeap.push(res);
            }
        }
        if (maxHeap.size() == 0){
            return 0;
        }
        return maxHeap.top();


        
    }
};
