#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"constants.h"

signed char** unflatten_array(signed char* arr);

signed char transform_signed(char ch){
  if(ch == 0){
    return -1;
  }
  return ch;
}

int sum_array(char* arr, int len){
  int sum = 0;

  for(int i = 0; i < len; i++){
    sum += arr[i];
  }

  return sum;

}

// change from 8           vvv
void print_array(char arr[L][L]){
  printf("\n\n");

  for(int i = 0; i < L; i++){
    for(int j = 0; j < L; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}


void print_flattened_array_as_char(signed char* arr){
  signed char** unflattened_arr = unflatten_array(arr);

  printf("\n\n");

  for(int i = 0; i < L; i++){
    for(int j = 0; j < L; j++){
      char curr;
      // to convert to 'O'
      if(unflattened_arr[i][j] == 0 || unflattened_arr[i][j] == -1){
        curr = '.';
      } else {
        curr = '@';
      }

      printf("%c ", curr);
    }
    printf("\n");
  }


  printf("\n\n");
}

void print_array_as_char(signed char** arr){
  printf("\n\n");

  for(int i = 0; i < L; i++){
    for(int j = 0; j < L; j++){
      char curr;
      // to convert to 'O'
      if(arr[i][j] == 0 || arr[i][j] == -1){
        curr = '.';
      } else {
        curr = '@';
      }

      printf("%c ", curr);
    }
    printf("\n");
  }
}

signed char* flatten_array(signed char** arr){

  int arr_len = L * L;
  int vec_ind = 0;
  char* out_arr = malloc(arr_len);


  for(int i = 0; i < L; i++){
    for(int j = 0; j < L; j++){
      out_arr[vec_ind] = arr[i][j];
      vec_ind++;
    }
  }
  return out_arr;
}

signed char** unflatten_array(signed char* arr){

  signed char** out_arr = malloc(L * sizeof(char*));

  // allocate 2d array            could add own fucntion to utils file
  if(!out_arr){
    printf("Error mallocing out array\n");
    return NULL;
  }

  for(int i = 0; i < L; i++){
    out_arr[i] = malloc(L * sizeof(char));
  }


  for(int i = 0; i < L*L; i++){

    out_arr[i / L][i % L] = arr[i];
  }

  //print the array 
  for(int i = 0; i < L; i++){
    for(int j = 0; j < L; j++){
      printf("%d ", out_arr[i][j]);
    }
    printf("\n");
  }

  return out_arr;
}

void combine_weight_matrices(signed char** matrix_1, signed char** matrix_2){
  for(int i = 0; i < L*L ; i++){
    for(int j = 0; j < L*L ; j++){
      matrix_1[i][j] = matrix_1[i][j] + matrix_2[i][j];
    }
  }
}

















