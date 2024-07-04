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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head;
        vector<int> nums;
        int sum = 0;

        while(cur) {
            if(cur -> val == 0) {
                if(cur != head) {
                    nums.push_back(sum);
                }
                sum = 0;
            }
            else sum += cur -> val;

            cur = cur -> next;
        }

        ListNode* ans = nullptr;

        for(int n : nums) {
            if(ans == nullptr) {
                ans = new ListNode(n);
                cur = ans;
            }
            else {
                cur -> next = new ListNode(n);
                cur = cur -> next;
            }
        }

        return ans;

    }
};