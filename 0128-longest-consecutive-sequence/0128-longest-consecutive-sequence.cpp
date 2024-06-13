class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums)); // inserting all elements into hashset
        int longest = 0;
        for(auto& num : s) {
            int current_longest = 1;
            for(int i=1; s.count(num-i); ++i){
                s.erase(num-i);
                ++current_longest;
            }
            for(int i=1; s.count(num+i); ++i){
                s.erase(num+i);
                ++current_longest;
            }
            longest = max(longest, current_longest);
        }
        return longest;
    }
};