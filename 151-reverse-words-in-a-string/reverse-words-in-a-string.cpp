class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        int n= s.size();
        string str="";
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] != ' ')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty())
                {
                while(!st.empty())
                {
                    char a= st.top();
                    st.pop();
                    str.push_back(a);
                }
                str.push_back(' ');
            }
            }
        }
            while(!st.empty())
                {
                    char a= st.top();
                    st.pop();
                    str.push_back(a);
                }
                int m= str.size();
                if(str.size() >0 && str[m-1] == ' ')
                {
                    str.pop_back();
                }
                return str;
    }
};