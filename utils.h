#include "constants.h"

void print_array(char arr[L][L]);
void print_array_as_char(signed char** arr);
void print_flattened_array_as_char(signed char* arr);
signed char* flatten_array(char arr[L][L]);
signed char** unflatten_array(char* arr);
int sum_array(char* arr, int len);
signed char transform_signed(char);
void combine_weight_matrices(signed char** matrix_1, signed char** matrix_2);
