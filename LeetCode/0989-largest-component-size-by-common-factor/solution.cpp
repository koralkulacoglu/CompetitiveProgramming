struct DSU {
	vector<int> parents, sizes;

	DSU(int n=2e5) : parents(n), sizes(n, 1) {
		for (int i=0; i<n; i++) parents[i] = i;
	}

	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;

		if (sizes[x_root] < sizes[y_root]) swap(x_root, y_root);
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;

		return true;
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};

class Solution {
    bool precomputed{false};
    vector<int> spf;

    void sieve(int n=1e5+1) {
        spf.resize(n);
        iota(spf.begin(), spf.end(), 0);
        for (int i=2; i<n; i++) {
            if (spf[i] == i) {
                for (int j=i*2; j<n; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        precomputed = true;
    }

public:
    int largestComponentSize(vector<int>& nums) {
        if (!precomputed) sieve();

        int n = nums.size();
        DSU dsu(1e5+1);

        for (int num : nums) {
            int prev = spf[num];
            while (num > 1) {
                num /= prev;
                int cur = spf[num];
                
                if (num > 1) dsu.unite(prev, cur);

                prev = cur;
            }
        }

        unordered_map<int, int> cnt;
        int ans = 0;
        for (int num : nums) {
            int root = dsu.find(spf[num]);
            ans = max(ans, ++cnt[root]);
        }

        return ans;
    }
};
