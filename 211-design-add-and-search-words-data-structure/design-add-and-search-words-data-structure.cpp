struct Node {
    Node* child[26];
    bool isEnd;
    Node() {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isEnd = false;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            int ind = c - 'a';
            if (!curr->child[ind]) {
                curr->child[ind] = new Node();
            }
            curr = curr->child[ind];
        }
        curr->isEnd = true;
        return;
    }

    bool searchHelper(string word, int i, Node* curr) {
        if (i == word.size())
            return curr->isEnd;

        for (; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curr->child[j] && searchHelper(word, i + 1, curr->child[j]))
                        return true;
                }
                return false;
            } else {
                int ind = word[i] - 'a';
                if (!curr->child[ind])
                    return false;
                curr = curr->child[ind];
            }
        }
        return curr->isEnd;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */