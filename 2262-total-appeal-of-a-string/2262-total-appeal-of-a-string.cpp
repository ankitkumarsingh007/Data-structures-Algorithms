class Solution {
public:
    typedef long long ll;
    long long appealSum(string s) {
        ll n=s.size(),res=0,minus=0;
        int arr[26]={};
        
        for(ll i=0;i<n;i++){
            ll a=i+1;
            
            minus+=arr[s[i]-'a'];
            arr[s[i]-'a']=a;
            
            res+=((a)*(a+1))/2;
            res-=minus;
        }
        
        return res;
    }
};