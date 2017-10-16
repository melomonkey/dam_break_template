#include "..\struct_particle.h"
#include "..\configuration.h"
#include "..\global_variables.h"
#include "..\update_calculation.h"
#include <ctime>
using namespace std;

void renew(double dt)
{
	{
		generate_neighbors_list();
		printf("Generating the Neighbor List...Done"); printf("\n");
	}

	{
		density_update_schm1_multi_threads(neighbors_list, particles, dt, 9);
		density_filter1_multi_threads(neighbors_list, particles, 9);
		printf("Density Update...Done"); printf("\n");
	}

	{
		pressure_update_schm1_multi_threads(neighbors_list, particles, 9);
		printf("Pressure Update...Done"); printf("\n");
	}

	{
		acc_pressure_term_update_schm1_multi_threads(neighbors_list, particles, 9);
		printf("Acceleration Update...Done"); printf("\n");
	}

	{
		velocity_update_schm1_multi_threads(neighbors_list, particles, dt, 9);
		velocity_filter1_multi_threads(neighbors_list, particles, 9);
		printf("Velocity Update...Done"); printf("\n");
	}

	{
		position_time_update_schm1(particles, dt);
		printf("Time and Position Update...Done"); printf("\n");
	}

	{
		support_radius_update_schm2_multi_threads(neighbors_list, particles, dt);
		printf("Radius Update...Done"); printf("\n");
	}

	printf("%12.11f s Calculation Done.\n\n\n", particles[0].time.val[0]);
}

void renew1(double dt)
{
	{
		generate_neighbors_list();
		printf("Generating the Neighbor List...Done"); printf("\n");
	}

	{
		density_update_schm1_multi_threads(neighbors_list, particles, dt, 9);
		printf("Density Update...Done"); printf("\n");
	}

	{
		pressure_update_schm1_multi_threads(neighbors_list, particles, 9);
		printf("Pressure Update...Done"); printf("\n");
	}

	{
		acc_pressure_term_update_schm1_multi_threads(neighbors_list, particles, 9);
		printf("Acceleration Update...Done"); printf("\n");
	}

	{
		velocity_update_schm1_multi_threads(neighbors_list, particles, dt, 9);
		printf("Velocity Update...Done"); printf("\n");
	}

	{
		position_time_update_schm1(particles, dt);
		printf("Time and Position Update...Done"); printf("\n");
	}

	{
		support_radius_update_schm2_multi_threads(neighbors_list, particles, dt);
		printf("Radius Update...Done"); printf("\n");
	}

	printf("%12.11f s Calculation Done.\n\n\n", particles[0].time.val[0]);
}