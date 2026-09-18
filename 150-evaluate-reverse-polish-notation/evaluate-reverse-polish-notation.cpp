class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int t =-1;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*")
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int t = st.top();
                st.pop();
                
                if(tokens[i] == "+")
                {
                    t = t + st.top();
                    st.pop();
                }
                else if(tokens[i] == "-")
                {
                    t = st.top() - t;
                    st.pop();
                }
                else if(tokens[i] == "/")
                {
                    t = st.top() / t;
                    st.pop();
                }
                else 
                {
                    t = t * st.top();
                    st.pop();
                }
                st.push(t);
            }
        }
        return st.top();
    }
};