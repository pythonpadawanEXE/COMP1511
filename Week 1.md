# Introductions

11.How do you make a peanut-butter sandwich?

How could you break that process into steps?

How could you break it down clearly enough that a computer could understand it?

Maybe your tutor could do a live demonstration of a similar task following your exact instructions...
# Operating Systems

12.What is an operating system?

What operating systems do your classmates run? The tute room? The CSE lab (and VLAB) computers?

What are the differences between each of the various operating systems? What differences are there in their interfaces, and how do you interact with them?

What are some different ways in which you can interact with a computer?

What are the differences between graphical user interfaces and the command line? When might one be better than the other?

# Writing Some Code

Discuss the following features of the sample program from lectures:
```
// Basic Hello World program
// Marc Chee, September 2020

#include <stdio.h>

int main (void) {
    printf("Hello World\n");
    
    return 0;
}
```
* the \n
* Comments: What should go in a comment? What makes a good comment? How do comments improve program style?
* Indenting and whitespace: What is indented in the sample program? Suggest why. 

14.Write a C program, face0.c, that behaves as follows:

```
./face0
~ ~
0 0
 o
 -
```

Open Terminal, change to desired directory
```
z5165158@vx7:/tmp_amd/ravel/export/ravel/3/z5165158/Desktop/COMP1511/week1$ gedit face0.c
```

```
#include <stdio.h>

int main (void) {
    printf("~ ~\n0 0\n o\n -");
    
    return 0;
}
```
Save as face0.c 
# ! IMPORTANT TO INCLUDE '.c' on end of file name !

Compile
```
z5165158@vx7:/tmp_amd/ravel/export/ravel/3/z5165158/Desktop/COMP1511/week1$ dcc face0.c -o face0
```

To run
```
z5165158@vx7:/tmp_amd/ravel/export/ravel/3/z5165158/Desktop/COMP1511/week1$ ./face0
~ ~
0 0
 o

```

15. How would you compile this program?
16. How could we modify it to make a program, face1.c, look like this instead?
```
./face1
~ ~
0 0
 o
\_/
```
```
#include <stdio.h>

int main (void) {
    printf("~ ~\n0 0\n o\n\\_/\n");
    
    return 0;
}
```
