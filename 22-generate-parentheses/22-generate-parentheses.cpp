class Solution {
public:
    void solve(int n,int open,int closed,vector<string>&res,string s){
        
        if(s.size()==2*n){
            res.push_back(s);
            return ;
        }
        if(open<n){
            
            solve(n,open+1,closed,res,s+"(");
        }
        
        if(open>closed){
            solve(n,open,closed+1,res,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s="";
        solve(n,0,0,res,s);
        return res;
    }
};