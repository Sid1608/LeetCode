class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n=stations.size();
        priority_queue<int>pq;
        int i=0;
        int res=0;
        for(res=0;startFuel<target;res++){
            while(i<n and stations[i][0]<=startFuel){
                pq.push(stations[i++][1]);
            }
            if(pq.empty())return -1;
            startFuel+=pq.top();
            pq.pop();
        }
        return res;
      
        
        
    }
};