class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        
        vector<bool> toDel(n, false);
        unordered_map<char, vector<int>> charIdx;
        for (int i=0; i<n; i++) {
            if (s[i] != '*') {
                charIdx[s[i]].push_back(i);
                continue;
            }

            toDel[i] = true;
            for (char c='a'; c<='z'; c++) {
                if (charIdx[c].empty()) continue;
                toDel[charIdx[c].back()] = true;
                charIdx[c].pop_back();
                break;
            }
        }

        string newS;
        for (int i=0; i<n; i++) {
            if (toDel[i]) continue;
            newS.push_back(s[i]);
        }

        return newS;
    }
};
