class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict;

        for(string s : dictionary) {
            dict.insert(s);
        }

        string ans = "", tmp = "";
        for(int i = 0; i < sentence.size(); i++) {
            tmp += sentence[i];
            if(sentence[i] == ' ' || (i + 1) == sentence.size()) {
                ans += tmp;
                tmp = "";
            }

            if(dict.count(tmp) != 0) {
                ans += tmp + " ";
                tmp = "";
                while(sentence[i] != ' ' && i < sentence.size()) i++;
            }
        }

        if(ans[ans.size() - 1] == ' ') ans = ans.substr(0, ans.size() - 1);

        return ans;
    }
};