#include <stdio.h>
#include <stdlib.h>

// Do not edit this struct. You may use it exactly as
// it is but you cannot make changes to it

// A node in a linked list
struct node {
    int data;
    struct node *next;
};

// ADD ANY FUNCTION DECLARATIONS YOU WISH TO USE HERE

// Remove any nodes in a list that are higher 
// than the node directly after them.
// Return the head of the list.
// The returned list must have no disorder in it!
int check_order(struct node *head) {

    struct node *iter = head;
    while(iter->next != NULL) {
        if(iter->data > iter->next->data){
            return 0;
        }
        iter = iter->next;
    }
    return 1;
}
struct node *delete_contains(int value, struct node *head) {
    if (head == NULL) {
        return head;
    }
    //list with one value that matches value to delete
    else if (head->data == value && head->next == NULL) {
        free(head);
        head = NULL;
        return head;

    }
    //list with multiple values with head that matches
    else if (head->data == value && head->next != NULL) {
        struct node *original_head = head;
        head = head->next;
        free(original_head);
        return head;

    }
    else {
        struct node *iter = head;
        struct node *delete = head;
        while (iter->next != NULL) {
            if (iter->next->data == value && iter->next->next != NULL) {
                delete = iter->next;
                iter->next = iter->next->next;
                free(delete);
                return head;

            }
            else if (iter->next->data == value && iter->next->next == NULL) {
                free(iter->next);
                iter->next = NULL;
                return head;

            }
            iter = iter->next;
        }
    }
    
    return head;

}


struct node *remove_disorder(struct node *head) {
    struct node *iter = head;
    while(check_order(head) == 0){
        iter = head;
        while(iter->next != NULL){
            if(iter->next->data < iter->data) {
               head = delete_contains(iter->data,head);
               break;
            }
            iter = iter->next;
        }    
        
    }
    return head;
}


// These helper functions are for the main below and will
// have no effect on your remove_disorder. They do not
// need to be modified.
struct node *make_list(int a, int b, int c);
void printList(struct node *head);

// This is a main function which could be used
// to test your remove_disorder function.
// It will not be marked.
// Only your remove_disorder function will be marked.
//
// It's recommended to change the int values in this
// main to test whether your remove_disorder is working.
int main(void) {
    // test an ordered list
    struct node *ordered = make_list(1, 2, 3);
    ordered = remove_disorder(ordered);
    printList(ordered);
    
    // test removing one element out of order
    ordered = make_list(1, 3, 2);
    ordered = remove_disorder(ordered);
    printList(ordered);
    
    // test a completely disordered list
    ordered = make_list(3, 2, 1);
    ordered = remove_disorder(ordered);
    printList(ordered);

    // test with the first removal causing more disorder
    ordered = make_list(2, 3, 1);
    ordered = remove_disorder(ordered);
    printList(ordered);
        
    return 0;
}

// A simple function to make a linked list with 3 elements
// This function is purely for the main above
// You will be tested with lists that are more and less
// than 3 elements long
struct node *make_list(int a, int b, int c) {
    struct node *head = malloc(sizeof (struct node));
    struct node *n = head;
    n->data = a;
    n->next = malloc(sizeof (struct node));
    n = n->next;
    n->data = b;
    n->next = malloc(sizeof (struct node));
    n = n->next;
    n->data = c;
    n->next = NULL;
    
    return head;
}

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
// ADD ANY FUNCTION DEFINITIONS YOU WISH TO USE HERE


