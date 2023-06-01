return 1;
}
while(!q.empty()){
pp p=q.front();
q.pop();
int a=p.first,b=p.second;
for(int i=0;i<8;i++){
int a1=a+x[i],b1=b+y[i];
if(isvalid(a1,b1) && dis[a1][b1]==INT_MAX && grid[a1][b1]==0){
dis[a1][b1]=dis[a][b]+1;
q.push({a1,b1});
if(a1==(m-1) && b1==(n-1))
return dis[a1][b1];
}
}
}
return -1;
}
```
​
#### Code with constant space complexity
```
​
```