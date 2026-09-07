class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string & word : strs){
            array<int, 26> count{};
            for (char c : word){
                count[c - 'a']++;
            }
            string key;
            for (int n : count) {
                key += to_string(n) + "#";
            }
            groups[key].push_back(word);
        }
        vector<vector<string>> result;
        for (auto & [key, group] : groups){
            result.push_back(move(group));
        }
        return result;
    }
};
