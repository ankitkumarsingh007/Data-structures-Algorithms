class Solution {
public:
    typedef pair<int,int> pp;
    int n;
    vector<pp> arr;
    vector<int> res;
    
    void merge(int l,int mid,int r){
        vector<pp> left,right;
        
        for(int i=l;i<=mid;i++)
            left.push_back(arr[i]);
        for(int i=mid+1;i<=r;i++)
            right.push_back(arr[i]);
        
        int n1=left.size(),n2=right.size(),i=0,j=0,k=l,cnt=0;
        
        while(i<n1 && j<n2){
            if(left[i].first<=right[j].first)
            {
                res[left[i].second]+=cnt;
                arr[k++]=left[i++];
            }
            else{
                cnt++;
                arr[k++]=right[j++];
            }
        }
        
        while(i<n1){
            res[left[i].second]+=cnt;
            arr[k++]=left[i++];
        }
        while(j<n2){
            arr[k++]=right[j++];
        }
        
        return;
    }
    
    void mergesort(int l,int r){
        if(l>=r)
            return;
        
        int mid=(l+r)/2;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,r);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        arr.clear();
        n=nums.size();
        
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        
        res.clear();
        res.resize(n,0);
        
        mergesort(0,n-1);
        
        return res;
    }
};