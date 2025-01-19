extern const int cell_width;
extern const int cell_height;

void draw_grid();
void init_grid();
void activate_cell(int i, int j, int draw_mode);
signed char** translate_grid_to_arr();
