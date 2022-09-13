class Solution {
public:
    bool validUtf8(vector<int>& arr) {
        int n=arr.size();
        
        for(int &x:arr){
            x=(x&255);
        }
        
        for(int i=0;i<n;)
        {
            int cnt=0;
            
            for(int j=7;j>=0;j--){
                if((arr[i]&(1<<j)) != 0)
                    cnt++;
                else
                    break;
            }
            
            if(cnt==0)
                i++;
            else if(cnt==1 || cnt>4)
                return false;
            else{
                i++;
                while(cnt>1 && i<n){
                    if( ((1<<7)&arr[i])!=0 && ((1<<6)&arr[i])==0 )
                        i++,cnt--;
                    else
                        return false;
                }
                
                if(cnt!=1)
                    return false;
            }
        }
        
        return true;
    }
};


