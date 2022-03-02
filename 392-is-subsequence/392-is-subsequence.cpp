class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int pos=0;
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=pos;j<m;j++){
                if(t[j]==s[i]){
                    pos=j+1;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                return false;
        }
        return true;
    }
};