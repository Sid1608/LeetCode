class Solution {
public:
    bool solve(int idx,string n){
        if(idx>=n.size()){
            int num=stoi(n);
            if(n[0]=='0')return false;
            cout<<num<<" ";
            if((num & (num-1))==0){
                return true;
            }
            return false;
        }
        for(int i=idx;i<n.size();i++){
            swap(n[i],n[idx]);
            if(solve(i+1,n))return true;
            swap(n[i],n[idx]);
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        //16->2^4
        //8->2^3
        //32->2^5
        //256->2^
        // string s=to_string(n);
        // return solve(0,s);
        for(int i=0;i<=30;i++){
            int num=1<<i;
            string s=to_string(num);
            string r=to_string(n);
            sort(s.begin(),s.end());
            sort(r.begin(),r.end());
            if(s==r)
                return true;
        }
        return false;
    }
};

