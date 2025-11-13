struct Compare {
    int dist(const pair<int, int>& a) const {
        return a.first * a.first + a.second * a.second;
    }

    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return dist(a) < dist(b);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (vector<int>& p : points) {
            pq.push({p[0], p[1]});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            pair<int, int> p = pq.top(); pq.pop();
            res.push_back({p.first, p.second});
        }

        return res;
    }
};
