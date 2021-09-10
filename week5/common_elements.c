// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination
//z5165158 made on 8/07/2021



int common_elements(int length, int source1[length], int source2[length], 
int destination[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    //follow source 2 to see if value has been used before as a match
    int iter_src_1 = 0;
    int num_common = 0;
    int dest_iter = 0;

    while (iter_src_1 < length) {
    
        for(int iter_src_2 = 0; iter_src_2 < length; iter_src_2++) {
            if (source1[iter_src_1] == source2[iter_src_2]) {
                destination[dest_iter] = source1[iter_src_1];
                num_common++;
                dest_iter++;
                break;
            }
        
        }
        iter_src_1++;
    }
    return num_common;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
