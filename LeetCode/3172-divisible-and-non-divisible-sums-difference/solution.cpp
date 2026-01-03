class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long num1=0, num2=0;
        for (int i=1; i<=n; i++) num1 += (i%m ? i : 0);
        for (int i=1; i<=n; i++) num2 += (i%m ? 0 : i);
        return num1 - num2;
    }
};
