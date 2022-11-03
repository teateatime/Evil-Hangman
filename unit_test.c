#include <stdio.h>
#include <stdlib.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
 test_init_default_returns_nonNULL,
 test_get_capacity_on_init_default_work,
 test_get_size_on_init_default_returns_0,
 test_is_string_empty,
 test_is_string_not_empty,
 test_is_string_at,
 test_is_string_compare_work,
 test_is_string_at_work,
 test_is_string_str,
 test_is_string_insertion,
 test_is_string_extraction,
 test_is_string_push,
 test_is_string_pop,
 test_is_string_init_c_string,
 test_is_string_destroy,
 test_is_string_concat,
 test_is_string_size_c_string,
 test_is_string_capacity_c_string,
 test_is_string_insertion_again,
 test_is_string_extraction_again,
 test_is_string_compare_work_again,
 test_is_string_destroy_again,
 test_is_string_pop_plus,
 test_is_string_push_plus,
 test_is_string_not_at
 };
 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;

 for(i=0; i<number_of_functions; i++){
 if(tests[i](buffer, 500) == FAILURE){
    printf("FAILED: Test %d failed miserably\n", i);
    printf("\t%s\n", buffer);
    failure_count++;
 }
 else {  
//  printf("PASS: Test %d passed\n", i);
//  printf("\t%s\n", buffer);
    success_count++;
    }
 }
 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);

 return 0;
}
