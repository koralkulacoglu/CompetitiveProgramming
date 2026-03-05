struct Trie {
    unordered_map<char, Trie*> mp;

    bool insert(string& word) {
        int n = word.size();
        Trie* cur = this;
        for (int i=0; i<n-1; i++) {
            if (cur->mp.find(word[i]) == cur->mp.end()) return false;
            cur = cur->mp[word[i]];
        }
        cur->mp[word[n-1]] = new Trie();
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        Trie trie;
        string best;
        for (string word : words) {
            if (trie.insert(word)) {
                if (word.size() == best.size() && word < best) best = word;
                else if (word.size() > best.size()) best = word;
            }
        }
        return best;
    }
};
