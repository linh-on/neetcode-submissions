class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()){
            return false;
        }
        string keyS2(26, 0);
        string keyS1(26, 0);
        for (int i = 0; i < s1.size();i++){
            keyS1[s1[i] - 'a']++;
            keyS2[s2[i] - 'a']++;
        }
        int left = 0;
        int matches = 0;
        for (int i = 0; i < 26; i++){
            if (keyS1[i] == keyS2[i]){
                matches += 1;
            }
        }
        for (int i = s1.size(); i < s2.size(); i++){
            if (matches == 26) {
                return true;
            }
            int charIndex = s2[i] - 'a';
            keyS2[charIndex]++; //turn the freq to 1
            if (keyS2[charIndex] == keyS1[charIndex]){
                matches++;
            } else if (keyS2[charIndex] - 1 == keyS1[charIndex]){
                matches--;
            }

            int leftIndex = s2[left] - 'a';
            keyS2[leftIndex]--; //turn the freq to 0
            if (keyS2[leftIndex] == keyS1[leftIndex]){
                matches +=1;
            } else if (keyS2[leftIndex] + 1 == keyS1[leftIndex]){
                matches--;
            }
            left++;
                }
        if (matches == 26) {
                return true;
            }
        else {
            return false;
        }


        
        
    }
};
