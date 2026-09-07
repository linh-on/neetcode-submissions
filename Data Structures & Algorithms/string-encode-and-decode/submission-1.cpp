class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (string str : strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < int(s.size())){
            //find #
            int j = i;
            while (s[j] != '#') j++;
            int length = stoi(s.substr(i, j-i));
            result.push_back(s.substr(j+1, length));
            i = j+ 1+length;
        }    
        return result;
    }
};
