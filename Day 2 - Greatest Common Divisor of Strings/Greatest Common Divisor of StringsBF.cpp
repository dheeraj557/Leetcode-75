class Solution {
public:
    bool isvalid(string str1,string str2,string base,int len1,int len2,int len3){
        if(len2%len3!=0 or len1%len3!=0)
        {
            return false;
        }
        int q1 = len1/len3;
        int q2 = len2/len3;
        if(str1==joinwords(base,q1) and (str2==joinwords(base,q2)))
        {
            return true;
        }
        return false;
    }
    string joinwords(string str,int k)
    {
        string ans="";
        for(int i=0;i<k;i++)
        {
            ans+=str;
        }
        return ans;
    }
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size(),len2=str2.size();
        for(int i=min(len1,len2);i>0;i--)
        {
            string base = str1.substr(0,i);
            if(isvalid(str1,str2,base,len1,len2,i))
            {
                return base;
            }
        }
        return "";
    }
};