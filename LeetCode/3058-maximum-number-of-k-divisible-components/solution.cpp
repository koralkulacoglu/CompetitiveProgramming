class Solution {
public:
    int n, k, ans;
    vector<int> vals;
    unordered_map<int, vector<int>> tree;

    // int dfs(int node, int parent) {
    //     vector<int> children = tree[node];
    //     int s = children.size();
    //     for (int i=0; i<s; i++) {
    //         if (children[i] == parent) {
    //             children.erase(children.begin() + i);
    //             s--;
    //             break;
    //         }
    //     }

    //     if (s == 0) {
    //         if (vals[node] % k == 0) {
    //             ans++;
    //             // cout << node << ' ' << 0 << endl;
    //             return 0;
    //         }
    //         // cout << node << ' ' << vals[node] << endl;
    //         return vals[node];
    //     }

    //     if (s == 1) {
    //         int childSum = dfs(children[0], node);
    //         if (childSum % k == 0) {
    //             if (childSum != 0) ans++;
    //             if (vals[node] % k == 0) {
    //                 ans++;
    //                 // cout << node << ' ' << 0 << endl;
    //                 return 0;
    //             }
    //             // cout << node << ' ' << vals[node] << endl;
    //             return vals[node];
    //         }

    //         int sum = childSum + vals[node];
    //         if (sum % k == 0) {
    //             ans++;
    //             // cout << node << ' ' << 0 << endl;
    //             return 0;
    //         }
    //         // cout << node << ' ' << sum << endl;
    //         return sum;
    //     }

    //     int leftSum = dfs(children[0], node);
    //     int rightSum = dfs(children[1], node);

    //     if (leftSum % k == 0 && rightSum % k == 0) {
    //         if (leftSum != 0) ans++;
    //         if (rightSum != 0) ans++;
    //         if (vals[node] % k == 0) {
    //             ans++;
    //             // cout << node << ' ' << 0 << endl;
    //             return 0;
    //         }
    //         // cout << node << ' ' << vals[node] << endl;
    //         return vals[node];
    //     }
    //     if (leftSum % k == 0) {
    //         if (leftSum != 0) ans++;
    //         int sum = rightSum + vals[node];
    //         if (sum % k == 0) {
    //             ans++;
    //             // cout << node << ' ' << 0 << endl;
    //             return 0;
    //         }
    //         // cout << node << ' ' << sum << endl;
    //         return sum;
    //     }
    //     if (rightSum % k == 0) {
    //         if (rightSum != 0) ans++;
    //         int sum = leftSum + vals[node];
    //         if (sum % k == 0) {
    //             ans++;
    //             // cout << node << ' ' << 0 << endl;
    //             return 0;
    //         }
    //         // cout << node << ' ' << sum << endl;
    //         return sum;
    //     }

    //     int sum = leftSum + rightSum + vals[node];
    //     if (sum % k == 0) {
    //         ans++;
    //         // cout << node << ' ' << 0 << endl;
    //         return 0;
    //     }
    //     // cout << node << ' ' << sum << endl;
    //     return sum;
    // }

    long long dfs(int node, int parent) {
        long long sum = vals[node];
        for (int child : tree[node]) {
            if (child == parent) continue;
            sum += dfs(child, node);
        }

        if (sum % k == 0) {
            ans++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n_, vector<vector<int>>& edges, vector<int>& values, int k_) {
        ans = 0;
        n = n_;
        k = k_;
        vals = values;
        tree.clear();

        for (vector<int>& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);

        return ans;
    }
};
