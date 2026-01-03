class Solution {
public:
    int secondHighest(string s) {
        int n=s.size(), num;
        set<int> dig;
        for (char &i : s) {
            num = i-'0';
            if (num >= 0 && num <= 9) {
                dig.insert(num);
            }
        }
        if (dig.size() <= 1) return -1;
        auto it = dig.end();
        it--; it--;
        return *it;
    }
};
