class Solution {
public:
   vector<int> findSubstring(string s, vector<string>& words) {
       unordered_map<string,int> mp;
       for(string x:words)
           mp[x]++;
       
       int n=s.size(),num=words.size(),len=words[0].size();
       
       vector<int> res;
       
       for(int i=0;i<(n-num*len+1);i++){
           unordered_map<string,int> curr;
           
           int j=0;
           for(j;j<num;j++){
               string x=s.substr(i+j*len,len);
               
               if(mp.find(x)!=mp.end()){
                   curr[x]++;
                   if(curr[x]>mp[x])
                       break;
               }
               else
                   break;
           }
           
           if(j==num)
               res.push_back(i);
       }
       
       return res;
    }
};