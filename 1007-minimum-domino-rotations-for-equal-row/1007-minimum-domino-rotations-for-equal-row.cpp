class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int mini=INT_MAX;
        for(int i=1;i<=6;i++){
            int j;
            int swaps=0;
            for(j=0;j<n;j++){
                if(tops[j]!=i ){
                    if(bottoms[j]!=i)
                        break;
                    else
                        swaps++;
                }
            }
            if(j==n){
                mini=min(mini,swaps);
            }
        }
        for(int i=1;i<=6;i++){
            int j;
            int swaps=0;
            for(j=0;j<n;j++){
                if(bottoms[j]!=i ){
                    if(tops[j]!=i)
                        break;
                    else
                        swaps++;
                }
            }
            if(j==n){
                mini=min(mini,swaps);
            }
        }
        if(mini==INT_MAX)return -1;
        return mini;
        
    }
};