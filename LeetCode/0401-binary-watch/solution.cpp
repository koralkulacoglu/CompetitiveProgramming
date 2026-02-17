class Solution {
    void getTime(int binary, vector<string>& res) {
        int hour = (binary & 0b1111000000) >> 6;
        int minute = binary & 0b111111;
        if (hour > 11 || minute > 59) return;
        string time = to_string(hour) + (minute < 10 ? ":0" : ":") + to_string(minute);
        res.push_back(time);
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int i=0; i<1024; i++) {
            if (__builtin_popcount(i) == turnedOn) getTime(i, res);
        }
        return res;
    }
};
