class Solution {
public:
    bool validUtf8(vector<int>& arr) {
        int n=arr.size();
        
        for(int &x:arr){
            x=(x&255);
        }
        
        int mask[5];
        for(int i=0,j=7;i<5;i++,j--){
            mask[i]=(1<<j);
        }
        
        for(int i=0;i<n;)
        {
            int cnt=0;
            
            for(int j=0;j<5;j++){
                if((arr[i]&mask[j])!=0)
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
                    if( (mask[0]&arr[i])!=0 && (mask[1]&arr[i])==0 )
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


