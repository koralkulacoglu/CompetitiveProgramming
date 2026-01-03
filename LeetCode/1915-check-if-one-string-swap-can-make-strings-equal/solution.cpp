class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] != s2[i]) {
                for (int j=i+1; j<s2.size(); j++) {
                    if (s1[j] != s2[j]) {
                        if (s1[i] == s2[j] && s1[j] == s2[i]) {
                            for (int k=j+1; k<min(s1.size(), s2.size()); k++) {
                                if (s1[k] != s2[k]) {
                                    return s1 == s2;
                                }
                            }
                            return true;
                        }
                        return s1 == s2;
                    }
                }
                return s1 == s2;
            }
        }
        return s1 == s2;
    }
};
