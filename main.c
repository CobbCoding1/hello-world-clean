/*
ORIGINAL CODE
#include <stdio.h>

int main(){
    printf("Hello, world!\n");
    return 0;
}
*/


// NEW AND IMPROVED CLEAN CODE


// include stdio.h;
#include <stdio.h>
// include stdlib.h;
#include <stdlib.h>
// include assert.h;
#include <assert.h>
// include string.h;
#include <string.h>

// define the hello world string length macro and set it to 14;
#define HELLO_WORLD_STRING_LENGTH_MACRO 14

// initialize the struct which contains a hello world string, hello world string length, and hello world struct error code;
typedef struct{
    char *hello_world_struct_string;
    size_t hello_world_struct_string_length;
    size_t hello_world_struct_error_code;
} HelloWorld;

// define the print_hello_world_error_message function, which takes an error message string as an argument;
size_t print_hello_world_error_message(HelloWorld *hello_world, char *error_message){
    // set the hello world struct error code equal to the non zero value;
    hello_world->hello_world_struct_error_code = 1;
    // print the error message passed to standard error;
    fprintf(stderr, "%s\n", error_message);
    // exit with exit code 1, which is non-zero, which indicates something went wrong;
    exit(1);
    // unnecessary but makes the code clearer, returning a non-zero value which we set to hello world struct error code;
    return hello_world->hello_world_struct_error_code;
}

// define the print_hello_world_string function, which takes a pointer to the hello world structure;
size_t print_hello_world_string(HelloWorld *hello_world){
    // assert that the hello world structure exists and is not null;
    assert(hello_world != NULL && "no struct");
    // initialize the new hello world string, in case the old hello world string is not correct;
    char *new_hello_world_string = "Hello, world!";
    // set the value of hello world string inside the hello world struct to the new hello world string value;
    hello_world->hello_world_struct_string = new_hello_world_string;

    // check that the length of the hello world string is equal to the string length in order to not go out of bounds;
    if(hello_world->hello_world_struct_string_length != HELLO_WORLD_STRING_LENGTH_MACRO){
        // if the condition is not met, then printing the error message, and setting the hello world struct error code value equal to the return of the function;
        hello_world->hello_world_struct_error_code = print_hello_world_error_message(hello_world, "str len no good");
    }

    // for loop, which iterates hello world string index until we reach the value of hello world string length;
    for(size_t hello_world_string_index; hello_world_string_index < hello_world->hello_world_struct_string_length; hello_world_string_index++){
        // make sure hello world string index does not go above 14;
        if(hello_world_string_index > 14){
            // if it does go above 14, then print the error message str len no good again, and set the hello world struct error code equal to the return value;
            hello_world->hello_world_struct_error_code = print_hello_world_error_message(hello_world, "str len no good again");
        }
        // print the current character of hello world string index of hello world struct string;
        printf("%c", hello_world->hello_world_struct_string[hello_world_string_index]);
    }
    // print new line at the end of the loop, to ensure there is space to make easy read;
    printf("\n");
    // return the hello world struct error code;
    return hello_world->hello_world_struct_error_code;
}

// define main function;
int main(){
    // initializing hello world string, which will be printed later (not actually);
    char *hello_world_string = "Hello, world!";
    // initializing hello world structure, which will contain the data of our program;
    HelloWorld hello_world;
    // seting the initial values of the hello world structure;
    hello_world.hello_world_struct_string = hello_world_string;
    // continues here
    hello_world.hello_world_struct_string_length = 14;
    // calling to the print_hello_world_string function, passing the hello world structure, setting the error code to the value returned;
    hello_world.hello_world_struct_error_code = print_hello_world_string(&hello_world);
    // if the hello world struct error code was not zero then:
    if(hello_world.hello_world_struct_error_code != 0){
        // do this, which is printing the error message not zero and setting hello world struct error code equal to the return value;
        hello_world.hello_world_struct_error_code = print_hello_world_error_message(&hello_world, "not zero");
    }
    // returning the hello world error code value;
    return hello_world.hello_world_struct_error_code;
}
