class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        unordered_map<int,int>mp;
        int rem[1001]={0};
        for(int i=0;i<n;i++)mp[pushed[i]]=i;
        for(int i=0;i<n;i++){
            int num=popped[i];
            int idx=mp[num];
            if(rem[idx]==1){
                cout<<i<<" "<<idx;
                return false;
            }
            //checkign wheather theres is gap
            int gap=1;
            for(int j=idx+1;j<n;j++){
                if(rem[j]==0){
                    gap=0;
                }else if(rem[j]==1){
                    if(gap==0){
                        cout<<i<<" "<<j;
                        return false;
                    }
                    
                }
            }
            rem[idx]=1;
            
        }
        return true;
        
    }
};