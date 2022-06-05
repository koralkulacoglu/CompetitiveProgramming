class TextEditor {
    int idx;
    string words;
    
    public:
    TextEditor() {
        idx = 0;
        words = "";
    }
    
    void addText(string text) {
        words.insert(idx, text);
        idx += text.size();
    }
    
    int deleteText(int k) {
        int ans = 0;
        while (idx != 0 && ans < k) {
            words.erase(idx-1, 1);
            --idx;
            ++ans;
        }
        // cout << "delet" << endl;
        return ans;
    }
    
    string cursorLeft(int k) {
        idx = max(0, idx-k);
        return words.substr(max(0, idx-min(10, idx)), min(10, idx));
    }
    
    string cursorRight(int k) {
        idx = min((int)words.size(), idx+k);
        return words.substr(max(0, idx-min(10, idx)), min(10, idx));
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
