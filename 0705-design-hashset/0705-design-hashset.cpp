class MyHashSet {
public:
    vector<vector<int>> arr;
    
    MyHashSet() {
        arr.resize(1007);
    }
    
    int hash(int key){
        return key%1007;
    }
    
    void add(int key) {
        int a=hash(key);
        
        if(contains(key))
            return;
        
        arr[a].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))
            return;
        
        int i,a=hash(key),n=arr[a].size();
        
        for(i=0;i<n;i++){
            if(arr[a][i]==key)
                break;
        }
        
        for(int j=i+1;j<n;j++){
            arr[a][i++]=arr[a][j];
        }
        
        arr[a].pop_back();
    }
    
    bool contains(int key) {
        int a=hash(key);
        
        for(int x:arr[a])
            if(x==key)
                return true;
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */