// exam_q6.c
//
// This program was written by z5165158
// on 18/08/21

#include <stdio.h>
#include <stdlib.h>

// Do not edit this struct. You may use it exactly as
// it is but you cannot make changes to it

// A node in a linked list
struct node {
    int height;
    struct node *next;
};

// ADD ANY FUNCTION DECLARATIONS YOU WISH TO USE HERE
int idx_of_height(struct node* head,int height){
    int count = 0;
    struct node* iter = head;
    while(iter != NULL){
        if(iter->height == height){
            return count;
        }
        iter = iter->next;
        count++;
    }
    return -1;
        
}

int height_at_idx(struct node* head,int idx){
    int count = 0;
    struct node* iter = head;
    while(iter != NULL){
        if(count == idx){
            return iter->height;
        }
        iter = iter->next;
        count++;
    }
    return -1;
}
struct node *ptr_of_height(struct node* head,int height){
    int count = 0;
    struct node* iter = head;
    while(iter != NULL){
        if(iter->height == height){
            return iter;
        }
        iter = iter->next;
        count++;
    }
    return head;
        
}

int max_height(struct node* head){
    int max = head->height;
    struct node* iter = head;
    while(iter != NULL){
        if(iter-> height > max){
            max = iter->height;
        }
        iter = iter->next;
    }
    return max;
}
int length(struct node* head){
    struct node* iter = head;
    int count = 0;
    while(iter != NULL){
        iter = iter->next;
        count++;
    }
    return count;
}
struct node *make_node(struct node* current,int height){
    struct node *new = malloc(sizeof(struct node));
    if(current == NULL){
        new->next = NULL;
        new->height = height;
        return new;
    }
    else{
        new->next = NULL;
        new->height = height;
        current->next = new;
        return new;
        
    }
}

struct node  *ptr_dec_left(struct node *head){
    //start at peak
    int height = max_height(head);
    int idx = idx_of_height(head, height);
    
    //moving left
    
    //should it be -1 or 0? as condition
    int num = 0;
    //printf("%d\n",height);
    struct node *new_head = make_node(NULL,height);
    struct node *curr = new_head;
    while(idx > -1){
       // printf("idx:%d\n",idx);
        //note can assume no equal heights
        if(height > height_at_idx(head,idx)){
            num++;
           // printf("%d\n",height);
            
            height = height_at_idx(head,idx);
            curr = make_node(curr,height);
        }
        
        idx = idx -1;
        
    }
    return new_head;
}


/*int num_dec_right(struct node *head){
    //start at peak
    int height = max_height(head);
    int idx = idx_of_height(head, max_height);
    
    //moving left
    
    //should it be < or <= as condition?
    int num = 0;
    int length_list = length(head);
    while(idx <= length_list){
        //note can assume no equal heights
        if(height >= height_at_idx(head,idx){
            num++;
            height = height_at_idx(head,idx);
        }
        
        idx = idx++;
        
    }
    return num;
}*/
struct node *mountaineer(struct node *head) {

    return ptr_dec_left(head);
}


///////////////////////////////////////////////////////////////
//
// YOU DO NOT NEED TO UNDERSTAND CODE BELOW THIS COMMENT
// 
// DO NOT CHANGE CODE BELOW THIS COMMENT
//
// IF YOU THINK YOU NEED TO CHANGE ANYTHING BELOW THIS COMMENT,
// YOU HAVE MISUNDERSTOOD THE QUESTION
//
///////////////////////////////////////////////////////////////

void print_and_free_list(struct node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d, ", head->height);
    print_and_free_list(head->next);
    free(head);
}

struct node *make_list(int length, char *argv[]) {
    struct node *head = malloc(sizeof (struct node));
    struct node *n = head;
    int i = 0;
    while (i < length) {
        n->height = strtol(argv[i + 1], NULL, 10);
        if (i < length - 1) {
            // there are more nodes to make
            n->next = malloc(sizeof (struct node));
            n = n->next;
        } else {
            n->next = NULL;
        }
        i++;
    }
    return head;
}

int main(int argc, char *argv[]) {
    struct node *head = make_list(argc - 1, argv);
    struct node *return_path = mountaineer(head);
    printf("Given stopping points: ");
    print_and_free_list(head);

    printf("Return stopping points: ");
    print_and_free_list(return_path);
    return 0;
}
