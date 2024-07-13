class Solution {
private:
    typedef struct Robot {
        int position;
        int id;
        int health;
        int direction;

        Robot(int id_, int position_, int health_, int direction_) {
            id = id_, position = position_, health = health_, direction = direction_;
        }
    } Robot;

    static bool cmp(const Robot& r1, const Robot& r2) {
        return r1.position <= r2.position;
    }

    static bool cmp2(const Robot& r1, const Robot& r2) {
        return r1.id <= r2.id;
    }
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int N = positions.size();
        
        vector<int> ans;
        vector<Robot> robots;

        for(int i = 0; i < N; i++) {
            int dir = (directions[i] == 'L') ? 0 : 1;
            robots.push_back(Robot(i + 1, positions[i], healths[i], directions[i]));
        }

        sort(robots.begin(), robots.end(), cmp);

        stack<Robot> st;
        for(int i = 0; i < N; i++) {
            if(st.empty()) {
                st.push(robots[i]);
            }
            else {
                bool push = true;
                while(!st.empty() && st.top().direction == 'R' && robots[i].direction == 'L' && push) {
                    if(st.top().health > robots[i].health) {
                        st.top().health--;
                        push = false;
                    }
                    else if(st.top().health == robots[i].health) {
                        st.pop();
                        push = false;
                    }
                    else if(st.top().health < robots[i].health) {
                        st.pop();
                        robots[i].health--;
                    }
                }
                if(push) st.push(robots[i]);
            }
        }

        vector<Robot> tmp;
        while(!st.empty()) {
            tmp.push_back(st.top());
            st.pop();
        }

        sort(tmp.begin(), tmp.end(), cmp2);

        for(int i = 0; i < tmp.size(); i++) {
            ans.push_back(tmp[i].health);
        }

        return ans;
    }
};

// positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
// positions = [2,3,5,6], healths = [15,10,10,12], directions = "RRLL"
// stack: R, RR, R(RL), R, (RL)

// 6 14 17 31 44
// 5 27 9  9  34
// R L  R  L  R
// LR