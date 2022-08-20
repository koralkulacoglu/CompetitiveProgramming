int t[int(2e5)+1];

void build() {
    for (int i=0; i<=2e5; i++) t[i] = 0;
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        
        build();
        for (vector<int>  i : shifts) {
            int left = i[0];
            int right = i[1];
            int add = i[2]?1:-1;
            update(1, 0, n-1, left, right, add);
        }
        for (int i=0; i<n; i++) {
            int dt = get(1, 0, n-1, i);
            
            int val = s[i]-'a';
            val += dt;
            val %= 26;
            if (val < 0) {
                int rem = -val % 26;
                val = 26 - rem;
            }
            s[i] = 'a'+val;
        }
        return s;
    }
};
