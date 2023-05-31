class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)!=st.end())
            return false;
        
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val)==st.end())
            return false;
        
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=st.size(),pos=rand()%n;
        auto a=st.begin();
        
        while(pos--)
            a++;
        
        return *a;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */