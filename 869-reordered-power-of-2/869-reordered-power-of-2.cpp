class Solution {
public:
    string s;
    int x,size;
    
    bool helper(int l,int r){
        if(l==r){
            x=stoi(s);
            
            if((x&(x-1))==0)
                return true;
            else
                return false;
        }
        
        for(int i=l;i<=r;i++){
            if(l!=0 || s[i]!='0'){
                swap(s[l],s[i]);
                if(helper(l+1,r)==true)
                    return true;
                swap(s[l],s[i]);
            }
        }
        
        return false;
    }
    
    bool reorderedPowerOf2(int n) {
        s=to_string(n);
        size=s.size();
        return helper(0,size-1);
    }
};