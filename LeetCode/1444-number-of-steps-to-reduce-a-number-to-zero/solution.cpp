class Solution {
public:
    int numberOfSteps(int num, int steps=0) {
        return num == 0 ? steps : numberOfSteps((num % 2 ? num - 1 : num / 2), steps + 1);
    }
};
