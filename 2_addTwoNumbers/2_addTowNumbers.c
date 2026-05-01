#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head1 = l1;
    struct ListNode* head2 = l2;
    struct ListNode* result = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* headResult = result;

    int carry = 0;
    int digitSum = 0;
    while (headResult != NULL)  {
        digitSum = carry;
        if (head1 != NULL) {
            digitSum += head1->val;
        }
        if (head2 != NULL) {
            digitSum += head2->val;
        }
        carry = digitSum / 10;
        digitSum = digitSum % 10;

        headResult->val = digitSum;
        if (head1 != NULL) head1 = head1->next;
        if (head2 != NULL) head2 = head2->next;

        if (head1 != NULL | head2 != NULL | carry > 0)   {
            headResult->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        }
        else {
            headResult->next = NULL;
        }
        headResult = headResult->next;
    }

    return result;
}

struct ListNode* makeList(int* vals, int len) {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;
    for (int i = 0; i < len; i++) {
        cur->val = vals[i];
        cur->next = (i < len - 1) ? malloc(sizeof(struct ListNode)) : NULL;
        cur = cur->next;
    }
    return head;
}

void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d", node->val);
        if (node->next != NULL) printf("->");
        node = node->next;
    }
    printf("\n");
}

int main(void) {
    int v1[] = {2, 4, 3}, v2[] = {5, 6, 4};
    printf("Input: [2->4->3] + [5->6->4] -> ");
    printList(addTwoNumbers(makeList(v1, 3), makeList(v2, 3)));

    int v3[] = {0}, v4[] = {0};
    printf("Input: [0] + [0]             -> ");
    printList(addTwoNumbers(makeList(v3, 1), makeList(v4, 1)));

    int v5[] = {9,9,9,9,9,9,9}, v6[] = {9,9,9,9};
    printf("Input: [9x7] + [9x4]         -> ");
    printList(addTwoNumbers(makeList(v5, 7), makeList(v6, 4)));

    return 0;
}
