class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e) {
            bool blocked = false;
            if (c == a) {
                if ((b < d && d < f) || (f < d && d < b))
                    blocked = true;
            }
            if (!blocked) return 1;
        }
        if (b == f) {
            bool blocked = false;
            if (d == b) {
                if ((a < c && c < e) || (e < c && c < a))
                    blocked = true;
            }
            if (!blocked) return 1;
        }

        if (abs(c - e) == abs(d - f)) {
            bool blocked = false;
            if (abs(c - a) == abs(d - b)) {
                if (( (c < a && a < e) || (e < a && a < c) ) &&
                    ( (d < b && b < f) || (f < b && b < d) ))
                    blocked = true;
            }
            if (!blocked) return 1;
        }

        return 2;
    }
};

