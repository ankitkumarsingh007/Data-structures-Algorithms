class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();

        int i=n-1;

        for(i;i>0;i--){
            if(arr[i]>arr[i-1]){
                int j=i+1;
                for(j;j<n;j++){
                    if(arr[j]<=arr[i-1])
                    break;
                }

                swap(arr[i-1],arr[j-1]);
                sort(arr.begin()+i,arr.end());
                break;
            }
        }

        if(i==0)
        sort(arr.begin(),arr.end());
    }
};