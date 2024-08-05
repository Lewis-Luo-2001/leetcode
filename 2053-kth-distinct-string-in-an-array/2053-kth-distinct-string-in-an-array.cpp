class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        const int N = arr.size();
        
        unordered_map<string, int> count;

        for(int i = 0; i < N; i++) {
            count[arr[i]]++;
        }

        for(int i = 0; i < N; i++) {
            if(count[arr[i]] == 1) {
                k--;
            }

            if(k == 0) {
                return arr[i];
            }
        }

        return "";
    }
};