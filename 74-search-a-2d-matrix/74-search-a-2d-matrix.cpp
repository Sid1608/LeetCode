class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=n*m-1;
        while(l<=r){
            int mid=(l+r)/2;
            int row=mid/m;
            int col=mid%m;
            if(mat[row][col]==t){
                return true;
            }else if(mat[row][col]>t){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};