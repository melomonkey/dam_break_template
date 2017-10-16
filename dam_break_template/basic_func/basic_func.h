
#ifndef basic_func_h_
#define basic_func_h_

double kernel_function(double dis, double h);
double kernel_function_1dev(double dis, double h);
double kernel_function_2dev(double dis, double h);

/* * * * * * * * * * * * * * * * * * * * * */

double constrain_d(double val, double min, double max);
float constrain_f(float val, float min, float max);
int constrain_i(int val, int min, int max);

/* * * * * * * * * * * * * * * * * * * * * */

double dot_prod_3_d(double * v1, double * v2);
float dot_prod_3_f(float * v1, float * v2);
int dot_prod_3_i(int * v1, int * v2);

/* * * * * * * * * * * * * * * * * * * * * */

void cross_prod_3_d(double * v1, double * v2, double * ans);
void cross_prod_3_f(float * v1, float * v2, float * ans);
void cross_prod_3_i(int * v1, int * v2, int * ans);

/* * * * * * * * * * * * * * * * * * * * * */

double modulus_3_d(double * v);
float modulus_3_f(float * v);
int modulus_3_i(int * v);

/* * * * * * * * * * * * * * * * * * * * * */

#endif 