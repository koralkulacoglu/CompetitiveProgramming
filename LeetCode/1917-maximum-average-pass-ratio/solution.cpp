class Solution {
    static double gain(const pair<int, int>& p) {
        return (double(p.first + 1) / (p.second + 1)) - (double(p.first) / p.second);
    }

    struct Scorer {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return gain(a) < gain(b);
        }
    };

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Scorer> pq;

        for (vector<int> i : classes) pq.push({i[0], i[1]});

        while (extraStudents) {
            extraStudents--;
            pair<int, int> c = pq.top();
            pq.pop();
            pq.push({c.first+1, c.second+1});
        }

        int size = pq.size();
        double ans = 0;
        while (!pq.empty()) {
            pair<int, int> c = pq.top();
            pq.pop();
            ans += double(c.first) / c.second;
        }

        return ans / size;
    }
};
