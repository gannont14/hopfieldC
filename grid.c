#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"raylib.h"
#include"constants.h"

const int cell_width = SCREEN_WIDTH / NUM_COLS;
const int cell_height = SCREEN_HEIGHT / NUM_ROWS;

typedef struct {
  int i;
  int j;
  bool selected;
} grid_cell;

grid_cell grid[NUM_ROWS][NUM_COLS];

void init_grid(){
  for(int i = 0; i < NUM_ROWS; i++){
    for(int j = 0; j < NUM_COLS; j++){
      grid[i][j] = (grid_cell){
          .i = i, 
          .j = j,
          .selected = false
        };
      
    }
  }
}

void draw_grid(){
  for(int i = 0; i < NUM_ROWS; i++){
    for(int j = 0; j < NUM_COLS; j++){
      Color color = RAYWHITE;
      grid_cell curr_cell = grid[i][j];
      if(curr_cell.selected) color = BLACK;
      DrawRectangle(cell_width * j, cell_height * i, cell_width, cell_height, color);
    }
  }
}

void activate_cell(int i, int j, int draw_mode){
  if(draw_mode){
    grid[i][j].selected = true;
  } else{
    grid[i][j].selected = false;
  }
}

signed char** translate_grid_to_arr(){
  // allocate the char array
  signed char** out_arr = malloc(L * sizeof(char*));

  // allocate each row 
  for(int i = 0; i < L; i++){
    out_arr[i] = malloc(L * sizeof(char));
  }

  // loop through the grid to check states of the nodes
  for(int i = 0; i < NUM_ROWS; i++){
    for(int j = 0; j < NUM_COLS; j++){
        out_arr[i][j] = grid[i][j].selected;
    }
  }

  printf("Set up the out_arr\n");

  return out_arr;

}







