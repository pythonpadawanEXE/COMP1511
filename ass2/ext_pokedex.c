// Assignment 2 21T2 COMP1511: Pokedex
// pokedex.c
//
// This program was written by YOUR-NAME-HERE (z5165158)
// on 25/07/2021
//
// Version 1.0.0: Release
// Version 1.0.1: Fixed references to create_new_dexnode in comments and error 
//messages

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ext_save.h"

// Note you are not allowed to use the strstr function in this assignment
// There are some techniques we would like you to learn to code
// that this function makes easier.

// ----------------------------------------------
// Add any extra #includes your code needs here.
// ----------------------------------------------

#include "pokedex.h"

#include <math.h>

// ----------------------------------------------
// Add your own #defines here.
// ----------------------------------------------
#define NAME_LEN 20
#define TYPE_LEN 20
#define FOUND 1
#define NOT_FOUND 0
#define SHOWN 1
#define NOT_SHOWN 0
#define NUM_TYPES 19
#define NONE_TYPE 0
#define POKEMON_STR_SIZE 1024
#define LEN_ID 5
#define LEN_NUM 16//probably should define this better


// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.
struct pokedex {
    struct pokedex *prev_pokedex; 
    struct pokedex *next_pokedex;
    struct dexnode *head;
    struct dexnode *current;
};


// You don't have to use the provided struct dexnode, you are free to
// make your own struct instead.
//
// If you use the provided struct dexnode, you will need to add fields
// to it to store other information.
struct dexnode {
    Pokemon pokemon;
    struct dexnode *next;
    struct dexnode *previous;
    int found_status;
};

struct pokemon {
    int pokemon_id;
    char *name;
    double height;
    double weight;
    pokemon_type type1;
    pokemon_type type2;
};


// ----------------------------------------------
// Add your own structs here.
// ----------------------------------------------




// ----------------------------------------------
// Add prototypes for your own functions here.
// ----------------------------------------------

// Creates a new dexnode struct and returns a pointer to it.
static struct dexnode *create_new_dexnode(Pokemon pokemon);
static void add_line(Pokedex pokedex, char *line);
int string_contains(char *substr, char *str);
int total_num_pokedexes(Pokedex pokedex);
Pokemon make_pokemon_from_existing(Pokemon existing_pkmn);
// You need to implement the following functions in their stages.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


// Creates a new Pokedex, and returns a pointer to it.
// Note: you will need to modify this function.
Pokedex new_pokedex(void) {
    // Malloc memory for a new Pokedex, and check that the memory
    // allocation succeeded.
    Pokedex pokedex = malloc(sizeof(struct pokedex));
    assert(pokedex != NULL);

    // Set the head of the linked list to be NULL.
    // (i.e. set the Pokedex to be empty)
    pokedex->prev_pokedex = NULL;
    pokedex->next_pokedex = NULL;
    pokedex->head = NULL;
    pokedex->current =  pokedex->head; 
    
    /*
    Hint: your currently selected Pokemon won't change in Stage 1, 
    and so will always be the first Pokemon added to your Pokedex (for now). 
    */

   

    return pokedex;
}

// Create a new dexnode struct and returns a pointer to it.
//
// This function should allocate memory for a dexnode, set its pokemon
// pointer to point to the specified pokemon, and return a pointer to
// the allocated memory.
static struct dexnode *create_new_dexnode(Pokemon pokemon) {
    
    struct dexnode * new_dexnode = malloc(sizeof(struct dexnode));
    assert(new_dexnode != NULL);
    new_dexnode->found_status = FOUND;
    new_dexnode->pokemon = pokemon;
    new_dexnode->next = NULL;
    new_dexnode->previous = NULL;
    return new_dexnode;
     
     
    //printf("The create_new_dexnode function has not been implemented yet!\n");
    //return NULL;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {

    // Note: you should use the create_new_dexnode function here, and add
    // the newly-created dexnode to the end of the linked list of
    // dexnodes in the Pokedex.
    
    struct dexnode *new_dexnode = create_new_dexnode(pokemon);

    if (pokedex->head == NULL && pokedex->current == NULL) {
        pokedex->head = new_dexnode;
        pokedex->current = pokedex->head;
        //printf("%p", pokedex->head);
    }
    else {
        struct dexnode *head = pokedex->head;
        struct dexnode *prev = head;

        while (head != NULL) {
            prev = head;
            head = head->next;
        
        }
        new_dexnode->previous = prev;
        prev->next = new_dexnode;
    }
 
}

