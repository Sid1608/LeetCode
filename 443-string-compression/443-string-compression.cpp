class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,cnt=0,pos=0;
        while(i<n){
            int freq=0;
            char currChar=chars[i];
            while(i<n and chars[i]==currChar){
                i++;
                freq++;
            }
            if(freq>1){
                cnt++;
                chars[pos++]=currChar;
                string tmp=to_string(freq);
                for(int j=0;j<tmp.size();j++){
                    cnt++;
                    char y=tmp[j];
                    chars[pos++]=y;
                }
            }else{
                cnt++;
                chars[pos++]=currChar;
            } 
        }
        return cnt;
    }

};