class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(operations[i] != "C" && operations[i] != "D" && operations[i] !="+")
            {
                st.push(stoi(operations[i]));
            }
            else
            {
                if(operations[i] == "C")
                {
                    st.pop();
                }
                else if(operations[i] == "D")
                {
                    st.push(2 * st.top());
                }
                else 
                {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    int sum = a+b;
                    st.push(b);
                    st.push(a);
                    st.push(sum);
                }
            }
        }
        int ans = 0;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};