// Print out all of the Pokemon in the Pokedex.
void print_pokedex(Pokedex pokedex) {
    struct dexnode *head = pokedex->head;
    
    while (head != NULL) {
        if (head == pokedex->current) {
            printf("--> ");
        }
        else {
            printf("    ");       
        }
        printf("#");
        if (pokemon_id(head->pokemon) < 10) {
            printf("00");
        }
        else if (pokemon_id(head->pokemon) < 100 ) {
            printf("0");
        }
        printf("%d: ",pokemon_id(head->pokemon));
        if (head->found_status == FOUND) {
            printf("%s\n",pokemon_name(head->pokemon));
        }
        else {
            for(int i = 0;i < strlen(pokemon_name(head->pokemon)); i++) {
                printf("*");
            }
            printf("\n");
        }
        head = head->next;
    }
}

// Print out the details of the currently selected Pokemon.
void detail_current_pokemon(Pokedex pokedex) {
    
    Pokemon pokemon = get_current_pokemon(pokedex);
    printf("ID: ");
    if (pokemon_id(pokemon) < 10) {
        printf("00");
    }
    else if (pokemon_id(pokemon) < 100 ) {
        printf("0");
    }
    printf("%d\n", pokemon_id(pokemon));
    if (pokedex->current->found_status == FOUND) { 
        printf("Name: %s\n", pokemon_name(pokemon));
        printf("Height: %lf m\n", pokemon_height(pokemon));
        printf("Weight: %lf kg\n", pokemon_weight(pokemon));
        if (strcmp(type_code_to_str(pokemon_second_type(pokemon)), "None")) {
            printf("Type: %s %s\n", 
            type_code_to_str(pokemon_first_type(pokemon)), 
            type_code_to_str(pokemon_second_type(pokemon)));
        }
        else {
            printf("Type: %s\n", type_code_to_str(pokemon_first_type(pokemon)));
        }
    }
    else {
        printf("Name: ");
        for(int i = 0;i < strlen(pokemon_name(pokemon)); i++) {
            printf("*");
        }
        printf("\n");
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
    
    }
}

// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    
    return pokedex->current->pokemon;
}

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    if (pokedex->current->next != NULL) {
        pokedex->current= pokedex->current->next;
    }
}

// Change the currently selected Pokemon to be the previous Pokemon in the 
//Pokedex.
void prev_pokemon(Pokedex pokedex) {
    if (pokedex->current->previous != NULL) {
        pokedex->current = pokedex->current->previous;
    }    
}

// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void jump_pokemon(Pokedex pokedex, int id) {
    struct dexnode *head = pokedex->head;
      

    while (head != NULL) {
        if (pokemon_id(head->pokemon) == id) {
            pokedex->current = head;
            return;     
        }
        head = head->next;
    
    }
    printf("POKEMON ID DOESN'T EXIST OR SOME OTHER ERROR OCCURRED\n");
}

//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Sets the currently selected pokemon's "found" status
void set_current_pokemon_found(Pokedex pokedex, int found) {
    pokedex->current->found_status = found;
}

// Add a pokemon before the current pokemon.
void insert_pokemon_before_current(Pokedex pokedex, Pokemon pokemon) {
    
    struct dexnode *new_dexnode = create_new_dexnode(pokemon);
    assert(new_dexnode != NULL);
    if (pokedex->head == NULL && pokedex->current == NULL) {
        pokedex->head = new_dexnode;
        pokedex->current = new_dexnode;
        //printf("%p", pokedex->head);
    }
    else if (pokedex->head == pokedex->current) {
        
        pokedex->current->previous = new_dexnode;
        new_dexnode->next = pokedex->current;
        pokedex->current = new_dexnode;
        pokedex->head = new_dexnode;
        //printf("works?\n");
        
    }
    else {
       
        pokedex->current->previous->next = new_dexnode;
        new_dexnode->previous = pokedex->current->previous;
        pokedex->current->previous = new_dexnode;
        new_dexnode->next = pokedex->current;
        pokedex->current = new_dexnode;
  
    }
    set_current_pokemon_found(pokedex, NOT_FOUND);
   
}

