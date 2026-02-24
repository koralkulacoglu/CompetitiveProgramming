class Solution {
    int fact(int n) {
        int ans = 1;
        for (int i=2; i<=n; i++) ans *= i;
        return ans;
    }
    
public:
    bool isDigitorialPermutation(int n) {
        vector<int> freq(10, 0);
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += fact(digit);
            freq[digit]++;
            n /= 10;
        }

        while (sum) {
            int digit = sum % 10;
            freq[digit]--;
            sum /= 10;
        }

        for (int i : freq) {
            if (i != 0) return false;
        }

        return true;
    }
};
