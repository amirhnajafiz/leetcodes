/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size = 0;
    struct ListNode* current = head;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    if (size == 0)
        return NULL;
    if (size == 1 && n == 1)
        return NULL;

    int place = size - n - 1;
    if (place == -1)
        return head->next;

    current = head;
    for (int i = 0; i < place; i++)
        current = current->next;
    
    if (current->next != NULL)
        current->next = current->next->next;

    return head;
}
