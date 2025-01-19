signed char** generate_weight_matrix(signed char* vector);
signed char parse_node(int i, signed char* vector, signed char** weight_vector, int b);
void parse_all_nodes(signed char* vector, signed char** weight_vector, int b);
void update_weight_matrix(signed char** weight_matrix, signed char* vector);
