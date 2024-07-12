class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        if(x >= y) {
            ans += remove(s, x, "ab");
            ans += remove(s, y, "ba");
        }
        else {
            ans += remove(s, y, "ba");
            ans += remove(s, x, "ab");
        }

        return ans;
    }

    int remove(string& s, int point, string pattern) {
        int score = 0;
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(!st.empty() && st.top() == pattern[0] && c == pattern[1]) {
                st.pop();
                score += point;
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

        return score;
    }
};

// cdbcbbaaabab
// cdbc

// aabbaaxybbaabb
// aabaxybb
// aaxybb
