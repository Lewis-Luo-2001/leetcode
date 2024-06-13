class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0;

        for(int i = 0; i < seats.size(); i++) {
            ans += abs(students[i] - seats[i]);
        }

        return ans;
    }
};

// 1 3 5
// 2 4 7

// 2 2 6 6 
// 1 2 3 6