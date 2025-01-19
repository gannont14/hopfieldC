#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"utils.h"
#include"constants.h"


signed char parse_node(int i, signed char* vector, signed char** weight_vector, int b){
  printf("Parsing node: %d\n", i);
  int vector_len = L * L;
  int sum = 0;
  // sum the weights, need to have running tally, 
  for(int j = 0; j < vector_len; j++){
    if(i != j){

      /*printf("the transformed vector value is : %d\n", transform_signed(vector[i]));*/
      int val = transform_signed(vector[j]) * weight_vector[i][j];

      sum += val;
    }
  }

  // found the sum of the node, if above or equal to threshold, return 1, otherwise -1
  if(sum >= b){
    /*printf("The sum of the nodes was greater than the threshold\nsum: %d\n" ,sum);*/
    return 1;
  } else{
    /*printf("The sum of the nodes was less than the threshold\nsum: %d\n" ,sum);*/
    return -1;
  }

}

void parse_all_nodes(signed char* vector, signed char** weight_vector, int b){
  int vec_len = L * L;

  for(int i = 0; i < vec_len; i++){
    signed char node_state;
    node_state =  parse_node(i, vector, weight_vector, b);

    /*printf("updating node state of %d to %d\n", i, node_state);*/

    // update all vectors with what new node state should be
    vector[i] = node_state;

    printf("\033[2J\033[1;1H");
    print_flattened_array_as_char(vector);
    usleep(10000);
  }

}

signed char** generate_weight_matrix(signed char* vector){
  int vector_len = L * L;
  printf("Vector length: %d\n", vector_len);

  printf("generating matrix of size %d X %d\n", vector_len, vector_len);
  // size of the vector that was passed in, based on L
  if(!vector) {
    printf("Error with vector init\n");
  }

  // this is so much memory for just 8 x 8 
  // the output matrix with the weight
  signed char** out_mat = malloc(vector_len * sizeof(char*));

  // allocate each row for the pointers
  if(!out_mat){
    printf("Failed to allocate out_mat pointers\n");
    return NULL;
  }

  for (int i = 0; i < vector_len; i++){
    out_mat[i] = malloc(vector_len * sizeof(char));
  }

  printf("Output matrix allocated\n");


  // find the weights for the vector, and then zero out the diagonal just in case

  // find weights of vector
  for (int i = 0; i < vector_len; i++){
    for (int j = 0; j < vector_len; j++){
      int val;
      int res = vector[i] ^ vector[j];

      if(res == 0){
        val = 1;
      }

      if(res == 1){
        val = -1;
      }


      if (i == j) val = 0; // fills the diagonol with 0s
      // only need to loop through this many times, and set both combinations
      // XOR to find out what the value of the weight should be
      out_mat[i][j] = val;
      out_mat[j][i] = val;
    }
  }



  // print at the end
  /*for (int i = 0; i < vector_len; i++){*/
  /*  for (int j = 0; j < vector_len; j++){*/
  /*    printf("%d ", out_mat[i][j]);*/
  /*  }*/
  /*  printf("\n");*/
  /*}*/


  return out_mat;
}



void update_weight_matrix(signed char** weight_matrix, signed char* vector){
  // Take the flattened Vector and generate weight matrix
  char** new_weight_matrix = generate_weight_matrix(vector);

  // add the weight matrix to the existing one
  combine_weight_matrices(weight_matrix, new_weight_matrix);
}



















