class Solution {
public:
    string countOfAtoms(string formula) {
        vector<string> tokens;
        string token = "";
        tokens.push_back("(");
        // transfer the string into tokens
        for(int i = 0; i < formula.size(); i++) {
            token += formula[i];

            // the last char -> push
            if(i == formula.size() - 1) {
                tokens.push_back(token);
            }
            // ith: A-Z, (i+1)th: a-z -> same token
            else if('A' <= formula[i] && formula[i] <= 'Z' && 'a' <= formula[i + 1] && formula[i + 1] <= 'z') {
                
            }
            // ith: 0-9, (i+1)th: 0-9 -> same token
            else if('0' <= formula[i] && formula[i] <= '9' && '0' <= formula[i + 1] && formula[i + 1] <= '9') {

            }
            else {
                tokens.push_back(token);
                token = "";
            }
        }
        tokens.push_back(")");

        unordered_map<string, int> hash;
        stack<string> st;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == ")") {
                // check is the next token a number
                int count = 1;
                if(i != tokens.size() - 1 && '0' <= tokens[i + 1][0] && tokens[i + 1][0] <= '9') {
                    count = stoi(tokens[i + 1]);
                    i++;
                }

                stack<string> tmpTokens;
                while(st.top() != "(") {
                    for(int j = 0; j < count; j++) {
                        tmpTokens.push(st.top());
                    }
                    st.pop();
                }
                st.pop();

                while(!tmpTokens.empty()) {
                    st.push(tmpTokens.top());
                    tmpTokens.pop();
                }
            }
            else {
                // token i is a number
                if('0' <= tokens[i][0] && tokens[i][0] <= '9') {
                    for(int j = 1; j < stoi(tokens[i]); j++) {
                        st.push(st.top());
                    }
                }
                else {
                    st.push(tokens[i]);
                }
            }
        }

        while(!st.empty()) {
            hash[st.top()]++;
            st.pop();
        }

        vector<pair<string, int>> pairs;
        for(auto e : hash) {
            pairs.push_back({e.first, e.second});
        }

        sort(pairs.begin(), pairs.end());

        string ans = "";
        for(int i = 0; i < pairs.size(); i++) {
            ans += pairs[i].first;
            if(pairs[i].second > 1) {
                ans += to_string(pairs[i].second);
            }
        }

        return ans;
    }
};

// Mg(OH)2 -> Mg, (, O, H, ), 2
// MgOHOH

// K4(ON(SO3)2)2 -> K 4 ( O N ( S O 3 ) 2 ) 2