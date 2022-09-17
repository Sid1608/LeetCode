class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        multiset<int>mt;
        for(auto i:t){
            mt.insert(i);
        }
        int ans=0;
        for(auto i:p){
            auto it=mt.lower_bound(i);
            if(it!=mt.end()){
                ans++;
                mt.erase(it);
            }
        }
        return ans;
    }
};