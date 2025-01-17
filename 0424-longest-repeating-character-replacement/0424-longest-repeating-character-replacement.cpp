class Solution {
public:
    bool check(string& s,int k){
        unordered_map<char,int>mp;
        for(auto a:s)mp[a]++;
        int n=s.size();
        for(auto a:mp){
            int other=n-a.second;
            if(other<=k) return true;
        }
        return false;
    }
    int bruteforce(string &s, int k) {
        int n=s.size();
        int res=k;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=i;j<n;j++){
                str+=s[j];
                if(str.size()>k) {
                    if(check(str,k)){
                        res=max(res,int(str.size()));
                    }
                }
            }
        }
        return res;
    }
    //Solution 2
    int getMaxFrequency(unordered_map<char,int>mp){
        int res=0;
        for(auto a:mp){
            res=max(res,a.second);
        }
        return res;
    }
    int better(string& s,int k){
        unordered_map<char,int>mp;
        int n=s.size();
        int res=k;
        for(int i=0,j=0;j<n;j++){
            mp[s[j]]++;
            if((j-i+1) - getMaxFrequency(mp) <=k){
                res=max(res,(j-i+1));
            }
            else{
                while(i<j and ((j-i+1) - getMaxFrequency(mp)) > k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0 ) mp.erase(s[i]);
                    i++;
                }
                if((j-i+1) - getMaxFrequency(mp) <=k){
                    res=max(res,(j-i+1));
                }
            }
        }
        return res;
    }

    //optimal Solution 3
    
    int optimal(string& s,int k){
        int n=s.size();
        unordered_map<char,int>mp;
        int res=k,maxFreq=0;

        for(int i=0,j=0;j<n;j++){
            mp[s[j]]++;
            
            if(mp[s[j]]>maxFreq){
                maxFreq=mp[s[j]];
            }
            if((j-i+1) - maxFreq <= k){
                res=max(res,(j-i+1));
            }
            else{
                while(i<j and ((j-i+1) - maxFreq) > k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    if(mp[s[i]]>maxFreq){
                        maxFreq=mp[s[i]];
                    }
                    i++;
                }
                if((j-i+1) - maxFreq <=k){
                    res=max(res,(j-i+1));
                }
            }
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        // return bruteforce(s,k); //O(n^2 * 26) time space O(N)
        
        // return better(s,k); //O(n * 26) time space O(26)


        return optimal(s,k); //O(n) time space O(26)
    }
};