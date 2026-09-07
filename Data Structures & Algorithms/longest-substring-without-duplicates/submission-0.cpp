class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, longest = 0;
        unordered_set<char> window;
        for (int r = 0; r < (int)s.size(); r++){
            while (window.count(s[r])){
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            longest = max(longest, r-l+1);
        }
        return longest;

        
    }
};
