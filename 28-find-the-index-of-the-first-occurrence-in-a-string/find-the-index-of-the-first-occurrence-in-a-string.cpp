class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0;
        int res=-1;
        int n= haystack.size(); // j
        int m= needle.size();

        if(m > n)
        return -1;

        while(j < n)
        {
           
            if(needle[i] == haystack[j])
            {
                i++;
                j++;
                if(i==m)
                return j-m;
            }
            else
            {
                j=j-i+1;
                i=0;
            }
        }
        return -1;
    }
};