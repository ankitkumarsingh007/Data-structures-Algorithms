class SnapshotArray {
public:
    
    vector<vector<int>> arr;
    int n;
    unordered_map<int,unordered_map<int,int>> mp;
    int cnt=0;    
    
    SnapshotArray(int length) {
        n=length;
        arr.resize(n,vector<int>(1,0));
    }
    
    void set(int index, int val) {
        if(mp[index][arr[index].back()]!=val){
            if(arr[index].back()==cnt)
                mp[index][cnt]=val;
            else{
                arr[index].push_back(cnt);
                mp[index][cnt]=val;
            }
        }
        
        return;
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        int pos=upper_bound(arr[index].begin(),arr[index].end(),snap_id)-arr[index].begin()-1;
        
        return mp[index][arr[index][pos]];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */