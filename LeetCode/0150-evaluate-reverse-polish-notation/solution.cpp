class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        map<string, bool> ops;
        ops["+"] = true;
        ops["-"] = true;
        ops["*"] = true;
        ops["/"] = true;

        stack<int> nums;
        for (string s : tokens) {
            if (!ops[s]) {
                nums.push(stoi(s));
                continue;
            }

            int num1 = nums.top(); nums.pop();
            int num2 = nums.top(); nums.pop();
            int res = 0;
            if (s == "+") res = num2 + num1;
            if (s == "-") res = num2 - num1;
            if (s == "*") res = num2 * num1;
            if (s == "/") res = num2 / num1;
            
            nums.push(res);
        }

        return nums.top();
    }
};
