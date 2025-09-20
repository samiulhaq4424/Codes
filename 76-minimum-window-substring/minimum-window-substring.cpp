class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0;
        int n=s.size();
        int miniLen=INT_MAX, startIndx=-1;
        unordered_map<char,int> mp;

        for(auto it : t){
            mp[it]++;
        }
        int count = mp.size();

        while(j<n) {
            if(mp.find(s[j]) != mp.end()){
                --mp[s[j]];
                if(mp[s[j]] == 0){
                    --count;
                }
            }
            if(count>0){
                ++j;
            }
            else if(count == 0){
                while(count == 0){
                    if(j-i+1 < miniLen){
                        startIndx = i;
                        miniLen = j-i+1;
                    }
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            ++count;
                        }
                    }
                    ++i;
                }
                ++j;
            }
        }
        if(startIndx == -1){
            return "";
        }
        else{
            return s.substr(startIndx,miniLen);
        }
    }
};