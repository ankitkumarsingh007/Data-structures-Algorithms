return res;
}
```
​
​
***But it would be much better if we optimized it further***
*Suppose we have n digits. After removal we are left with n-1 digits.
We start traversing from the left. If we encounter a candidate digit we have two options:
1). Delete it: In this case the i'th position will be taken by the next (i+1)'th digit.
2). Not delete it.
Now the crux of the solution is to determine whether to delete the ith element or not.
Lets say that the i'th element is smaller than element at i+1 position. Then if we delete the i'th element, the bigger element at i+1 position will take the i'th position and make the number bigger. Hence it is in our advantage to delete that number. If we encounter such a case traversing from left, we will delete that digit and get our answer. We dont need to consider the digits remaining on the right side as any possible increase in number will always be less than current change by some order of ten.
If on the other hand , if the i'th element is bigger than the next element. Then if we delete the i'th element , we are reducing the number which is not desirable. Hence we wont delete in this case.
If we cannot find any such pairing where digit at i'th position < digit at i+1'th position. We will take the rightmost occurence of the digit. The reason being that any case of deletion will effectively reduce the number value so we will try to minimize that reduction. This will be achieved by selecting the rightmost occurence of the digit.*
​
​
​