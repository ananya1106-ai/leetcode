class Solution {
public:
    bool checkString(string s) {
        bool found = false;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'b')
            found = true;
            if(s[i] == 'a' && found == true)
            return false;
        }
        return true;
    }
};