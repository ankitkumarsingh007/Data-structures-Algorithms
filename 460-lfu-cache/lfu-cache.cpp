class LFUCache {
    struct Node {
        int key, val, freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1; // Every new key starts with frequency 1
            prev = next = nullptr;
        }
    };

    struct DLL {
        Node* left;
        Node* right;
        int size;

        DLL() {
            left = new Node(0, 0);  // Dummy left node
            right = new Node(0, 0); // Dummy right node

            left->next = right;
            right->prev = left;
            size = 0;
        }

        // Insert node at the right (most recently used)
        void pushRight(Node* node) {
            Node* last = right->prev;

            last->next = node;
            node->prev = last;

            node->next = right;
            right->prev = node;

            size++;
        }

        // Remove a node from the list
        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->prev = node->next = nullptr;
            size--;
        }

        // Remove and return the leftmost (LRU) node
        Node* popLeft() {
            Node* node = left->next;
            remove(node);
            return node;
        }

        bool empty() { return size == 0; }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> nodeMap; // key -> node
    unordered_map<int, DLL*> listMap;  // frequency -> DLL

    // Increase frequency of a node after get() or updating an existing key
    void increaseFreq(Node* node) {
        int oldFreq = node->freq;

        // Remove node from its current frequency list
        listMap[oldFreq]->remove(node);

        // If this was the last node at minimum frequency,
        // the minimum frequency will increase by 1
        if (oldFreq == minFreq && listMap[oldFreq]->empty()) {
            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Create the new frequency list if it doesn't exist
        if (!listMap.count(node->freq)) {
            listMap[node->freq] = new DLL();
        }

        // Add node as most recently used at its new frequency
        listMap[node->freq]->pushRight(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        // Key does not exist
        if (!nodeMap.count(key)) {
            return -1;
        }

        Node* node = nodeMap[key];

        // Accessing a key increases its frequency
        increaseFreq(node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        // Key already exists: update value and increase frequency
        if (nodeMap.count(key)) {
            Node* node = nodeMap[key];
            node->val = value;
            increaseFreq(node);
            return;
        }

        // Cache is full: evict LFU, and LRU among LFU keys
        if (nodeMap.size() == capacity) {
            DLL* list = listMap[minFreq];

            Node* victim = list->popLeft();

            nodeMap.erase(victim->key);
            delete victim;
        }

        // Insert new node (frequency starts at 1)
        Node* node = new Node(key, value);
        nodeMap[key] = node;

        // All new nodes enter frequency 1
        if (!listMap.count(1)) {
            listMap[1] = new DLL();
        }

        listMap[1]->pushRight(node);

        // Newly inserted node has the lowest frequency
        minFreq = 1;
    }
};