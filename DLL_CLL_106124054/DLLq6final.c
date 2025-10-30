//6> LRU Cache Implementation 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int val;
    struct Node *next;
} node;

node *createNode(int key, int val) {
	node *ret = (node *) malloc(sizeof(node));
	ret->key = key;
    ret->val = val;
	ret->next = NULL;
	return ret;
}

node *LRUCache(int n) {
	node *head = NULL, *cur;
	int k = n+1;
	while (--k) {
		node *new = createNode(-1, -1);
		if (head == NULL) {
			head = new;
			cur = head;
			continue;
		}
		cur->next = new;
		cur = new;
	}
	cur->next = NULL;
	return head;
}

int get(node *head, int key) {
    node *cur = head, *prev = NULL;
    while (cur != NULL) {
        if (cur->key == key) {
            return cur->val;
        }
        cur = cur->next;
    }
    return -1;
}

node *put(node *head, int key, int val) {
    node *cur = head, *prev = NULL;
    while (cur->next != NULL) {
        if (cur->key == key) {
            cur->val = val;
            return cur;
        }
        prev = cur;
        cur = cur->next;
    }
    if (cur->key == key) {
        cur->val = val;
        return cur;
    }
    node *new = createNode(key, val);
    new->next = head;
    prev->next = NULL;
    free(cur);
    return new;
}

void showCache(node *head) {
	node *cur = head;
    printf("LRU Cache[ ");
	while (cur != NULL) {
		printf("%d ",cur->key);
		cur = cur->next;
	}
    printf("]\n");
}

int main() {
    node *cache = LRUCache(2);
    showCache(cache);
    cache = put(cache, 1, 1);
    showCache(cache);
    cache = put(cache, 2, 2);
    showCache(cache);
    printf("Get 1: %d\n", get(cache, 1));
    cache = put(cache, 3, 3);
    showCache(cache);
    printf("Get 2: %d\n", get(cache, 2));
    cache = put(cache, 4, 4);
    showCache(cache);
    printf("Get 1: %d\n", get(cache, 1));
    printf("Get 3: %d\n", get(cache, 3));
    printf("Get 4: %d\n", get(cache, 4));    

    return 0;
}

/*
Input and Output:
LRU Cache[ -1 -1 ]
LRU Cache[ 1 -1 ]
LRU Cache[ 2 1 ]
Get 1: 1
LRU Cache[ 3 2 ]
Get 2: 2
LRU Cache[ 4 3 ]
Get 1: -1
Get 3: 3
Get 4: 4
*/