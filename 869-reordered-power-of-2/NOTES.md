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
```
​
**Time complexity can be smartly improved using smart hashing  TC=(32*9*9)**
```
bool reorderedPowerOf2(int N) {
long c = counter(N);
for (int i = 0; i < 32; i++)
if (counter(1 << i) == c) return true;
return false;
}
​
long counter(int N) {
long res = 0;
for (; N; N /= 10) res += pow(10, N % 10);
return res;
}
```