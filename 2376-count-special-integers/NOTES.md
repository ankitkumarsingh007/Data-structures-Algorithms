**Very brilliantly written solution , maths involved mainly**
```
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