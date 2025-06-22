/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* before = dummy;
    struct ListNode* after = head;
    struct ListNode* curr = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* nxt = NULL;

    while(true){
        struct ListNode* cursor = after;
        for(int i = 0; i < k; i++){
            if(cursor == NULL) return dummy->next;
            cursor = cursor->next;
        }

        curr = after;
        prev = before;

        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        after->next = curr;
        before->next = prev;
        before = after;
        after = curr;
    }
}
