class Solution {
public:
    typedef long long ll;
    bool isPowerOfThree(int n) {
        if(n==1){
            return true;
        }
        if(n<3)
        return false;

        ll r = ceil(log(n)/log(3)) , l = 1;

        while(l<=r){
            ll mid = l+(r-l)/2;
            ll val = pow(3,mid);

            if(val>n){
                r=mid-1;
            }else if(val<n){
                l=mid+1;
            }else{
                return true;
            }
        }

        return false;
    }
};