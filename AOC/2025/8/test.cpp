#include <bits/stdc++.h>
using namespace std;

// 

#define vi vector<int>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

struct DSU {
    vector<int> parents;
    int components;
    DSU(int n) : parents(n), components(n) { iota(all(parents), 0); }
    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }
    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            parents[rootY] = rootX;
            components--;
        }
    }
};

struct Edge {
    int u, v;
    double dist;
    bool operator<(const Edge& o) const { return dist < o.dist; }
};

double getDist(const vi& p1, const vi& p2) {
    long long dx = p1[0] - p2[0], dy = p1[1] - p2[1], dz = p1[2] - p2[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// THE STRATEGY YOU REQUESTED
bool isConnectedWithKEdges(int k, int n, const vector<Edge>& sortedEdges) {
    DSU dsu(n);
    // Only use the first k edges
    for (int i = 0; i < k; i++) {
        dsu.unite(sortedEdges[i].u, sortedEdges[i].v);
    }
    return dsu.components == 1;
}

void solve() {
    // 1. Setup Data
    ifstream inputFile("input.txt");
    vector<vi> a;
    string line;
    while (getline(inputFile, line)) { /* ... reading code ... */
        vi row; stringstream ss(line); string cell;
        while (getline(ss, cell, ',')) row.pb(stoi(cell));
        a.pb(row);
    }
    int n = sz(a);

    // 2. Generate and SORT edges (The bottleneck: O(N^2 log N))
    vector<Edge> edges;
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            edges.pb({i, j, getDist(a[i], a[j])});
    
    sort(all(edges)); 

    // 3. BINARY SEARCH for "Min # Connections"
    int low = n - 1; // Minimum edges needed for any graph of size n
    int high = sz(edges);
    int ans_index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isConnectedWithKEdges(mid, n, edges)) {
            ans_index = mid;
            high = mid - 1; // Try to use fewer edges
        } else {
            low = mid + 1;  // Need more edges
        }
    }

    // 4. Output Result
    // ans_index is the count (1-based), so the edge is at ans_index - 1
    Edge lastEdge = edges[ans_index - 1];
    
    cout << "Binary Search found minimum connections: " << ans_index << endl;
    cout << "Last Connection: " << lastEdge.u << " and " << lastEdge.v << endl;
    cout << "Answer: " << 1LL * a[lastEdge.u][0] * a[lastEdge.v][0] << endl;
}

int main() { solve(); return 0; }
