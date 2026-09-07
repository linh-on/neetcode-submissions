class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.size();

        while (begin < end){
            while (begin < end && !isalnum(s[begin])) begin++;
            while (begin < end && !isalnum(s[end])) end--;

            if (tolower(s[begin]) == tolower(s[end])){
                begin++; end--;
            } else{
                return false;

            }

        }
        return true;
        
    }
};
