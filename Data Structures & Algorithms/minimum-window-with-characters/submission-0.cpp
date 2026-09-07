class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()){return "";}

        unordered_map<char, int> countT, window;

        for (char c : t){
            countT[c]++;
        }
        int need = countT.size();
        int have = 0;

        int resStart = -1;
        int resLen = INT_MAX;

        int left = 0;

        for (int right = 0; right < s.size(); right++){
            window[s[right]]++;
            if (countT.count(s[right]) && countT[s[right]] == window[s[right]]){
                have++;

            }
            while (have == need){
                if (right - left + 1 < resLen){
                    resStart = left;
                    resLen = right - left + 1;
                }
                window[s[left]]--;
                if (countT.count(s[left]) && countT[s[left]] > window[s[left]]){
                    have--;
                }
                left++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);

        
        
    }
};
