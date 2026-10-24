class Solution {
    static constexpr array<int, 12> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int maa = stoi(arriveAlice.substr(0, 2));
        int daa = stoi(arriveAlice.substr(3, 2));
        int mal = stoi(leaveAlice.substr(0, 2));
        int dal = stoi(leaveAlice.substr(3, 2));
        int mba = stoi(arriveBob.substr(0, 2));
        int dba = stoi(arriveBob.substr(3, 2));
        int mbl = stoi(leaveBob.substr(0, 2));
        int dbl = stoi(leaveBob.substr(3, 2));
        int days = 0;
        auto inAlice = [&](int m, int d) {
            if (m < maa || m > mal) return false;
            if (m == maa && d < daa) return false;
            if (m == mal && d > dal) return false;
            return true;
        };
        auto inBob = [&](int m, int d) {
            if (m < mba || m > mbl) return false;
            if (m == mba && d < dba) return false;
            if (m == mbl && d > dbl) return false;
            return true;
        };
        for (int m=1; m<=12; m++) {
            for (int d=1; d<=months[m-1]; d++) {
                if (inAlice(m, d) && inBob(m, d)) days++;
            }
        }
        return days;
    }
};
