class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x%10;
            x /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        vector<int> a(n+1, 0);
        for (int i=1; i<=n; i++) a[digitSum(i)]++;

        int mx = *max_element(a.begin(), a.end());
        int ans = 0;
        for (int i : a) ans += i == mx;
        
        return ans; 
    }
};
