#include "search_adachi.hpp"

void init_map(int x, int y);
void set_map(int x, int y, int mask);
void set_wall(int x, int y);
t_bool is_unknown(int x, int y);
int get_priority(int x, int y, t_global_dir dir);
int get_nextdir(int x, int y, int mask, t_global_dir *dir);