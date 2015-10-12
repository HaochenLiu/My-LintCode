/*
442. Implement Trie

Implement a trie with insert, search, and startsWith methods.
Have you met this question in a real interview?
Example
*/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
 
const int N = 26;

class TrieNode {
public:
    char c;
    bool finish;
    vector<TrieNode*> child;

    // Initialize your data structure here.
    TrieNode(char c = 0, bool finish = false) {
        this->c = c;
        this->finish = finish;
        child.resize(N, NULL);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(word.empty()) {
            root->finish = true;
            return;
        }
        int n = word.size();
        TrieNode* node = root;
        for(int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if(node->child[idx] == NULL) {
                node->child[idx] = new TrieNode(word[i], false);
            }
            node = node->child[idx];
        }
        node->finish = true;

        return;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(word.empty()) return root->finish;
        int n = word.size();
        TrieNode* node = root;
        for(int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if(node->child[idx] == NULL) {
                return false;
            }
            node = node->child[idx];
        }

        return node->finish;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.empty()) return root->finish;
        int n = prefix.size();
        TrieNode* node = root;
        for(int i = 0; i < n; i++) {
            int idx = prefix[i] - 'a';
            if(node->child[idx] == NULL) {
                return false;
            }
            node = node->child[idx];
        }

        return true;
    }

private:
    TrieNode* root;
};
