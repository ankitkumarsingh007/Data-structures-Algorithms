**Simple solution with simple logic**
```
bool isPowerOfFour(int n) {
if(n<=0)
return false;
if((n&(n-1))!=0)
return false;
int cnt=0;
while((n&1)!=1){
n>>=1;
cnt++;
}
return cnt%2==0;
}
```
​
**Briliant observation to convert this in one line code**
*(4^n - 1) % 3 == 0
another proof:
(1) 4^n - 1 = (2^n + 1) * (2^n - 1)
(2) among any 3 consecutive numbers, there must be one that is a multiple of 3
among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n) cannot be the one, therefore either (2^n-1) or (2^n+1) must be a multiple of 3, and 4^n-1 must be a multiple of 3 as well.*
​