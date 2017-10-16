#ifndef global_variables_h_
#define global_variables_h_

#include <vector>
#include "struct_particle.h"
using std::vector;

extern vector<PARTICLE> particles; 

extern vector<vector<int>> neighbors_list;

extern vector<vector<int>> neighbors_list_wall;

#endif