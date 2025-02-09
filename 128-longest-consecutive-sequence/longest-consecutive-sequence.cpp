class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        unordered_set<int> st;
        
        for(int a:nums){
            st.insert(a);
        }

        for(int a:nums){
            if(st.find(a)!=st.end() && st.find(a+1)==st.end()){
                int x=a,cnt=0;
                while(st.find(x)!=st.end()){
                    st.erase(x--);
                    cnt++;
                }
                res=max(res,cnt);
            }
        }

        return res;
    }
};