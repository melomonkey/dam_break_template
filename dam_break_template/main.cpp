#include <iostream>
#include <vector>
#include <fstream>
#include "struct_particle.h"
#include "configuration.h"
#include "global_variables.h"
#include "io\input.h"
#include "io\output.h"
#include "initialization\field_initialization.h"
#include "update_calculation.h"
#include "basic_func\basic_func.h"
using namespace std;

void renew(double); 
void renew1(double); 

void main()
{
	/* * * * * * * * * * * * * * * */

	/* Fist time run */
	//{
	//	void input_initial_water();
	//	void generate_neighbors_list();
	//	void dambreak3d_field_initialization();
	//	void initial_particles_mass(vector<vector<int>> neighbors_list, vector<PARTICLE> & particles);

	//	input_initial_water();
	//	//generate_neighbors_list();
	//	dambreak3d_field_initialization();
	//	//initial_particles_mass(neighbors_list, particles);

	//	output_saved();
	//	output_tecplot();
	//}

	/* * * * * * * * * * * * * * * * * * * * * * * * */


	/* Restart the program */
	void input_saved();
	input_saved();
	for (int i = 0; i < particles.size(); ++i) particles[i].density.val[1] = 0.0; 
	/* * * * * * * * * * * * * * * * * * * * * * * * */

	int cnt = 0; 
	int plt_cnt = 0; 
	double dt = 1e-4;  

	while(1) 
	{
		if(cnt == 4) 
		{
			renew(dt);
			cnt = 0; 
		}
		else
		{
			renew1(dt); 
		}

		if( ((int)(particles[0].time.val[0] / dt)) % 25 == 0) 
		{
			output_tecplot();
			output_saved();
			plt_cnt = 0; 
		} 

		 

		plt_cnt ++; 
		cnt ++; 
	}

	system("pause"); 
}