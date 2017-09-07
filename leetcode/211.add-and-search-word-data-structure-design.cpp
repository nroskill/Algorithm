/**
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/
 * By Nroskill
 * runtime 119 ms
 * language cpp
 */

class Node {
public:
    bool isEnd;
    unordered_map<char, Node*> next;

    Node() {
        isEnd = false;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto t = root;
        for(int i = 0; i < word.length(); i++) {
            if(t->next.find(word[i]) == t->next.end())
                t->next[word[i]] = new Node();
            t = t->next[word[i]];
        }
        t->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        auto t = root;
        for(int i = 0; i < word.length(); i++) {
            if(word[i] == '.') {
                for(auto j = t->next.begin(); j != t->next.end(); j++) {
                    word[i] = j->first;
                    if(search(word))
                        return true;
                }
                return false;
            }
            else if(t->next.find(word[i]) == t->next.end())
                return false;
            t = t->next[word[i]];
        }
        return t->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */