class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        val = v;
        key = k;
        prev = NULL;
        next = NULL;
    }
    Node() {
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    int size;
    Node *left, *right;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        left = new Node(), right = new Node();
        left->next = right, right->prev = left;
        size = capacity;
    }

    void remove(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        return;
    }

    void insert(Node* curr) {
        curr->next = right;
        curr->prev = right->prev;

        right->prev->next = curr;
        right->prev = curr;

        return;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* curr = mp[key];
        remove(curr);
        insert(curr);

        return curr->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* curr = mp[key];

            remove(curr);
            insert(curr);
            curr->val = value;
        } else if (size > 0) {
            mp[key] = new Node(key, value);
            insert(mp[key]);
            size--;
        } else {
            Node* last = left->next;

            remove(last);
            mp.erase(last->key);
            delete last;

            mp[key] = new Node(key, value);
            insert(mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */