#define fir first
#define sec second

class Solution {
public:
    string largestWordCount(vector<string>& msg, vector<string>& snd) {
        unordered_map<string, int> ans;
        int n = msg.size();
        for (int i=0; i<n; i++) {
            int cur = 1;
            int m = msg[i].size();
            for (int j=0; j<m; j++) {
                if (msg[i][j] == ' ') cur++;
            }
            ans[snd[i]] += cur;
        }
        int mx=0;
        string res="";
        for (auto i : ans) {
            if ((i.sec > mx) || (i.sec == mx && i.fir > res)) {
                res = i.fir;
                mx = i.sec;
            }
        }
        return res;
    }
};
