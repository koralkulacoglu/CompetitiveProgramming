struct DSU {
	vector<int> parents, sizes;

	DSU(int n=1e4+1) : parents(n), sizes(n, 1) {
		for (int i=0; i<n; i++) parents[i] = i;
	}

	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;

		if (x_root < y_root) swap(x_root, y_root);
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;

		return true;
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};

class SummaryRanges {
    DSU dsu;
    unordered_map<int, bool> seen;
public:
    void addNum(int value) {
        if (seen[value]) return;
        seen[value] = true;
        if (seen[value-1]) dsu.unite(value, value-1);
        if (seen[value+1]) dsu.unite(value, value+1);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int left = 0;
        while (left <= 1e4) {
            if (seen[left]) {
                int right = dsu.find(left);
                res.push_back({left, right});
                left = right+1;
            }
            else left++;
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
