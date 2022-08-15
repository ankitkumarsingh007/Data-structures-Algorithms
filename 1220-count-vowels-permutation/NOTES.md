**Simple DP based code**
```
typedef long long ll;
ll mod=1e9+7;
int countVowelPermutation(int n) {
ll a=1,e=1,i=1,o=1,u=1;
for(int k=2;k<=n;k++){
ll a1=(e+u+i)%mod;
ll e1=(a+i)%mod;
ll i1=(e+o)%mod;
ll o1=(i)%mod;
ll u1=(i+o)%mod;
a=a1,e=e1,i=i1,o=o1,u=u1;
}
return (a+e+i+o+u)%mod;
}
```