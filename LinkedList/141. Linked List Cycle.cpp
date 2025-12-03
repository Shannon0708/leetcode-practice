using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {};
        ListNode(int x) : val(x), next(nullptr) {};
        ListNode(int x, ListNode* next) : val(x), next(next) {};
    };

    bool hasCycle(ListNode *head) {
        // pos is like the index of an array
        // if pos exist return true
        // if pos < 0 return false

        if(!head || !head -> next) return false;

        ListNode *fast = head -> next;
        ListNode *slow = head;
    
        while(fast && (fast -> next)) {
            if(slow != fast) {
                slow = slow->next;
                fast = fast->next->next;
            } 
            else {
                return true;
            }
        }
        

        return false;

    }
};