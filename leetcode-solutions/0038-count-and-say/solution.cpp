/*

1
11
21
1211
111221
312211
13112221

*/

vector<string> rle(31);

class Solution {
public:
    string extend(string s) {
        int n = s.size();
        string newS;

        int run = 0;
        char prev = ' ';
        for (char c : s) {
            if (prev == ' ' || c == prev) run++;
            else {
                newS += to_string(run);
                newS.push_back(prev);
                run = 1;
            }
            prev = c;
        }

        newS += to_string(run);
        newS.push_back(prev);

        return newS;
    }

    string countAndSay(int n) {
        if (rle[1].empty()) {
            rle[1] = "1";
            for (int i=2; i<=30; i++) rle[i] = extend(rle[i-1]);
        }

        return rle[n];
    }
};
