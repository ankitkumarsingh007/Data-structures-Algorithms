class Solution {
public:
    string intToRoman(int num) {
        string res="";
        
        vector<int> val={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> s={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        for(int i=0;i<13;i++){
            while(num>=val[i]){
                res+=s[i];
                num-=val[i];
            }
        }
        
        return res;
    }
};