#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lru {
    int data;
    struct lru *next;
}lru;

void printLru(lru *head) {
    lru *p = head->next;
    while(p != NULL) {
        printf("%d\n",p->data);
        p = p->next;
    }
}

void freeLru(lru *head) {
    lru * tmp = NULL;
    while(head != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

int initLru(lru *head){
    for(int i=0; i<5; i++) {
        lru *tmp = (lru*) malloc(sizeof(lru));
        tmp->data = i;
        if(i ==0) {
            tmp->next = NULL;
        }else{
            tmp->next = head->next;
        }
        head->next = tmp;
    }
    return 0;
}

void lruSearch(lru *head, int target) {
    //命中缓存
    lru *p = head->next;
    lru *preP = head;
    while(p != NULL) {
        if(p->data == target) {
            lru *tmp = p->next;
            preP->next = tmp;
            p->next = head->next;
            head->next = p;
            return;
        }
        preP = p;
        p = p->next;
    }
    //没有命中缓存
    lru *newNode = (lru *)malloc(sizeof(lru));
    newNode->data = target;
    newNode->next = head->next;
    head->next = newNode;
}

int main(){
    lru *head = (lru*)malloc(sizeof(lru));
    head->data = -1;
    head->next = NULL;
    initLru(head);
    printLru(head);
    printf("lru search-------------\n");
    lruSearch(head, 3);
    printLru(head);
    freeLru(head);
    return 0;
}
