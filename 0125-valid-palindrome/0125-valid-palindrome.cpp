class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right) {
            char a, b;

            while(left < s.size() && !(s[left] >= 'a' && s[left] <= 'z') && !(s[left] >= 'A' && s[left] <= 'Z') && !(s[left] >= '0' && s[left] <= '9')) left++;
            while(right >= 0 && !(s[right] >= 'a' && s[right] <= 'z') && !(s[right] >= 'A' && s[right] <= 'Z') && !(s[right] >= '0' && s[right] <= '9')) right--;
            if(left > right) break;

            a = (s[left] >= 'a' && s[left] <= 'z') ? s[left] : 'a' + s[left] - 'A';
            b = (s[right] >= 'a' && s[right] <= 'z') ? s[right] : 'a' + s[right] - 'A';

            if(a != b) return false;

            left++, right--;
        }

        return true;
    }
};