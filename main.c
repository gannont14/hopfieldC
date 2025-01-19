#include<stdio.h>
#include"raylib.h"
#include"utils.h"
#include"hopfield.h"
#include"constants.h"
#include"grid.h"

#define DRAW 1
#define ERASE 0

int draw_mode = DRAW;

int main(void) {
    /*const int screenWidth = 800;*/
    /*const int screenHeight = 450;*/

    init_grid();

    int num_patterns = 0;
    signed char** weights_matrix;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hopfield Network");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
          {
            Vector2 mPos = GetMousePosition();
            int i = mPos.y / cell_width;
            int j = mPos.x / cell_height;

            activate_cell(i, j, draw_mode);
          }

        if (IsKeyPressed(KEY_R)){
            if(weights_matrix == NULL){
              printf("Weights matrix not initialized\n");
            }
            if(num_patterns == 0){
              // first one generated
              printf("Generating first weight matrix\n");
              signed char** initial_arr;
              initial_arr = translate_grid_to_arr();
              weights_matrix = generate_weight_matrix(flatten_array(initial_arr));
            } else {
              printf("Generating next weight matrix\n");
              signed char** new_arr;
              new_arr = translate_grid_to_arr();
              update_weight_matrix(weights_matrix, flatten_array(new_arr));
            }

            num_patterns += 1;
          }

        if (IsKeyPressed(KEY_P)){
            for(int i = 0; i < L*L; i++){
              for(int j = 0; j < L*L; j++){
                char ch;
                if(weights_matrix[i][j] == -1){
                  ch = '.';
                } else if (weights_matrix[i][j] == -1){
                  ch = '%';
                } else {
                  ch = '@';
                }
                printf("%c", ch);
              }
                printf("\n");
            }
          }


        if (IsKeyPressed(KEY_E)){
            printf("draw mode erase\n");
            draw_mode = ERASE;
          }

        if (IsKeyPressed(KEY_D)){
            printf("draw mode draw\n");
            draw_mode = DRAW;
          }


        if (IsKeyPressed(KEY_F)){
            signed char** distorted_arr;
            distorted_arr = translate_grid_to_arr();
            signed char** flattened_distorted_arr;
            flattened_distorted_arr = flatten_array(distorted_arr);
            parse_all_nodes(flattened_distorted_arr, weights_matrix, 0);

            // final image
            signed char** restored_image = unflatten_array(flattened_distorted_arr);
            print_array_as_char(restored_image);
          }


        BeginDrawing();
            ClearBackground(BLACK);
            // Your drawing code goes here
            draw_grid();
        EndDrawing();
    }

    CloseWindow();

    /*draw_grid();*/

    return 0;
}

