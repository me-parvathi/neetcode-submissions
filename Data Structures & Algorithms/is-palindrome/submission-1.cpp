class Solution {
public:
    bool isPalindrome(string s) {
        string t=""; 
        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c)))
                t += static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
        int n = t.size();
        int l = (n - 1) / 2, r = n / 2;
        while (l > -1 && r < n) {
            if (t[l] != t[r]) return false;
            l--; r++;
        }
        return true;
    }
};
