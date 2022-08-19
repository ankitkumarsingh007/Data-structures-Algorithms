**I think you have to first realize that each number can either be the beginning or the end of the sequence at a given point of iteration. Another subtle insight to this solution is proving that appending to a previous sequence is always better than creating a new sequence. Consider the problem [1,2,3,4,5,5,6,7] and how prioritizing the creation of a subsequence over appending would cause an issue.
However, don't feel bad because I think a lot of people, myself included, did not find this problem to have a very intuitive answer. In an interview setting I would hope for some generous hints.**
​
[For logic refer this solution ](https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106514/C%2B%2BPython-Esay-Understand-Solution)
​
```
bool isPossible(vector<int>& nums) {
unordered_map<int,int> left,end;
for(int x:nums)
left[x]++;
for(int i:nums){
if(left[i]==0)
continue;
left[i]--;
if(end[i-1]>0){
end[i-1]--;
end[i]++;
}
else if(left[i+1]>0 && left[i+2]>0){
left[i+1]--;
left[i+2]--;
end[i+2]++;
}
else
return false;
}
return true;
}
```