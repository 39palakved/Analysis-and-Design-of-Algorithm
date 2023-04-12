 #include<stdlib.h>
 
 struct ListNode {
    int data;
    struct ListNode* next;
};
 struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}
 struct ListNode* mergeSort(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* right = mergeSort(slow->next);
    slow->next = NULL;
    struct ListNode* left = mergeSort(head);
    return merge(left, right);
}
 int main() {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->data = 3;
    head->next = malloc(sizeof(struct ListNode));
    head->next->data = 1;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->data = 2;
    head->next->next->next = NULL;
    head = mergeSort(head);
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}