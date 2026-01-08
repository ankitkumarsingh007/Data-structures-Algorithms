class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> arr;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;

        mp[val] = arr.size();
        arr.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;

        int lastVal = arr.back();
        arr[mp[val]] = lastVal;
        mp[lastVal] = mp[val];
        arr.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = arr.size() ? rand() % arr.size() : 0;
        return *(arr.begin() + randomIndex);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */