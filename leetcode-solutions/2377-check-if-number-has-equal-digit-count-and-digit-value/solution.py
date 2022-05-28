'''
        vector<int> freq(10);
        string sNum = to_string(num);
        for (char &i : sNum) freq[i-'0']++;
        for (int i=0; i<sz(sNum); i++) {
            if (freq[i] != (sNum[i]-'0')) return false;
        }
        return true;
'''

class Solution:
    def digitCount(self, num: str) -> bool:
        freq = [0 for i in range(10)]
        sNum = str(num)
        for i in sNum:
            freq[int(i)] += 1
        for i in range(len(sNum)):
            if freq[i] != int(sNum[i]):
                return False
        return True
