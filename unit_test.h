#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_get_capacity_on_init_default_work(char* buffer, int length);
Status test_is_string_empty(char* buffer, int length);
Status test_is_string_not_empty(char* buffer, int length);
Status test_is_string_at(char* buffer, int length);
Status test_is_string_compare_work(char* buffer, int length);
Status test_is_string_at_work(char* buffer, int length);
Status test_is_string_str(char* buffer, int length);
Status test_is_string_insertion(char* buffer, int length);
Status test_is_string_extraction(char* buffer, int length);
Status test_is_string_push(char* buffer, int length);
Status test_is_string_pop(char* buffer, int length);
Status test_is_string_init_c_string(char* buffer, int length);
Status test_is_string_destroy(char* buffer, int length);
Status test_is_string_concat(char* buffer, int length);
Status test_is_string_size_c_string(char* buffer, int length);
Status test_is_string_capacity_c_string(char* buffer, int length);
Status test_is_string_capacity_c_string_return_0(char* buffer, int length);
Status test_is_string_capacity_c_string_another(char* buffer, int length);
Status test_is_string_size_c_string_another(char* buffer, int length);
Status test_is_string_insertion_again(char* buffer, int length);
Status test_is_string_extraction_again(char* buffer, int length);
Status test_is_string_compare_work_again(char* buffer, int length);
Status test_is_string_concat_again(char* buffer, int length);
Status test_is_string_destroy_again(char* buffer, int length);
Status test_is_string_pop_plus(char* buffer, int length);
Status test_is_string_push_plus(char* buffer, int length);
Status test_is_string_not_at(char* buffer, int length);
#endif
