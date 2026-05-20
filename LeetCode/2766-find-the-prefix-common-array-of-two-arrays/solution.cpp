class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> fA(n+1, false), fB(n+1, false);
        vector<int> pca(n);
        pca[0] = A[0] == B[0];
        fA[A[0]] = fB[B[0]] = true;
        for (int i=1; i<n; i++) {
            pca[i] = pca[i-1];
            pca[i] += (fA[B[i]] && !fB[B[i]]);
            fB[B[i]] = true;
            pca[i] += (fB[A[i]] && !fA[A[i]]);
            fA[A[i]] = true;
        }
        return pca;
    }
};
