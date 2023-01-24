#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *head = NULL;

void mark_and_sweep() {
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL) {
        if (current->marked) {
            previous = current;
            current = current->next;
        } else {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            current = previous->next;
        }
    }
}

int main() {
    Node *node1 = (Node *) malloc(sizeof(Node));
    node1->value = 1;
    node1->next = NULL;
    node1->marked = 0;
    head = node1;
    
    Node *node2 = (Node *) malloc(sizeof(Node));
    node2->value = 2;
    node2->next = NULL;
    node2->marked = 0;
    node1->next = node2;
    
    mark_and_sweep();
    return 0;
}
