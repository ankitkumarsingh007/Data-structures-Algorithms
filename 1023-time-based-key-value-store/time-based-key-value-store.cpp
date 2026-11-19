class TimeMap {
    struct valueUpdates{
        unordered_map<int,string> valueUpdatesSummary;
        set<int> st;

        void push(int time,string val){
            valueUpdatesSummary[time] = val;
            st.insert(time);
        }

        string get(int time){
            auto itr = st.upper_bound(time);
            if(itr == st.begin())
            return "";

            itr--;
            return valueUpdatesSummary[*itr];
        }
    };
    unordered_map<string,valueUpdates> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))
        return "";

        return mp[key].get(timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */