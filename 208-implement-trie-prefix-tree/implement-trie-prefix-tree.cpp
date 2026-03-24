struct Node {
    Node* child[26];
    bool isEnd;
    Node() {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isEnd = false;
    }
};
class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(string word) {
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

    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            int ind = c - 'a';
            if (!curr->child[ind])
                return false;
            curr = curr->child[ind];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int ind = c - 'a';
            if (!curr->child[ind])
                return false;
            curr = curr->child[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */