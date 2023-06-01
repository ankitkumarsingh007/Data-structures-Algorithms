class Solution {
public:
    string convert(string s, int l) {
        int n=s.size();
        string res="";
        
        if(l==1)
            return s;
        
        for(int i=0;i<l;i++){
            int j=i;
            
            if(i==0 || i==l-1){
                while(j<n){
                    res+=s[j];
                    j+=(2*l-2);
                }
            }
            else{
                while(j<n){
                    res+=s[j];
                    j+=(2*(l-i-1));
                    if(j<n){
                        res+=s[j];
                        j+=(2*i);
                    }
                }
            }
        }
        return res;
    }
};