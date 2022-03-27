
class Solution {
public:
   
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>vec;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            vec.push_back({cnt,i});
        }
        sort(vec.begin(),vec.end(), [](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            if(a.first>b.first){
                return false;
            }
            return true;
    });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};