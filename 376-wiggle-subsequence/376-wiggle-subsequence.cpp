class Solution {
public:
    int wiggleMaxLength(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 1;
        
        vector<int> bigend(n,1),smallend(n,1);
        
        int res=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]>arr[i])
                    smallend[i]=max(smallend[i],1+bigend[j]);
                else if(arr[j]<arr[i])
                    bigend[i]=max(bigend[i],1+smallend[j]);
            }
            
            res=max(res,max(bigend[i],smallend[i]));
        }
        
        return res;
    }
};