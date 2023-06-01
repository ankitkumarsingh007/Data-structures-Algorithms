class Solution {
public:
    string convert(string s, int l) {
            int n=s.size();
            string res="";

            if(l==1)    //corner case
            return s;

            int gap=2*l-2;
            for(int i=0;i<l;i++)
            {
                int j=i;
                if(i==0 || i==l-1)  //special care
                {
                    while(j<n)
                    {
                        res+=s[j];
                        j+=gap;
                    }
                }
                else               //regular care
                {
                    int gap2=2*i,gap1=gap-gap2;
                    while(j<n)
                    {
                        res+=s[j];
                        j+=gap1;
                        if(j<n)
                        {
                            res+=s[j];
                            j+=gap2;
                        }
                    }
                }
            }

            return res;
        }
};