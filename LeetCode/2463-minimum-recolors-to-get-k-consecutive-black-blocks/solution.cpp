class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int b = 0;
        for (int i=0; i<k; i++) b += blocks[i] == 'B';

        int hB = b;
        for (int i=k; i<n; i++) {
            b -= blocks[i-k] == 'B';
            b += blocks[i] == 'B';
            hB = max(hB, b);
        }

        return k - hB;
    }
};
