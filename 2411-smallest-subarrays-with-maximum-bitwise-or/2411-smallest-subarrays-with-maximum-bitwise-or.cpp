class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>bit(32,-1);
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<32;j++){
                int f=1<<j;
                if(nums[i]&f){
                    bit[j]=i;
                }
            }
            int j=i;
            for(int i=0;i<32;i++){
                j=max(j,bit[i]);
            }
            ans.push_back(j-i+1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};