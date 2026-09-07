class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> count;
        int result = 0;
        int left = 0;
        int maxf = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            count[c] = 0;
        }
        for (int right = 0; right < s.size(); right++){
            count[s[right]] = count[s[right]] + 1;
            //get the max frequency
            maxf = max(maxf, count[s[right]]);

            if (right - left + 1 > maxf + k){
                count[s[left]]--;
                left += 1;
            } else {
                
            result = max(result, right - left + 1);

            }

        }
        return result;
        
    }
};
