class Solution {
public:
    vector<string> revisions(string version,int n){
        int i=0;
        string s="";
         vector<string>a;
        while(i<n){
            if(version[i]=='.'){
                if(s.size()==0)s+='0';
                a.push_back(s);
                s="";
                i++;
            }else{
                if(version[i]=='0'){
                    if(s.size())
                        s+='0';
                }else{
                    s+=version[i];
                }
                i++;
            }
        }
        if(s.size() and s!="0"){
            a.push_back(s);
        }
        return a;
    }
    int compareVersion(string version1, string version2) {
        vector<string>a,b;
        a=revisions(version1,version1.size());
        b=revisions(version2,version2.size());
        int n=a.size();
        int m=b.size();
        int i=0,j=0;
        while(i<n and j<m){
            cout<<a[i]<<" "<<b[j]<<" ";
            int x=stoi(a[i]);
            int y=stoi(b[j]);
            if(x>y){
                return 1;
            }else if(x<y){
                return -1;
            }else{
                i++;j++;
            }
        }
        while(i<n){
            if(a[i]!="0")
                return 1;
            i++;
        }
        while(j<m){
            // cout<<"d";
            if(b[j]!="0")
                return -1;
            j++;
        }
        return 0;
        
        
    }
};