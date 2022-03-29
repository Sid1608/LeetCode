class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n=a.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int x=abs(a[i]);
            if(a[x]<0){
                ans=x;
                break;
            }
            a[x]*=-1;
        }
        return ans;
    }
};