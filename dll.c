#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert at the front
void insertFront(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

// Function to insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert after a given node
void insertAfter(struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }

    prev_node->next = new_node;
}

// Function to delete a node
void deleteNode(struct Node** head, struct Node* del_node) {
    if (*head == NULL || del_node == NULL) {
        return;
    }

    if (*head == del_node) {
        *head = del_node->next;
    }

    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }

    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }

    free(del_node);
}

// Function to print the DLL in forward direction
void traverseForward(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to print the DLL in backward direction
void traverseBackward(struct Node* node) {
    if (node == NULL) {
        return;
    }

    // Move to the last node
    while (node->next != NULL) {
        node = node->next;
    }

    // Traverse backward
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

// Function to search for a node
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to delete the entire DLL
void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
}

// Main function to demonstrate DLL operations
int main() {
    struct Node* head = NULL;

    // Insert elements
    insertFront(&head, 5);
    insertFront(&head, 10);
    insertEnd(&head, 15);
    insertEnd(&head, 20);

    // Print the list forward
    printf("Forward: ");
    traverseForward(head);

    // Print the list backward
    printf("Backward: ");
    traverseBackward(head);

    // Search for a node
    struct Node* found = search(head, 15);
    if (found != NULL) {
        printf("Found: %d\n", found->data);
    } else {
        printf("Not found\n");
    }

    // Delete a node
    deleteNode(&head, found);

    // Print after deletion
    printf("After deletion: ");
    traverseForward(head);

    // Delete the entire list
    deleteList(&head);

    return 0;
}