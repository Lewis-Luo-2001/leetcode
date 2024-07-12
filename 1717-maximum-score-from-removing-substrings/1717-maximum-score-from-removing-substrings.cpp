class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(c == 'a' && !st.empty() && st.top() == 'b') {
                st.pop();
                ans += max(x, y);
            }
            else {
                st.push(c);
            }
        }

        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(c == 'b' && !st.empty() && st.top() == 'a') {
                st.pop();
                ans += min(x, y);
            }
            else {
                st.push(c);
            }
        }

        return ans;
    }
};

// cdbcbbaaabab
// cdbc

// aabbaaxybbaabb
// aabaxybb
// aaxybb