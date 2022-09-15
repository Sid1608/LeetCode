class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        int n=changed.size();
        if(n&1){
            return ans;
        }
        // sort(changed.begin(),changed.end());
        multiset<int>mst;
        for(auto c:changed){
            mst.insert(c);
        }
        int m=n/2;
        while(m--){
            auto it=mst.begin();
            int t=2*(*it);
            mst.erase(mst.begin());
            if(!mst.empty() and mst.find(t)!=mst.end()){
                ans.push_back(t/2);
                mst.erase(mst.lower_bound(t));
                
            }else{
                return {};
            }
        }
        return ans;
        
    }
};