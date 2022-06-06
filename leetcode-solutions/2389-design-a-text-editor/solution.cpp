class TextEditor {
    string s;
    int pos ;
public:
    TextEditor() {
        pos = 0;
    }
    
    void addText(string text) {
        s.insert(pos, text);
        pos += text.size();
        // cout << "add" << endl;
    }
    
    int deleteText(int k) {
        int ans = 0;
        while (pos != 0 && ans < k) {
            s.erase(pos-1, 1);
            --pos;
            ++ans;
        }
        // cout << "delet" << endl;
        return ans;
    }
    
    string cursorLeft(int k) {
        // cout << "r" << endl;
        pos = max(pos-k, 0);
        string res;
        for (int i = pos-10; i < pos; ++i) if (i >= 0) res += s[i];
        return res;
    }
    
    string cursorRight(int k) {
        // cout << "R" << endl;
        pos = min(pos+k, int(s.size()));
        string res;
        for (int i = pos-10; i < pos; ++i) if (i >= 0) res += s[i];
        return res;
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

