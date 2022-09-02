class Solution {
public:
   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
           return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        });
        
        vector<int>res;
        res.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>res.back()){
                res.push_back(envelopes[i][1]);
            }else{
                int idx=lower_bound(res.begin(),res.end(),envelopes[i][1])-res.begin();
                res[idx]=envelopes[i][1];
            }
        }
        return res.size();
        
        
        
        
        
    }
};