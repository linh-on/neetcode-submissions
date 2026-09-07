class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> indexes;

        for (int i = 0; i <n; i++){
            while (!indexes.empty() && temperatures[i] > temperatures[indexes.top()]){
                int ind = indexes.top();
                indexes.pop();
        
                result[ind] = i-ind;
            }
            indexes.push(i);
            
        }
        return result;

        
    }
};
