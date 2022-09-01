class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec;
        vec.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>vec.back()){
                vec.push_back(nums[i]);
            }else{
                int idx=lower_bound(vec.begin(),vec.end(),nums[i])-vec.begin();
                vec[idx]=nums[i];
            }
        }
        return vec.size();
    }
};