class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        int freq[26]={0};
        string ch="";
        unordered_map<int,int>last;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']==1){
                ch+=s[i];
            }
            last[s[i]]=i;
        }
        sort(ch.begin(),ch.end());
        int vis[10001]={0};
        int indx=-1;
        string ans="";
        while(ans.size()!=ch.size()){
            for(int i=0;i<ch.size();i++){
                if(vis[i]==0){
                    int isValid=1;
                    for(int k=indx+1;k<n;k++){
                        if(s[k]!=ch[i])
                            continue;
                        for(int j=0;j<ch.size();j++){
                            if(vis[j]==0 and last[ch[j]]<k){
                                isValid=0;
                                break;
                            }
                        }
                        if(isValid){
                            indx=k;
                        }
                        break;
                    }
                    if(isValid){
                        ans+=ch[i];
                        // cout<<ch[i]<<" "<<indx<<endl;
                        vis[i]=1;
                        break;
                    }
                    
                }
                
            }
        }
        return ans;
    
        
    }
};