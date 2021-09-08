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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k==1)return head;
        int count = 1;
        ListNode* current = head;
        ListNode* prevNode = new ListNode(0);
        prevNode->next = head;
        ListNode* newHead = NULL;
        while(current){
            if(count == k){
                //current points to the last node of the revese
                ListNode* nextStart = current->next; //next start moves to the start of the next list
                ListNode* currentStart = prevNode->next; // current start from prevNode->next
                current->next = NULL;//making it NULL and reversing the currentStart
                ListNode* reversedHead = reverse(currentStart);
                if(!newHead)newHead = reversedHead;//no head store it we can use it to return
                prevNode->next = reversedHead;// prevNode connection to the newHead
                currentStart->next = nextStart; //currentStart->next to the nextStart
                current = nextStart; //current iterator to the nextStart
                prevNode = currentStart; // setting up the prevNode so that the start of the next list can be linked to the reversedHead
                count = 1;//re setting the count
            }
            current = (current)?current->next:NULL; // current can be NULL if nextStart is NULL so double checking
            count++; // incrementing the count
        }
        return newHead;
        
    }
 private:
    //reverse function
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;
        while(current){
            ListNode* after = current->next;
            current->next = prev;
            prev = current;
            current = after;
        }
        return prev;
    }
};