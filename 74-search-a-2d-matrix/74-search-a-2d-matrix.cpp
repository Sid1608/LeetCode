//time complexity: o(logn+logm)
//space compleity: o(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=n-1,desired_row=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(mat[mid][0]==t){
                return true;
            }
            else if(mat[mid][0]>t){
                r=mid-1;
            }else{
                desired_row=mid;
                l=mid+1;
            }
            
        }
        if(desired_row==-1)
            return false;
        l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(mat[desired_row][mid]==t){
                return true;
            }
            else if(mat[desired_row][mid]>t){
                r=mid-1;
            }else{
            
                l=mid+1;
            }
            
        }
        return false;
    
    }
};