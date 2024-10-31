class Solution {
public:
    int sx, sy, t;
    map<pair<int, int>, bool> seen;
    bool recur(int x, int y) {
        if (x == t || y == t || x+y == t) return true;

        if (seen[{x, y}]) return false;
        seen[{x, y}] = true;

        if (recur(x, sy)) return true;
        if (recur(sx, y)) return true;
        if (recur(0, y)) return true;
        if (recur(x, 0)) return true;
        if (recur(min(x+y, sx), y - min(x+y, sx))) return true;
        if (recur(x - min(x+y, sy), min(x+y, sy))) return true;
        return false;
    }

    bool canMeasureWater(int x, int y, int target) {
        sx = x;
        sy = y;
        t = target;
        seen.clear();
        return recur(0, 0);
    }
};
