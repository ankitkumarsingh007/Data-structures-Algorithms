class Solution {
public:
    int countSpecialNumbers(int n) {
        unordered_map<int,int> mp;
        // add result for exactly length<log10(n)
        mp[1]=9;
        mp[2]=9*9;
        mp[3]=9*9*8;
        mp[4]=9*9*8*7;
        mp[5]=9*9*8*7*6;
        mp[6]=9*9*8*7*6*5;
        mp[7]=9*9*8*7*6*5*4;
        mp[8]=9*9*8*7*6*5*4*3;
        mp[9]=9*9*8*7*6*5*4*3*2;
        mp[10]=9*9*8*7*6*5*4*3*2;
        
        int res=0,x=log10(n);
        
        for(int i=1;i<=x;i++)
            res+=mp[i];
        
        // add result for exactly length=log10(n)
        string s=to_string(n);
        n=s.size();
        
        vector<bool> used(10,false);
        int i=0;
        
        for(i;i<n;i++){
            int add;
            if(i==0){
                add=(s[i]-'0'-1);
            }
            else{
                add=(s[i]-'0'-1);
                int temp=add;
                for(int i=0;i<=temp;i++)
                    if(used[i])
                        add--;
                add++;
            }
            
            int mul=9-i;
            for(int j=1;j<(n-i);j++)
                add*=(mul--);
            
            res+=add;
            
            // if any digit repeated no need to investigate further
            if(used[s[i]-'0'])
                break;
            else
                used[s[i]-'0']=true;
        }
        
        //that no itself is special one
        if(i==n)
            res++;
        
        return res;
    }
};