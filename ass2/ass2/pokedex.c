// Assignment 2 21T2 COMP1511: Pokedex
// pokedex.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0: Release
// Version 1.0.1: Fixed references to create_new_dexnode in comments and error messages

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


// ----------------------------------------------
// Add your own #defines here.
// ----------------------------------------------


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
    struct dexnode *head;
};


// You don't have to use the provided struct dexnode, you are free to
// make your own struct instead.
//
// If you use the provided struct dexnode, you will need to add fields
// to it to store other information.
struct dexnode {
    Pokemon pokemon;
    struct dexnode *next;
};


// ----------------------------------------------
// Add your own structs here.
// ----------------------------------------------




// ----------------------------------------------
// Add prototypes for your own functions here.
// ----------------------------------------------

// Creates a new dexnode struct and returns a pointer to it.
static struct dexnode *create_new_dexnode(Pokemon pokemon);


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
    pokedex->head = NULL;

    // TODO: Add your own code here.

    return pokedex;
}

// Create a new dexnode struct and returns a pointer to it.
//
// This function should allocate memory for a dexnode, set its pokemon
// pointer to point to the specified pokemon, and return a pointer to
// the allocated memory.
static struct dexnode *create_new_dexnode(Pokemon pokemon) {

    printf("The create_new_dexnode function has not been implemented yet!\n");

    return NULL;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {

    // Note: you should use the create_new_dexnode function here, and add
    // the newly-created dexnode to the end of the linked list of
    // dexnodes in the Pokedex.

    fprintf(stderr, "exiting because you have not implemented the add_pokemon function\n");
    exit(1);
}

// Print out all of the Pokemon in the Pokedex.
void print_pokedex(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the print_pokemon function\n");
    exit(1);
}

// Print out the details of the currently selected Pokemon.
void detail_current_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the detail_pokemon function\n");
    exit(1);
}

// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the get_current_pokemon function\n");
    exit(1);
}

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the next_pokemon function\n");
    exit(1);
}

// Change the currently selected Pokemon to be the previous Pokemon in the Pokedex.
void prev_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the prev_pokemon function\n");
    exit(1);
}

// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void jump_pokemon(Pokedex pokedex, int id) {
    fprintf(stderr, "exiting because you have not implemented the change_current_pokemon function\n");
    exit(1);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Sets the currently selected pokemon's "found" status
void set_current_pokemon_found(Pokedex pokedex, int found) {
    fprintf(stderr, "exiting because you have not implemented the set_current_pokemon_found function\n");
    exit(1);
}

// Add a pokemon before the current pokemon.
void insert_pokemon_before_current(Pokedex pokedex, Pokemon pokemon) {
    fprintf(stderr, "exiting because you have not implemented the insert_pokemon_before_current function\n");
    exit(1);
}

// Return the total number of Pokemon in the Pokedex.
int count_pokemon_of_type(Pokedex pokedex, char *type) {
    fprintf(stderr, "exiting because you have not implemented the count_pokemon_of_type function\n");
    exit(1);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////


// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the remove_pokemon function\n");
    exit(1);
}

// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    // Note: there is no fprintf or exit(1) in this function, as the
    // Stage 1 autotests call destroy_pokedex but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1, rather than exit).
}

// Prints out all types of found Pokemon stored in the Pokedex
void show_types(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the show_types function\n");
    exit(1);
}

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the count_found_pokemon function\n");
    exit(1);
}

// Return the total number of Pokemon in the Pokedex.
int count_total_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the count_total_pokemon function\n");
    exit(1);
}

// NOTE: Make sure you submit ass2_pokedex before completing these.
//////////////////////////////////////////////////////////////////////
//                     Stage 4 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

/*
 * Saves a pokedex to a text file
 * Use the functions in ext_save.h to save the contents to a file
 */
void save_pokedex(Pokedex pokedex, char* filename) {
    fprintf(stderr, "exiting because you have not implemented the save_pokedex function\n");
    exit(1);

}

/*
 * Loads a pokedex from a text file
 * Use the functions in ext_save.h to load the text from a file
 */
Pokedex load_pokedex(char* filename) {
    fprintf(stderr, "exiting because you have not implemented the load_pokedex function\n");
    exit(1);

    return NULL;
}

//////////////////////////////////////////////////////////////////////
//                     Stage 5 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    fprintf(stderr, "exiting because you have not implemented the get_pokemon_of_type function\n");
    exit(1);
}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the get_found_pokemon function\n");
    exit(1);
}

// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    fprintf(stderr, "exiting because you have not implemented the search_pokemon function\n");
    exit(1);
}

// Free's the current sub-list and returns the original pokedex state, 
// prior to the search
Pokedex end_search(Pokedex sub_pokedex) {
    fprintf(stderr, "exiting because you have not implemented the end_search function\n");
    exit(1);
}

// Add definitions for your own functions here.
