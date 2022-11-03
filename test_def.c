#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "unit_test.h"
#include "my_string.h"
#include <string.h>

Status test_init_default_returns_nonNULL(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_default();

    if(hString == NULL) {
       strncpy(buffer, "test_init_default_returns_nonNULL\n"
       "my_string_init_default returns NULL", length);
       return FAILURE;
    }
    else {
       my_string_destroy(&hString);
       strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
       return SUCCESS; 
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    if(my_string_get_size(hString) != 0) {
       status = FAILURE;
       printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
       strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
       "Did not receive 0 from get_size after init_default\n", length);
    }
    else {
       status = SUCCESS;
       strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_get_capacity_on_init_default_work(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    if(my_string_get_capacity(hString) != 0){
       status = SUCCESS;
       printf("Expected to get capacity of %d from default\n", my_string_get_capacity(hString));
       strncpy(buffer, "test_get_capacity_on_init_default_returns_0\n"
       "Did not receive 0 from get_capacity after init_default\n", length);
    }
    else{
       status = FAILURE;
       strncpy(buffer, "test_get_capacity_on_init_default_returns_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_is_string_empty(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("Hello");

    if(my_string_empty(hString) == 0){
	printf("String is empty\n");
	status = SUCCESS;
    }
    else{
	printf("hString is not empty\n");
	status = FAILURE;
    }
    	my_string_destroy(&hString);
	return status;
}

Status test_is_string_not_empty(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    if(my_string_empty(hString) == 0){
        printf("String is empty\n");
        status = FAILURE;
    }
    else{
        printf("hString is not empty\n");
        status = SUCCESS;
    }
        my_string_destroy(&hString);
        return status;

}

Status test_is_string_at(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("World");
     Status status;

     if(*my_string_at(hString, 3) == 'l'){
        status = SUCCESS;
     }
     else {
        status = FAILURE;
     }

     my_string_destroy(&hString);
     return status;

}

Status test_is_string_compare_work(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Hello");
     MY_STRING sString = NULL;
     sString = my_string_init_c_string("World");
     Status status;

     if(my_string_compare(hString, sString) == 0){
        status = SUCCESS;
     }
     else {
        status = FAILURE;
     }
     
     my_string_destroy(&hString);
     my_string_destroy(&sString);
     return status;
}

Status test_is_string_at_work(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Hello");
     Status status;

     if(*my_string_at(hString, 3) == 'l'){
	status = SUCCESS;
     }
     else {
	status = FAILURE;
     }

     my_string_destroy(&hString);
     return status;
}

Status test_is_string_str(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Hello");
     Status status;

     if(*my_string_at(hString, 0) == 'H' && (*my_string_at(hString, 1) == 'e' && (*my_string_at(hString, 2) == 'l' && (*my_string_at(hString, 3) == 'l' && (*my_string_at(hString, 4) == 'o' ))))){
        status = SUCCESS;
     }
     else {
        status = FAILURE;
     }

     my_string_destroy(&hString);
     return status;
}

Status test_is_string_insertion(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Hello");
     Status status;

     if(my_string_insertion(hString, stdout) == SUCCESS){
	printf("\n");
	my_string_insertion(hString, stdout);
	printf("\n");
	status = SUCCESS;
     }
     else {
	status = FAILURE;
     }
     my_string_destroy(&hString);
     return status;

}

Status test_is_string_extraction(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    Status status;
    FILE* fp;
    fp = fopen("simple.txt", "r");

    if (fp == NULL) {
        fprintf(stdout, "Did not open\n");
        exit(1);
    }
    if(my_string_extraction(hString, fp)  == SUCCESS) {
        printf("my_string_extraction works\n");
	status = SUCCESS;
    }
    else {
	status = FAILURE;
    }

    my_string_destroy(&hString);
    fclose(fp);
    return status;
}

Status test_is_string_push(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("Hello");
    Status status;

    if(my_string_push_back(hString, 'P') == SUCCESS){
	status = SUCCESS;
	printf("Push back is successful\n");
	my_string_insertion(hString, stdout);
	printf("\n");
    }
    else {
	status = FAILURE;
    }
    my_string_destroy(&hString);
    return status;

}

Status test_is_string_pop(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("Hello");
    Status status;
    my_string_push_back(hString, 'P');
    my_string_insertion(hString, stdout);
    printf("\n");

    if(my_string_pop_back(hString) == SUCCESS){
	status = SUCCESS;
	printf("Pop back works\n");
	my_string_insertion(hString, stdout);
	printf("\n");
    }
    else {
	status = FAILURE;
    }
    my_string_destroy(&hString);
    return status;
}

Status test_is_string_init_c_string(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("Hello");
    Status status;
    
    if(hString == NULL){
	status = FAILURE;
    }
    else {
	status = SUCCESS;
	printf("my_string_init_c_string works\n");
	my_string_insertion(hString, stdout);
        printf("\n");
    }
    my_string_destroy(&hString);
    return status;
}

Status test_is_string_destroy(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("Hello");
    Status status;
    my_string_destroy(&hString);

    if(hString == NULL){
        status = FAILURE;
    }
    else {
        status = SUCCESS; 
    }
    return status;
}

Status test_is_string_concat(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Hello");
     MY_STRING sString = NULL;
     sString = my_string_init_c_string("World");
     Status status;
     
     if(my_string_concat(hString, sString) == SUCCESS){
	status = SUCCESS;
	printf("Concat works\n");
     }
     else {
	status = FAILURE;
     }
     my_string_destroy(&hString);
     my_string_destroy(&sString);
     return status;
}

Status test_is_string_size_c_string(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("Hello");

    if(my_string_get_size(hString) == 5){
	status = SUCCESS;
    }
    else {
	status = FAILURE;
    }
    my_string_destroy(&hString);
    return status;
}

Status test_is_string_capacity_c_string(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("Hello");

    if(my_string_get_capacity(hString) == 6){
        status = SUCCESS;
    }
    else {
        status = FAILURE;
    }
    my_string_destroy(&hString);
    return status;
}

Status test_is_string_insertion_again(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Hello World");
     Status status;

     if(my_string_insertion(hString, stdout) == SUCCESS){
        printf("\n");
        my_string_insertion(hString, stdout);
        printf("\n");
        status = SUCCESS;
     }
     else {
        status = FAILURE;
     }
     my_string_destroy(&hString);
     return status;

}

Status test_is_string_extraction_again(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    Status status;
    FILE* fp;
    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        fprintf(stdout, "Did not open\n");
        exit(1);
    }
    if(my_string_extraction(hString, fp)  == SUCCESS) {
        status = SUCCESS;
    }
    else {
        status = FAILURE;
    }

    my_string_destroy(&hString);
    fclose(fp);
    return status;
}

Status test_is_string_compare_work_again(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Jail");
     MY_STRING sString = NULL;
     sString = my_string_init_c_string("Bail");
     Status status;

     if(my_string_compare(hString, sString) == 0){
        status = SUCCESS;
     }
     else {
        status = FAILURE;
     }

     my_string_destroy(&hString);
     my_string_destroy(&sString);
     return status;
}

Status test_is_string_concat_again(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Welcome");
     MY_STRING sString = NULL;
     sString = my_string_init_c_string("World");
     Status status;

     if(my_string_concat(hString, sString) == SUCCESS){
        status = SUCCESS;
     }
     else {
        status = FAILURE;
     }
     my_string_destroy(&hString);
     my_string_destroy(&sString);
     return status;
}

Status test_is_string_destroy_again(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("World");
    Status status;
    my_string_destroy(&hString);

    if(hString == NULL){
        status = FAILURE;
    }
    else {
        status = SUCCESS;
    }
    return status;
}

Status test_is_string_pop_plus(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("Hello");
    Status status;
    my_string_push_back(hString, 'P');
    my_string_push_back(hString, 'S');
    printf("\n");

    if(my_string_pop_back(hString) == SUCCESS){
        status = SUCCESS;
    }
    else {
        status = FAILURE;
    }
    my_string_destroy((Item*)&hString);
    return status;
}

Status test_is_string_push_plus(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("Hello");
    Status status;

    if(my_string_push_back(hString, 'S') == SUCCESS){
        status = SUCCESS;
    }
    else {
        status = FAILURE;
    }
    my_string_destroy(&hString);
    return status;

}

Status test_is_string_not_at(char* buffer, int length){
     MY_STRING hString = NULL;
     hString = my_string_init_c_string("Hello");
     Status status;

     if(*my_string_at(hString, 4) != 'l'){
        status = SUCCESS;
     }
     else {
        status = FAILURE;
     }

     my_string_destroy(&hString);
     return status;
}

