class Solution {
public:
    typedef long long ll;
    
    bool ispossible(ll &val,ll &x,ll &y,ll &lim){
        ll total=val;
        
        if((val-1)<=x)
            total+=((val-1)*val/2+(x-val+1));
        else
            total+=((x*(x+1))/2 + x*(val-1-x));
        
        if((val-1)<=y)
            total+=((val-1)*val/2+(y-val+1));
        else
            total+=((y*(y+1))/2 + y*(val-1-y));
        
        return total<=lim;
    }
    
    int maxValue(ll n, ll index, ll maxSum) {
        ll x=index,y=n-1-index;
        ll l=1,r=maxSum;
        ll res=1;
        
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(ispossible(mid,x,y,maxSum)){
                res=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        
        return res;
    }
};