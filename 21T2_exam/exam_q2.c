// exam_q2.c
//
// This program was written z5165158
// on 18/08/21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

// compare should return -1 if head1 is a shorter list than head2
// compare should return  1 if head1 is a longer list than head2
// compare should return  0 if head1 is the same length as head2
int compare(struct node *head1, struct node *head2) {
    int count1 = 0;
    int count2 = 0;
    struct node* iter1 = head1;
    struct node* iter2 = head2;
    
    while(iter1 != NULL){
        count1++;
        iter1 = iter1->next;
    }
    while(iter2 != NULL){
        count2++;
        iter2 = iter2->next;
    }
    if(count1 < count2){
        return -1;
    }
    else if(count1 == count2){
        return 0;
    }
    else if(count1 > count2){
        return 1;
    }
    else {
        return 404;
    }


}


///////////////////////////////////////////////////
//
// YOU DO NOT NEED TO UNDERSTAND CODE BELOW THIS COMMENT
// 
// DO NOT CHANGE CODE BELOW THIS COMMENT
//
// IF YOU THINK YOU NEED TO CHANGE ANYTHING BELOW THIS COMMENT,
// YOU HAVE MISUNDERSTOOD THE QUESTION
//
///////////////////////////////////////////////////

struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = compare(head1, head2);
    printf("%d\n", result);

    return 0;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
