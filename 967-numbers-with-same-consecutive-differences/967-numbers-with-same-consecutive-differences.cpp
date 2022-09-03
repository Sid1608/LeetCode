class Solution {
public:
    void solve(int idx,int n,int k,string temp,vector<int>&res){
        if(idx==n){
            int ans=stoi(temp);
            res.push_back(ans);
            return;
        }
        
        for(int i=0;i<=9;i++){
            if(idx==0){
                if(i!=0){
                    temp+=to_string(i);
                    solve(idx+1,n,k,temp,res);
                    temp.pop_back();
                }
            }else{
                int prev=temp[idx-1]-'0';
                if(abs(i-prev)==k){
                    temp+=to_string(i);
                    solve(idx+1,n,k,temp,res);
                    temp.pop_back();
                }
            }
            
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        string temp="";
        solve(0,n,k,temp,res);
        return res;
    }
};