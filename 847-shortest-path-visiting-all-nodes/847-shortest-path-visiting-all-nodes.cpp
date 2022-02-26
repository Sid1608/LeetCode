class Solution {
public:
   
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)
            return 0;
        
        //node,mask,dist
        queue<tuple<int,int,int>>q;
        //mask,node
        set<pair<int,int>>vis;
        for(int i=0;i<n;i++){
            q.push({i,1<<i,0});
            
            vis.insert({1<<i,i});
        }
        int endMask=(1<<n)-1;//denotes all  nodes  are visited.
        while(!q.empty()){
            tuple<int,int,int>curr=q.front();
            q.pop();
            int node=get<0>(curr);
            int mask=get<1>(curr);
            int dist=get<2>(curr);
            if(mask==endMask){
                return dist;
            }
            for(int child: graph[node]){
                //making the bit at child position set to ensure it is visited
                int newMask=(1<<child)|mask;
                
                //it will ensure that we don't revisit states
                if(vis.find({newMask,child})== vis.end()){
                    q.push({child,newMask,dist+1});
                    vis.insert({newMask,child});
                }
            }
        }
        return 0;
    }
};