// Return the total number of Pokemon in the Pokedex.
int count_pokemon_of_type(Pokedex pokedex, char *type) {
    struct dexnode *head = pokedex->head;
    int count = 0;
    while (head != NULL) {
        if (strcasecmp(type_code_to_str(pokemon_first_type(head->pokemon)),
        type) == 0 
        ||
        strcasecmp(type_code_to_str(pokemon_second_type(head->pokemon)),
        type) == 0) 
        {
            count++;
        }
        head = head->next;
    }
    return count;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////


// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    struct dexnode *delete = pokedex->current;
    if (pokedex->current->next != NULL &&
     pokedex->current->previous != NULL) {

        pokedex->current->previous->next = pokedex->current->next;
        pokedex->current->next->previous = pokedex->current->previous;
        pokedex->current = pokedex->current->next;
        free(pokemon_name(delete->pokemon));
        free(delete->pokemon);
        free(delete);
    }
    else if (pokedex->current->next != NULL &&
     pokedex->current->previous == NULL) {

        pokedex->current->next->previous = NULL;
        pokedex->current = pokedex->current->next;
        pokedex->head = pokedex->current;
        free(pokemon_name(delete->pokemon));
        free(delete->pokemon);
        free(delete);
    }
    else if (pokedex->current->previous != NULL && 
    pokedex->current->next == NULL) {

        pokedex->current->previous->next = NULL;
        pokedex->current = pokedex->current->previous;
        free(pokemon_name(delete->pokemon));
        free(delete->pokemon);
        free(delete);
    }
    else if (pokedex->current->next == NULL && 
    pokedex->current->previous == NULL ) {

        free(pokemon_name(delete->pokemon));
        free(delete->pokemon);
        free(delete);
        pokedex->current = NULL; 
        pokedex->head = NULL;   
    }
    else { 
        printf("Unhandled exception");
    }
    
}

// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        free(pokedex);
        return;
    }
    for (pokedex->current = pokedex->head; pokedex->current != NULL;
    pokedex->current = pokedex->current) {
        
        remove_pokemon(pokedex);  
    
    }
    free(pokedex);
}

// possibly issues with types and indexing

// Prints out all types of found Pokemon stored in the Pokedex
void show_types(Pokedex pokedex) {
    int type_check[NUM_TYPES] = {NOT_SHOWN};
    
    for(struct dexnode *iter = pokedex->head; iter != NULL;
    iter = iter->next) {
    
        if (iter->found_status == FOUND && 
        type_check[pokemon_first_type(iter->pokemon)] == NOT_SHOWN &&
        pokemon_first_type(iter->pokemon) != NONE_TYPE) {
            printf("%s\n", type_code_to_str(pokemon_first_type(iter->pokemon)));
            type_check[pokemon_first_type(iter->pokemon)] = SHOWN;
        }
        if (iter->found_status == FOUND && 
        type_check[pokemon_second_type(iter->pokemon)] == NOT_SHOWN
        && pokemon_second_type(iter->pokemon) != NONE_TYPE) {
            printf("%s\n", 
            type_code_to_str(pokemon_second_type(iter->pokemon)));
            type_check[pokemon_second_type(iter->pokemon)] = SHOWN;
        }
    }
     
}

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    int count = 0;
    for(struct dexnode *iter = pokedex->head; iter != NULL;
    iter = iter->next) {
    
        if (iter->found_status == FOUND) {
            count++;
        }
    }
    return count;
}

// Return the total number of Pokemon in the Pokedex.
int count_total_pokemon(Pokedex pokedex) {
    int count = 0;
    for(struct dexnode *iter = pokedex->head; iter != NULL; iter = iter->next) {
        count++;
    }
    return count;
}

// NOTE: Make sure you submit ass2_pokedex before completing these.
//////////////////////////////////////////////////////////////////////
//                     Stage 4 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

/*
 * Saves a pokedex to a text file
 * Use the functions in ext_save.h to save the contents to a file
 */
