class Solution {
public:
    typedef long long ll;
    int m=1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<ll,ll> mp;
        
        if(n==1)
            return 1;
        
        mp[arr[0]]=1;
        ll res=1;
        
        for(ll i=1;i<n;i++){
            ll cnt=1,a=arr[i],j;
            
            for(j=2;j*j<a;j++){
                if(a%j==0){
                    if(mp.find(j)!=mp.end() && mp.find(a/j)!=mp.end())
                        // if(j!=(a/j))
                            cnt=(cnt+mp[j]*mp[a/j]*2)%m;
                        // else
                        //     cnt+=(mp[j]*mp[j]);
                        // cnt%=m;
                }
            }
            if(j*j==a)
                cnt=(cnt+mp[j]*mp[a/j])%m;
            
            mp[a]=cnt;
            res=(res+cnt)%m;
        }
        
        return res;
    }
};