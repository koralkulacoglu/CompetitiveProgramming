class Solution {
public:
    bool check(map<char, int> &f1, map<char, int> &f2) {
        for (auto i : f2) {
            if (i.second > f1[i.first]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        map<char, int> freqS, freqT;
        for (char i : t) freqT[i]++;

        int bestStart = 0;
        int bestEnd = -1;
        int n = s.size();
        for (int i=0; i<n; i++) {
            freqS[s[i]]++;
            if (check(freqS, freqT)) {
                bestEnd = i;
                break;
            }
        }
        
        if (bestEnd == -1) return "";

        int j = 0;
        while (check(freqS, freqT)) {
            freqS[s[j]]--;
            j++;
        }
        j--;
        freqS[s[j]]++;
        bestStart = j;

        for (int i=bestEnd+1; i<n; i++) {
            freqS[s[i]]++;
            while (check(freqS, freqT)) {
                freqS[s[j]]--;
                j++;
            }
            j--;
            freqS[s[j]]++;
            if (i-j < bestEnd-bestStart) {
                bestStart = j;
                bestEnd = i;
            }
        }

        return s.substr(bestStart, bestEnd-bestStart+1);
    }
};