void save_pokedex(Pokedex pokedex, char *filename) {
    //define size of big string
    int pokemon_size = POKEMON_STR_SIZE;
    int count = count_total_pokemon(pokedex);
    char * pokedex_str = malloc(sizeof(char)*count * pokemon_size);
    //check pokedex is not empty
    //printf("%d\n",count);
    if (count == 0) {
        save_string(filename, "EMPTY FILE\n");
        //printf("is this working\n");
        free(pokedex_str);
        return;
    }
    
    
     
    //is this big enough for name?
    
    struct dexnode *iter = pokedex->head;
    int i = 0;

    //int dec_num;

    int tmp;
    char id[LEN_ID];
    char num[LEN_NUM];
    //make pokedex a big string
    while (iter != NULL) {
        //id
        sprintf(id, "%d", pokemon_id(iter->pokemon));
        strcpy(&pokedex_str[i], id);
        i = i + strlen(id);
        pokedex_str[i] = ' ';
        i = i + strlen(" ");
        //name
        strcpy(&pokedex_str[i],pokemon_name(iter->pokemon));
        i = i + strlen(pokemon_name(iter->pokemon));
        pokedex_str[i] = ' ';
        i = i + strlen(" ");
        //height
        tmp = sprintf(num,"%lf",pokemon_height(iter->pokemon));
        strcpy(&pokedex_str[i], num);
        i = i + tmp;
        pokedex_str[i] = ' ';
        i = i + strlen(" ");
       
        tmp = sprintf(num, "%lf", pokemon_height(iter->pokemon));
        strcpy(&pokedex_str[i], num);
        i = i + tmp;
        pokedex_str[i] = ' ';
        i = i + strlen(" ");
        //type one
        strcpy(&pokedex_str[i], 
        type_code_to_str(pokemon_first_type(iter->pokemon))); 
        i = i + strlen(type_code_to_str(pokemon_first_type(iter->pokemon)));
        pokedex_str[i] = ' ';
        i = i + strlen(" ");
        //type two
        strcpy(&pokedex_str[i], 
        type_code_to_str(pokemon_second_type(iter->pokemon)));
        i = i + strlen(type_code_to_str(pokemon_second_type(iter->pokemon)));

        pokedex_str[i] = '\n';
        i = i + strlen("\n");
        
        iter = iter->next;
    }
    pokedex_str[i] = '\0';
    save_string(filename, pokedex_str);
    free(pokedex_str);
}

/*
 * Loads a pokedex from a text file
 * Use the functions in ext_save.h to load the text from a file
 */
Pokedex load_pokedex(char *filename) {
    Pokedex pokedex = new_pokedex();
    char *pokedex_str;
    char *line;
    //load the big string
    pokedex_str = load_string(filename);
    //printf("str:%s\n",pokedex_str);
    if (pokedex_str == NULL || strcmp(pokedex_str, "EMPTY FILE\n") == 0) {
        free(pokedex_str);
        return pokedex;
    }

    char delimiter[] = "\n";
    //process the big string
    line = strtok(pokedex_str, delimiter);
     
    while (line != NULL) {
        
        add_line(pokedex, line);
        line = strtok(NULL, delimiter);
    }
    
    free(pokedex_str);
    return pokedex;
}

//////////////////////////////////////////////////////////////////////
//                     Stage 5 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    
    //TODO:
    //The currently selected Pokemon in the new Pokedex should be the
    //first Pokemon in the Pokedex.
    Pokedex pokedex_filtered = new_pokedex();
    pokedex->next_pokedex =  pokedex_filtered;
    pokedex_filtered->prev_pokedex = pokedex;
    
    
    for (struct dexnode *iter = pokedex->head; iter != NULL; 
    iter = iter->next) {
        if ((pokemon_first_type(iter->pokemon) == type || 
        pokemon_second_type(iter->pokemon) == type) && 
        iter->found_status == FOUND) {
            Pokemon new_pkmn = make_pokemon_from_existing(iter->pokemon);
            add_pokemon(pokedex_filtered, new_pkmn);
        }
    
    }
    
    
    return pokedex_filtered;
    //make pokedex next pointer in pokedex struct and modified new pokedex function
    //make new pokedex
}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    //TODO:
    //The currently selected Pokemon in the new Pokedex should be the
    //first Pokemon in the Pokedex.
    Pokedex pokedex_filtered = new_pokedex();
    pokedex->next_pokedex =  pokedex_filtered;
    pokedex_filtered->prev_pokedex = pokedex;
    
    
    for (struct dexnode *iter = pokedex->head; iter != NULL;
    iter = iter->next) {
        if (iter->found_status == FOUND) {
            Pokemon new_pkmn = make_pokemon_from_existing(iter->pokemon);
            add_pokemon(pokedex_filtered, new_pkmn);
        }
    
    }
    
    
    return pokedex_filtered;
}

// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    //TODO:
    //The currently selected Pokemon in the new Pokedex should be the
    //first Pokemon in the Pokedex.
    Pokedex pokedex_filtered = new_pokedex();
    pokedex->next_pokedex =  pokedex_filtered;
    pokedex_filtered->prev_pokedex = pokedex;
    
    
    for (struct dexnode *iter = pokedex->head; iter != NULL; 
    iter = iter->next) {
        //printf("%s %d\n",pokemon_name(iter->pokemon), iter->found_status);
        if (string_contains(text,pokemon_name(iter->pokemon)) == 1 &&
         iter->found_status == FOUND) {

            Pokemon new_pkmn = make_pokemon_from_existing(iter->pokemon);
            add_pokemon(pokedex_filtered, new_pkmn);
        }
    
    }
    
    
    return pokedex_filtered;
}

// Free's the current sub-list and returns the original pokedex state, 
// prior to the search
Pokedex end_search(Pokedex sub_pokedex) {
    /*Pokedex iter = sub_pokedex;
    if(sub_pokedex->prev_pokedex == NULL){
        return sub_pokedex;
    }
    Pokedex iter_prev_pokedex = sub_pokedex->prev_pokedex;
    while(iter_prev_pokedex != NULL){
        destroy_pokedex(iter);
        iter = iter->prev_pokedex;
        iter_prev_pokedex = iter_prev_pokedex->prev_pokedex;
    }*/
    if (sub_pokedex->prev_pokedex == NULL) {
        return sub_pokedex;
    }
    /*Pokedex iter = sub_pokedex->prev_pokedex;
    free(sub_pokedex);
    return iter;*/
    Pokedex iter = sub_pokedex;
    sub_pokedex = sub_pokedex->prev_pokedex;
    sub_pokedex->next_pokedex = NULL;
    destroy_pokedex(iter);
    //printf("Pokedexes existing: %d\n", total_num_pokedexes(sub_pokedex));
    return sub_pokedex;
    
}

// Add definitions for your own functions here.
int string_contains(char *substr, char *str){

    int max_check_idx = strlen(str) - strlen(substr) + 1;
    for (int i = 0; i < max_check_idx;i++) {
        if (strncmp(substr, &str[i], strlen(substr)) == 0) {
            return 1;
        }
        /*for(int ii = i; ii < i + strlen(substr);ii++){
            putchar(str[ii]);
        }
        printf("\n");
        */
    }
    return 0;
}
int total_num_pokedexes(Pokedex pokedex){
    Pokedex iter = pokedex;
    while (iter->next_pokedex != NULL) {
        iter = iter->next_pokedex;
    }
    int count = 0;
    while (iter->prev_pokedex != NULL) {
        count++;
        iter= iter->prev_pokedex;
    }
    return count;
}
//how do we break link to existing pokemon
Pokemon make_pokemon_from_existing(Pokemon existing_pkmn){
    int pokemon_id_val = pokemon_id(existing_pkmn);
    double height = pokemon_height(existing_pkmn);
    double weight = pokemon_weight(existing_pkmn);
    char name[POKEMON_STR_SIZE] = {0};
    strcpy(name, pokemon_name(existing_pkmn));
    pokemon_type type1 = pokemon_first_type(existing_pkmn);
    pokemon_type type2 = pokemon_second_type(existing_pkmn);
   
    
    Pokemon new_pkmn = new_pokemon(pokemon_id_val, name, height, weight,
        type1, type2);
    return new_pkmn;
}


static void add_line(Pokedex pokedex, char *line) {
    int pokemon_id = 0;
    double height = 0, weight = 0;
    int items_read = 0;
    char name[POKEMON_STR_SIZE] = {0};
    char type1[POKEMON_STR_SIZE] = {0};
    char type2[POKEMON_STR_SIZE] = {0};
    //printf("%s\n", line);
    items_read = sscanf(line, "%d %s %lf %lf %s %s", &pokemon_id,
        name, &height, &weight, type1, type2);

    if (items_read < 5) {
        printf("Invalid Add Command\n");
        return;
    }

    Pokemon pokemon = new_pokemon(pokemon_id, name, height, weight,
        type_str_to_code(type1), type_str_to_code(type2));

    add_pokemon(pokedex, pokemon);
    //printf("Added %s to the pokedex!\n", name);
}
