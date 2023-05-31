class UndergroundSystem {
public:
    typedef pair<string,int> pp1;
    typedef pair<double,int> pp2;
    
    unordered_map<int,pp1> start;
    unordered_map<string,unordered_map<string,pp2>> mp;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        start[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s=start[id].first,e=stationName;
        int in=start[id].second;
        
        start.erase(id);
        
        pp2 a=mp[s][e];
        
        double avg=a.first;
        int freq=a.second;
        
        avg=(avg*freq+t-in)/(freq+1);
        
        mp[s][e]={avg,freq+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return mp[startStation][endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */