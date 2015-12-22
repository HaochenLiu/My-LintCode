/*
473. Add and Search Word

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Have you met this question in a real interview? Yes
Example
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note
You may assume that all words are consist of lowercase letters a-z.
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
        return searchRecur(word, 0, root);
    }

    bool searchRecur(string word, int start, TrieNode* node) {
        if(word.empty()) return root->finish;
        int n = word.size();
        for(int i = start; i < n; i++) {
            if(word[i] != '.') {
                int idx = word[i] - 'a';
                if(node->child[idx] == NULL) {
                    return false;
                }
                node = node->child[idx];
            } else {
                for(int j = 0; j < N; j++) {
                    if(node->child[j] == NULL) {
                        continue;
                    }
                    if(searchRecur(word, i + 1, node->child[j])) {
                        return true;
                    }
                }
                return false;
            }
        }

        return node->finish;
    }

private:
    TrieNode* root;
};

class WordDictionary {
private:
    Trie t;
    
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        t.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        if(word.empty()) return false;
        return t.search(word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
