class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        string ans="",act;
        vector<string>st;
        stringstream ss(path);
        while(getline(ss,act,'/')){
           if(act==""||act=="."){
               continue;
           }else if(act==".." and !st.empty() )st.pop_back();
            else if(act!="..")st.push_back(act);
        }
        for(auto dir:st){
            ans+="/"+dir;
        }
        
        return ans.size()?ans:"/";
    }
};