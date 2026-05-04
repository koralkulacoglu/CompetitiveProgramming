class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> answer;
        for (int i=1; i<n-k; i++) answer.push_back(i);
        int l=n-k, r=n;
        for (int i=0; i<=k; i++) {
            if (i%2 == 0) answer.push_back(l++);
            else answer.push_back(r--);
        }
        return answer;
    }
};
