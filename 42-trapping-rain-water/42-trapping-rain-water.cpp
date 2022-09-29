class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0,l=0,r=n-1,lmax=-1,rmax=-1;
        while(l<r){
            
            if(height[l]<height[r]){
                lmax=max(lmax,height[l]);
                ans+=min(lmax,height[r])-height[l];
                l++;
            }else{
                rmax=max(rmax,height[r]);
                ans+=min(rmax,height[l])-height[r];
                r--;
            }
        }
        return ans;
    }
};