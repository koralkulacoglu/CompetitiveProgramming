const int MAXN = 4e4+5;
const int MAXVAL = 1e9+1; // Max possible value in array (or after coordinate compression)
int K;

// Node structure for the persistent segment tree
struct Node {
    int left, right, count;
    long long sum;
};

Node nodes[MAXN * 35]; // Pool for nodes, size is N * log(MAXVAL)
int root[MAXN]; // Root of the segment tree for each prefix
int nodeCount;
vector<int> arr;

// Update function to insert a value into the tree
// Prev_node is the root of the previous version, cur_node is the new root
int update(int prev_node, int start, int end, int val) {
    int new_node = ++nodeCount;
    nodes[new_node].left = nodes[prev_node].left;
    nodes[new_node].right = nodes[prev_node].right;

    if (start == end) {
        nodes[new_node].count = nodes[prev_node].count + 1;
        nodes[new_node].sum = nodes[prev_node].sum + val;
        return new_node;
    }

    int mid = start + (end - start) / 2;
    if (val <= mid) {
        nodes[new_node].left = update(nodes[prev_node].left, start, mid, val);
    } else {
        nodes[new_node].right = update(nodes[prev_node].right, mid + 1, end, val);
    }
    
    nodes[new_node].count = nodes[nodes[new_node].left].count + nodes[nodes[new_node].right].count;
    nodes[new_node].sum = nodes[nodes[new_node].left].sum + nodes[nodes[new_node].right].sum;
    
    return new_node;
}

// Query function to find the k-th smallest element
// Root_l is the root of T[l-1], Root_r is the root of T[r]
int query(int root_l, int root_r, int start, int end, int k) {
    if (start == end) return start;

    int mid = (start + end) / 2;
    // Count of elements in the left child for the range [l, r]
    int left_count = nodes[nodes[root_r].left].count - nodes[nodes[root_l].left].count;

    if (k <= left_count) {
        return query(nodes[root_l].left, nodes[root_r].left, start, mid, k);
    } else {
        // Adjust k for the right child
        return query(nodes[root_l].right, nodes[root_r].right, mid + 1, end, k - left_count);
    }
}

pair<long long, int> query2(int root_l, int root_r, int start, int end, int limit) {
    if (start > limit) return {0, 0};

    if (end <= limit) {
        return {
            nodes[root_r].sum - nodes[root_l].sum,
            nodes[root_r].count - nodes[root_l].count
        };
    }

    int mid = start + (end - start) / 2;

    pair<long long, int> left = query2(nodes[root_l].left, nodes[root_r].left, start, mid, limit);
    pair<long long, int> right = query2(nodes[root_l].right, nodes[root_r].right, mid+1, end, limit);

    return {left.first + right.first, left.second + right.second};
}

// Function to find the range median
int findRangeMedian(int l, int r) {
    int k = (r - l + 1 + 1) / 2; // k-th element (1-based index)
    return query(root[l - 1], root[r], 1, MAXVAL, k);
}

template<class T> struct Seg { // comb(ID,b) = b
	const T ID = {0, true};
    T comb(T a, T b) {
        if (a == ID) return b;
        if (b == ID) return a;
        
        if (!a.second || !b.second || (a.first - b.first) % K != 0) return {0, false};
        return {b.first, true};
    }
    
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// min on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};


// idea: range median query using segtree
// another segtree to determine if every value in range is kx away from one another

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        nodeCount = 0;
        root[0] = 0;
        K = k;
        int n = nums.size();

        Seg<pair<int, bool>> st; // random item in range, boolean indicating if possible
        st.init(n);
        for (int i = 0; i < n; ++i) {
            root[i+1] = update(root[i], 1, MAXVAL, nums[i]);
    		st.upd(i, {nums[i], true});
        }

        vector<long long> ans;
        for (vector<int>& q : queries) {
            int l = q[0];
            int r = q[1];
            bool possible = st.query(l, r).second;
            if (!possible) {
                ans.push_back(-1);
                continue;
            }
            
            int median = findRangeMedian(l+1, r+1);

            pair<long long, int> small = query2(root[l], root[r+1], 1, MAXVAL, median);
            pair<long long, int> total = query2(root[l], root[r+1], 1, MAXVAL, MAXVAL);

            long long sumSmall = small.first;
            long long countSmall = small.second;

            long long sumLarge = total.first - small.first;
            long long countLarge = total.second - small.second;

            long long ops = (countSmall * median - sumSmall) + (sumLarge - countLarge * median);
            long long kOps = ops / k;

            ans.push_back(kOps);
        }

        return ans;
    }
};
