class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> graph;
        
        //for making graph
        unordered_set<string> st;
        int len=wordList[0].size();
        
        for(string s:wordList)
            st.insert(s);
        
        //no result possible
        if(st.find(endWord)==st.end())
            return res;
        if(st.find(beginWord)==st.end()){
            st.insert(beginWord);
            wordList.push_back(beginWord);
        }
        
        //making graph
        for(string s:wordList){
            for(int i=0;i<len;i++){
                char c=s[i];
                string x=s;
                for(int j=0;j<26;j++){
                    if((j+'a')==c)
                        continue;
                    else{
                        s[i]=char(j+'a');
                        if(st.find(s)!=st.end())
                            graph[x].push_back(s);
                        s[i]=c;
                    }
                }
            }
        }
        
        unordered_map<string,int> dis;
        for(string s:wordList){
            dis[s]=INT_MAX;
        }
        
        dis[beginWord]=0;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            string s=q.front();
            q.pop();
            
            for(string x:graph[s]){
                if(dis[x]==INT_MAX){
                    dis[x]=dis[s]+1;
                    q.push(x);
                }
            }
        }
        
        
        if(dis[endWord]==INT_MAX)
            return res;
        
        queue<vector<string>> q1;
        q1.push({endWord});
                   
        while(!q1.empty()){
            vector<string> v=q1.front();
            q1.pop();
            
            string s=v.back();
            if(s==beginWord){
                reverse(v.begin(),v.end());
                res.push_back(v);
                continue;
            }
            
            for(string x:graph[s]){
                if((dis[x]+1)==dis[s])
                {
                    v.push_back(x);
                    q1.push(v);
                    v.pop_back();
                }
            }
        }           
        
        return res;
    }
};