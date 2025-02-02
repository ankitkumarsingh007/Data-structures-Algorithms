class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int l=-1,r=n,i=0;

        while(i<r){
            if(arr[i]==2){
                r--;
                swap(arr[i],arr[r]);
                continue;
            }else if(arr[i]==0){
                l++;
                swap(arr[l],arr[i]);
            }
            i++;
        }

        return;
    }
};