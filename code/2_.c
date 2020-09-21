#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l, *a, *b, *temp;
    // l - 结果链表
    // a - 指示l1
    // b - 指示l2
    // temp - 作为链表temp
    // iflag - 指示下一位是否进1
    int iflag = 0;
    a = l1;
    b = l2;
    // 带头节点
    l = malloc(sizeof(struct ListNode));
    temp = l;
    while ((a != NULL || b != NULL || iflag != 0)) {
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;

        if (a != NULL && b != NULL){
            temp->val = (a->val + b->val) % 10;
            if (temp->val < 9) {
                temp->val += iflag;
                if (a->val + b->val > 9) {
                    iflag = 1;
                }
                else {
                    iflag = 0;
                }
            }
            else if (temp->val == 9 && iflag == 1) {
                temp->val = 0;
                iflag = 1;
            }
            a = a->next;
            b = b->next;
        }
        else if (a != NULL) {
            if (a->val == 9 && iflag == 1) {
                temp->val = 0;
                iflag = 1;
            } else {
                temp->val = a->val + iflag;
                iflag = 0;
            }
            a = a->next;
        }
        else if (b != NULL) {
            if (b->val == 9 && iflag == 1) {
                temp->val = 0;
                iflag = 1;
            } else {
                temp->val = b->val + iflag;
                iflag = 0;
            }
            b = b->next;
        }
        else if (iflag == 1) {
            temp->val = iflag;
            iflag = 0;
        }

        temp->next = NULL;
    }
    temp = l;
    l = l->next;
    free(temp);
    return l;
}

void travelList(struct ListNode* l) {
    struct ListNode* temp;
    temp = l;
    while (temp != NULL) {
        printf("%d\t", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    struct ListNode *l1, *l2, *temp;
//    l1 = malloc(sizeof(struct ListNode));
//    temp = l1;
//    temp->val = 5;
//    temp->next = malloc(sizeof(struct ListNode));
//    temp = temp->next;
//    temp->val = 5;
//    temp->next = malloc(sizeof(struct ListNode));
//    temp = temp->next;
//    temp->val = 5;
//    temp->next = NULL;
//
//    l2 = malloc(sizeof(struct ListNode));
//    temp = l2;
//    temp->val = 5;
//    temp->next = malloc(sizeof(struct ListNode));
//    temp = temp->next;
//    temp->val = 5;
//    temp->next = malloc(sizeof(struct ListNode));
//    temp = temp->next;
//    temp->val = 5;
//    temp->next = NULL;

    l1 = malloc(sizeof(struct ListNode));
    temp = l1;
    temp->val = 1;
    temp->next = NULL;

    l2 = malloc(sizeof(struct ListNode));
    temp = l2;
    temp->val = 9;
    temp->next = malloc(sizeof(struct ListNode));
    temp = temp->next;
    temp->val = 9;
    temp->next = NULL;

    travelList(l1);
    travelList(l2);
    travelList(addTwoNumbers(l1, l2));

    return 0;
}