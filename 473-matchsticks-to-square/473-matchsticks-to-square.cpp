class Solution {
public:
    bool fun(vector<int> &arr,int a,int b,int c,int d,int n,int &lim){
        if(n==arr.size()){
            if(a==b && b==c && c==d)
                return true;
            else
                return false;
        }
        
        if((a+arr[n])<=lim && fun(arr,a+arr[n],b,c,d,n+1,lim))
            return true;
        if((b+arr[n])<=lim && fun(arr,a,b+arr[n],c,d,n+1,lim))
        return true;
        if((c+arr[n])<=lim && fun(arr,a,b,c+arr[n],d,n+1,lim))
        return true;
        if((d+arr[n])<=lim && fun(arr,a,b,c,d+arr[n],n+1,lim))
        return true;
        
        return false;
    }
    bool makesquare(vector<int>& arr) {
        int n=arr.size(),sum=0;
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        for(int a:arr)
            sum+=a;
        
        if(sum%4!=0)
            return false;
        sum/=4;
        
        return fun(arr,0,0,0,0,0,sum);
    }
};