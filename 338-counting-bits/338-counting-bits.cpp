class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int cnt=0;
            for(int j=0;j<18;j++){
                int f=1<<j;
                if((f & i)!=0)
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};