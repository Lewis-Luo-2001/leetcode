/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        int pre = INT_MIN;

        ListNode *cur = head;
        vector<int> criticals;
        for(int i = 0; cur -> next; i++, cur = cur -> next) {
            // local maxima
            if(cur -> val > max(pre, cur -> next -> val) && pre != INT_MIN) {
                criticals.push_back(i);
            }

            //local minima
            else if(cur -> val < min(pre, cur -> next -> val) && pre != INT_MIN) {
                criticals.push_back(i);
            }
            
            pre = cur -> val;
        }

        if(criticals.size() < 2) return {-1, -1};

        int minDistance = INT_MAX, maxDistance;
        for(int i = 0; i < criticals.size() - 1; i++) {
            minDistance = min(minDistance, criticals[i + 1] - criticals[i]);
        }
        maxDistance = criticals[criticals.size() - 1] - criticals[0];

        return {minDistance, maxDistance};
    }
};