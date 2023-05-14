class Solution {
public:
    unordered_map<int,unordered_map<int,int>> aux;

    vector<int> identify;
    int n,pos;

    vector<vector<int>> temp;
    vector<int> curr;

    void helper(){
        if(pos==0){
           temp.push_back(curr);
           return;
        }

        pos-=2;
        int i,a;

        for(i=0;i<n;i++){
            if(identify[i]>0)
            break;
        }

        a=identify[i];
        identify[i]*=-1;

        for(int j=i+1;j<n;j++){
            if(identify[j]>0){
                curr.push_back(aux[a][identify[j]]);
                identify[j]*=-1;
                helper();
                curr.pop_back();
                identify[j]*=-1;
            }
        }
        
        identify[i]*=-1;
        pos+=2;
    }

    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                aux[nums[i]][nums[j]]=__gcd(nums[i],nums[j]);
            }
        }

        unordered_set<int> s;
        vector<int> v;
        for(int x:nums){
            if(s.find(x)==s.end())
            s.insert(x);
            else{
                s.erase(x);
                v.push_back(x);
            }
        }

        for(auto itr=s.begin();itr!=s.end();itr++){
            identify.push_back(*itr);
        }
        sort(identify.begin(),identify.end());

        n=identify.size();
        pos=n;
        
        helper();
        int res=0;

        for(auto vec:temp){
            for(int x:v){
                vec.push_back(x);
            }

            sort(vec.begin(),vec.end());
            int x=0;

            for(int i=0;i<vec.size();i++){
                x+=(i+1)*vec[i];
            }
            res=max(res,x);
        }

        return res;
    }
};