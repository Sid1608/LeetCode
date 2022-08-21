class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
       
        vector<int>adj[100001];
        unordered_set<int>st(restricted.begin(),restricted.end());
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int>vis(100001,0);
        queue<int>q;
        q.push(0);
        int ans=0;
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            ans++;
            q.pop();
            
            for(auto child:adj[node]){
                if(!vis[child] and st.find(child)==st.end()){
                    vis[child]=1;
                    q.push(child);
                }
            }
        }
        return ans;
    }
};