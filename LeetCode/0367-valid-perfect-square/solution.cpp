class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=0;
        for (; i*i<num; i++) {}
        return i * i == num;
    }
};
