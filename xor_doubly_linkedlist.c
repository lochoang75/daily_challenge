#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *both;
};

int add(struct Node *head, int data) {
    struct Node *pCurr = head;
    struct Node *pPrev = 0;
    struct Node *pTemp = head;
    while (pCurr->both != NULL) {
        pTemp = (long)pCurr->both ^ (long)pPrev;
        pPrev = pCurr;
        pCurr = pTemp;
    }
    pTemp = malloc(sizeof(struct Node));
    pTemp->data = data;
    pTemp->both = NULL;
    pCurr->both = (long)pPrev ^ (long)pTemp;
}

void print_list(struct Node *head) {
    struct Node *pCurr = head;
    struct Node *pPrev = 0;
    struct Node *pTemp = head;
    while (pCurr != NULL) {
        printf("%d -> ", pCurr->data);
        if (pCurr->both != NULL){
            pTemp = (long)pCurr->both ^ (long)pPrev;
            pPrev = pCurr;
            pCurr = pTemp;
        }else {
            pCurr = pCurr->both;
        }
    }
}

void free_list(struct Node *head) {
    struct Node *pCurr = head;
    struct Node *pPrev = 0;
    struct Node *pTemp = head;
    while (pCurr != NULL) {
        if (pCurr->both != NULL){
            pTemp = (long)pCurr->both ^ (long)pPrev;
            pPrev = pCurr;
            free(pCurr);
            pCurr = pTemp;
        }else {
            free(pCurr);
            pCurr = NULL;
        }
    }
}

struct Node* get(struct Node* head, int index) {
    struct Node *pCurr = head;
    struct Node *pPrev = 0;
    struct Node *pTemp = head;
    for (int i = 0; i < index; i++) {
        if (pCurr == NULL) {
            return NULL;
        }
        pTemp = (long)pCurr->both ^ (long)pPrev;
        pPrev = pCurr;
        pCurr = pTemp;
    }
    return pCurr;
}

int main(int argc, char*argv[]) {
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 0;
    head->both = NULL;
    add(head, 10);
    add(head, 100);
    add(head, 1000);
    print_list(head);
    struct Node* get_node = NULL;
    get_node = get(head, 0);
    printf("\r\nget 0 %d\r\n", get_node->data);
    get_node = get(head, 1);
    printf("get 1 %d\r\n", get_node->data);
    get_node = get(head, 2);
    printf("get 2 %d\r\n", get_node->data);
    get_node = get(head, 3);
    printf("get 3 %d\r\n", get_node->data);
    free_list(head);
    return 0;
}
