class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        
        for(string s : logs) {
            if(s == "../") {
                step = max(0, step - 1);
            }
            else if(s == "./") {

            }
            else {
                step++;
            }
        }

        return step;
    }
};