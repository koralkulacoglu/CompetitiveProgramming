class Solution {
public:
    int strStr(string haystack, string needle) {
        auto it = std::search(haystack.begin(), haystack.end(), std::boyer_moore_searcher(needle.begin(), needle.end()));
        if (it == haystack.end()) return -1;
        return (it - haystack.begin());
    }
};
