// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        //to store all string
        unordered_set<string> st (wordList.begin(),wordList.end());
        //to store all visited ones only
        unordered_set<string> visited;
        
        //ans array
        vector<vector<string>> ans;
        
        //queue for BFS
        queue<vector<string>> q;
        q.push({beginWord});
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr_path = q.front();
                q.pop();
                string last = curr_path.back();
                for(int i = 0 ; i < last.size() ; ++i){
                    auto temp = last;
                    for(char ch = 'a' ; ch <= 'z' ; ++ch){
                        temp[i] = ch;
                        if(st.find(temp) != st.end()){
                            auto new_path = curr_path;
                            new_path.push_back(temp);
                            visited.insert(temp);
                            if(temp == endWord)
                                ans.push_back(new_path);
                            else
                                q.push(new_path);
                        }
                    }
                }
            }
            //so that any string can be used in one step only
            for(auto& str : visited)
                    st.erase(str);
        }
        return ans;
    }
};

// { Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}  // } Driver Code Ends