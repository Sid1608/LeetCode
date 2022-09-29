class Solution {
public:
    string pushDominoes(string s) {
        int n=s.size();
        set<int>st;
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                st.insert(i);
            }
        }
        if(st.size()==0)return s;
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                auto it=st.lower_bound(i);
                int r,l;
                if(it==st.end()){
                    it--;
                    l=*it;
                    if(s[l]=='R'){
                        s[i]='R';
                    }
                }else{
                    r=*it;
                    if(it!=st.begin()){
                        it--;
                        l=*it;
                        if(s[l]=='R' and s[r]=='R'){
                            s[i]='R';
                        }else if(s[l]=='L' and s[r]=='L'){
                            s[i]='L';
                        }else if(s[l]=='R' and s[r]=='L'){
                            if(i-l>r-i){
                                s[i]='L';
                            }else if(i-l<r-i){
                                s[i]='R';
                            }
                        }
                    }else{
                        if(s[r]=='L'){
                            s[i]='L';
                        }
                    }
                }
            }
        }
        return s;
    }
};