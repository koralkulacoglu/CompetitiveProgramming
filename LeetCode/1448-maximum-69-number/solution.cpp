class Solution {
public:
    int maximum69Number (int num) {
        string sNum = to_string(num);
        int n = sNum.size();
        for (int i=0; i<n; i++) {
            if (sNum[i] == '9') continue;
            sNum[i] = '9';
            return stoi(sNum);
        }
        return num;
    }
};
