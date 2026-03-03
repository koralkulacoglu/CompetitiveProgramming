class Solution {
    vector<string> s;
    void fillS() {
        s.resize(21);
        s[1] = "0";
        for (int i=2; i<=20; i++) {
            s[i] = s[i-1] + "1";
            string sTemp = s[i-1];
            int m = sTemp.size();
            for (int j=0; j<m; j++) sTemp[j] = (sTemp[j] == '0' ? '1' : '0');
            reverse(sTemp.begin(), sTemp.end());
            s[i] += sTemp;
        }
    }
public:
    char findKthBit(int n, int k) {
        if (s.empty()) fillS();
        return s[n][k-1];
    }
};
