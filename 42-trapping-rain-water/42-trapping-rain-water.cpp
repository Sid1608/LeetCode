class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lheight(n,0),rheight(n,0);
        int h=0;
        for(int i=0;i<n;i++){
            h=max(h,height[i]);
            lheight[i]=h;
        }
        h=0;
        for(int i=n-1;i>=0;i--){
            h=max(h,height[i]);
            rheight[i]=h;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int l=lheight[i];
            int r=rheight[i];
            ans+=(min(l,r)-height[i]);
        }
        return ans;
    }
};