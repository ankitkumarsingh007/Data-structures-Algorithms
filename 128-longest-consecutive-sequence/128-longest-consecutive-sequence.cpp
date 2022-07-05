class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> s(arr.begin(),arr.end());
        
        int res=0;
        for(int &a:arr)
        {
            //if it is first occurence of that sequence
            //only then run this loop
            if(s.find(a-1)==s.end())
            {
                int cnt=1;
                a++;
                while(s.find(a)!=s.end())
                {
                    cnt++;
                    a++;
                }
                res=max(res,cnt);
            }
        }
        
        return res;
    }
};