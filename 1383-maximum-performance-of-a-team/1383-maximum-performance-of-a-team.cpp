typedef long long ll;

class Solution {
public:
    int m=1e9+7;
    
    static bool comp(vector<ll> &a,vector<ll> &b){
        return a[0]>b[0];
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<ll>> arr;
        for(ll i=0;i<n;i++){
            arr.push_back({efficiency[i],speed[i]});
        }
        
        sort(arr.begin(),arr.end(),comp);
        
        
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll curr=0,maxx=0;
        
        for(ll i=0;i<n;i++){
            if(pq.size()<k){
                curr+=arr[i][1];
                pq.push(arr[i][1]);
            }
            else if(arr[i][1]>pq.top()){
                curr+=arr[i][1];
                curr-=pq.top();
                pq.pop();
                pq.push(arr[i][1]);
            }
            
            maxx=max(maxx,curr*arr[i][0]);
        }
        
        
        return maxx%m;
    }
};