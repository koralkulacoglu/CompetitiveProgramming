class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxVal = 0, minVal = INT_MAX;

        for (char d = '0'; d <= '9'; ++d) {
            string temp = s;
            for (char& c : temp)
                if (c == d) c = '9';
            maxVal = max(maxVal, stoi(temp));
        }

        for (char d = '0'; d <= '9'; ++d) {
            string temp = s;
            for (char& c : temp)
                if (c == d) c = '0';
            minVal = min(minVal, stoi(temp));
        }

        return maxVal - minVal;
    }
};
