class MyCalendar {
public:
    vector<int> arr;
    unordered_map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(arr.size()==0){
            arr.push_back(start);
            mp[start]=end;
            return true;
        }
        else{
            sort(arr.begin(),arr.end());
            
            int pos=upper_bound(arr.begin(),arr.end(),start)-arr.begin(),n=arr.size();
            
            int prevend=INT_MIN,nextstart=INT_MAX;
            if(pos!=0)
                prevend=mp[arr[pos-1]];
            if(pos!=n)
                nextstart=arr[pos];
            
            if(prevend<=start && nextstart>=end){
                arr.push_back(start);
                mp[start]=end;
                return true;
            }
            else
                return false;
        }
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */