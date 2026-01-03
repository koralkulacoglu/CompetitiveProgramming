vector<int> t(int(4e6)+4, 0);
vector<int> lazy(int(4e6)+4, 0);

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -1e9;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> a(1e6+1, 0);
        for (int i=0; i<t.size(); i++) t[i] = 0;
        for (int i=0; i<lazy.size(); i++) lazy[i] = 0;
        for (vector<int> i : intervals) {
            update(1, 0, 1e6+1, i[0], i[1], 1);
        }
        int ans = query(1, 0, 1e6+1, 0, 1e6+1);
        
        return ans;
    }
};
