class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        if(m != n)
        return false;
        else
        {
            for(int i=0;i<n;i++)
            {
                mp1[s[i]]++;
            }
            for(int i=0;i<m;i++)
            {
                mp2[t[i]]++;
            }
        }
        if(mp1 == mp2)
        return true;
        else
        return false;
        
    }
};