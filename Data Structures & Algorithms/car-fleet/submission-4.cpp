class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> timeStack;
        vector<pair<int, int>> carPairs;

        for (int i = 0; i < position.size(); i++){
            carPairs.push_back(make_pair(position[i], speed[i]));
        }
        sort(carPairs.begin(), carPairs.end(), greater<pair<int, int> >());

        for (const auto & [pos, spd] : carPairs){
            double time = (double) (target - pos) / spd;
            if (timeStack.empty()){
                timeStack.push(time);
            } else if (time > timeStack.top()){
                timeStack.push(time);
            }
            

        }

        return timeStack.size();
        
    }
};
