class LFUCache {
    struct Node {
        int val, key, freq;
        Node *prev, *next;

        Node(int a, int b) {
            val = a, key = b;
            freq = 1;
            prev = NULL;
            next = NULL;
        }
    };

    struct DLL {
        Node *left, *right;
        int size;

        DLL() {
            left = new Node(0, 0);
            right = new Node(0, 0);

            left->next = right;
            right->prev = left;
            size = 0;
        }

        // Detach node from the list, but don't delete it
        void pop(Node* curr) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            curr->prev = curr->next = NULL;
            size--;
        }

        // Insert at right (most recently used)
        void pushRight(Node* curr) {
            curr->prev = right->prev;
            curr->next = right;

            right->prev->next = curr;
            right->prev = curr;

            size++;
        }

        // Permanently remove the LRU node
        void popLeft() {
            Node* deleteNode = left->next;

            left->next = deleteNode->next;
            deleteNode->next->prev = left;

            size--;
            delete deleteNode;
        }

        bool isempty() {
            return size == 0;
        }
    };

    unordered_map<int, DLL*> freqList; // frequency -> DLL
    unordered_map<int, Node*> nodeList; // key -> node

    int minFreq, capacity;

    // Increase frequency of an existing node
    void increaseFreq(Node* curr) {
        int oldFreq = curr->freq;

        // Remove from old frequency list
        freqList[oldFreq]->pop(curr);

        // Update minFreq only if the old minimum list becomes empty
        if (oldFreq == minFreq && freqList[oldFreq]->isempty()) {
            minFreq++;
        }

        // Increase frequency
        curr->freq++;

        // Create new frequency list if needed
        if (!freqList.count(curr->freq)) {
            freqList[curr->freq] = new DLL();
        }

        // Insert as most recently used in new frequency
        freqList[curr->freq]->pushRight(curr);
    }

public:
    LFUCache(int cap) {
        minFreq = 0;
        capacity = cap;
    }

    int get(int key) {
        if (!nodeList.count(key)) {
            return -1;
        }

        Node* curr = nodeList[key];

        // Access increases frequency
        increaseFreq(curr);

        return curr->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // Key already exists: update and increase frequency
        if (nodeList.count(key)) {
            Node* curr = nodeList[key];

            curr->val = value;
            increaseFreq(curr);

            return;
        }

        // Cache full: evict LFU, and LRU among LFU
        if (nodeList.size() == capacity) {
            Node* victim = freqList[minFreq]->left->next;

            nodeList.erase(victim->key);
            freqList[minFreq]->popLeft();
        }

        // Insert new node (frequency = 1)
        Node* curr = new Node(value, key);

        nodeList[key] = curr; // Important: insert into hashmap

        if (!freqList.count(1)) {
            freqList[1] = new DLL();
        }

        freqList[1]->pushRight(curr);

        minFreq = 1; // Every new node starts at frequency 1
    }
};