class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end())) return 0;
        else if (s.size() == 2) return -1;
        int n = s.size();
        char l = s[0];
        char r = s[n-1];
        if (l <= *min_element(s.begin(), s.end())) return 1;
        if (r >= *max_element(s.begin(), s.end())) return 1;
        if (l >= *max_element(s.begin(), s.end()) && count(s.begin(), s.end(), l) == 1 && r <= *min_element(s.begin(), s.end()) && count(s.begin(), s.end(), r) == 1) return 3;
        return 2;
    }
};

