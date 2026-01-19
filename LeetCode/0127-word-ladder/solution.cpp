class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> words;
        for (string word : wordList) words[word] = true;

        unordered_map<string, bool> seen;

        auto getNeighs = [&](string word) {
            int m = word.size();
            vector<string> res;

            for (int i=0; i<m; i++) {
                string newWord = word;
                for (char c='a'; c<='z'; c++) {
                    newWord[i] = c;
                    if (seen[newWord] || !words[newWord]) continue;

                    res.push_back(newWord);
                    seen[newWord] = true;
                }
            }

            return res;
        };

        queue<pair<string, int>> que;
        que.push({beginWord, 1});
        seen[beginWord] = true;
        while (!que.empty()) {
            auto node = que.front();
            que.pop();

            string word = node.first;
            int cost = node.second;

            if (word == endWord) return cost;

            vector<string> neighs = getNeighs(word);
            for (string neigh : neighs) que.push({neigh, cost+1});
        }

        return 0;
    }
};
