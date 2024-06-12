class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int i=0; i<nums.size(); ++i) ++count[nums[i]];
        for(int i=0; i<count[0]; ++i) nums[i] = 0;
        for(int i=count[0]; i<count[0] + count[1]; ++i) nums[i] = 1;
        for(int i=count[0] + count[1]; i<count[0] + count[1] + count[2]; ++i) nums[i] = 2;
    }
};