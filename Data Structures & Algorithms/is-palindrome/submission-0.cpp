class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (unsigned char c : s)
            if (isalnum(c)) t += tolower(c);

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < (int)t.size()) {
                if (t[l] != t[r]) return false;
                --l; ++r;
            }
            return true;
        };

        int n = t.size();
        return expand((n - 1) / 2, n / 2);
    }
};