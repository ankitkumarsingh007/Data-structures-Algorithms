class Solution {
public:
    string intToRoman(int num) {
        string s="";
        
        int a=num/1000;
        num%=1000;
        while(a--)
            s+='M';

        if(num>=900)
        {
            s+="CM";
            num-=900;
        }
        if(num>=500){
            s+='D';
            num-=500;
        }
        if(num>=400){
            s+="CD";
            num-=400;
        }

        a=num/100;
        while(a--)
            s+='C';

        num%=100;
        if(num>=90){
            s+="XC";
            num-=90;
        }
        if(num>=50){
            s+='L';
            num-=50;
        }
        if(num>=40){
            s+="XL";
            num-=40;
        }

        a=num/10;
        num%=10;
        while(a--)
            s+='X';

        if(num==9){
            num-=9;
            s+="IX";
        }
        if(num>=5){
            num-=5;
            s+='V';
        }
        if(num==4){
            num-=4;
            s+="IV";
        }

        while(num--)
            s+='I';
        
        return s;
    }
};