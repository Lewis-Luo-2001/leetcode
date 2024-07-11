class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')') {
                string tmp = "";
                while(st.top() != '(') {
                    tmp += st.top();
                    st.pop();
                }
                st.pop();

                for(int j = 0; j < tmp.size(); j++) {
                    st.push(tmp[j]);
                }
            }
            else {
                st.push(s[i]);
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
