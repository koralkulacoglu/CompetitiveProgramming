class WordDictionary {
    struct Trie {
        vector<Trie*> children{26, nullptr};
        bool isWord{false};
    };

    Trie* trie;
    string word;

public:
    WordDictionary() {
        trie = new Trie();
    }

    int idx(char c) {
        return c - 'a';
    }
    
    void addWord(string word) {
        Trie* cur = trie;
        for (char c : word) {
            if (cur->children[idx(c)] == nullptr) {
                cur->children[idx(c)] = new Trie();
            }
            cur = cur->children[idx(c)];
        }
        cur->isWord = true;
    }

    bool recSearch(int i, Trie* cur) {
        if (cur == nullptr) return false;
        if (i == word.size()) return cur->isWord;

        char c = word[i];

        if (c == '.') {
            for (char t='a'; t<='z'; t++) {
                if (recSearch(i + 1, cur->children[idx(t)])) {
                    return true;
                }
            }
        }
        else {
            if (recSearch(i + 1, cur->children[idx(c)])) {
                return true;
            }
        }

        return false;
    }
    
    bool search(string s) {
        word = s;
        return recSearch(0, trie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
