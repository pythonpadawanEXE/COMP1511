//z5165158 Made:30/07/2021
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_contains(int value, struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    int value;
    scanf("%d", &value);
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_contains(value, head);
    print_list(new_head);


    return 0;
}


//
// Delete the first node in the list containing the value `value`.
// The deleted node is freed.
// If no node contains `value`, the list is not changed.
// The head of the list is returned.
//
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


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}
