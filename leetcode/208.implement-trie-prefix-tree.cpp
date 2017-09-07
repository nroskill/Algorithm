/**
 * https://leetcode.com/problems/implement-trie-prefix-tree/
 * By Nroskill
 * runtime 62 ms
 * language cpp
 */

class Treenode {
public:
    char val;
    vector<Treenode*> next;
    bool isEnd;
    
    Treenode(char val) {
        this->val = val;
        this->isEnd = false;
    }
};

class Trie {
private:
    Treenode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Treenode(' ');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto t = root;
        for(int i = 0; i < word.length(); i++) {
            int j;
            for(j = 0; j < t->next.size(); j++)
                if(t->next[j]->val == word[i])
                    break;
            if(j == t->next.size())
                t->next.push_back(new Treenode(word[i]));
            t = t->next[j];
        }
        t->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto t = root;
        for(int i = 0; i < word.length(); i++) {
            int j;
            for(j = 0; j < t->next.size(); j++)
                if(t->next[j]->val == word[i])
                    break;
            if(j == t->next.size())
                return false;
            t = t->next[j];
        }
        return t->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto t = root;
        for(int i = 0; i < prefix.length(); i++) {
            int j;
            for(j = 0; j < t->next.size(); j++)
                if(t->next[j]->val == prefix[i])
                    break;
            if(j == t->next.size())
                return false;
            t = t->next[j];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */