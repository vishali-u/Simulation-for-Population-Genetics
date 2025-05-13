// Header file for simulation functions
#include <stdbool.h>

typedef struct {
    int population_size; // Number of individuals in the population
    int generations;     // Number of generations to simulate
    double initial_allele_frequency; // Initial frequency of the allele
    int num_reps; // Number of repetitions for the simulation
    bool enable_mutation; // Flag to enable mutation
    bool enable_selection; // Flag to enable selection 
    double mutation_rate; // Mutation rate for the allele
    double selection_coefficient; // Selection coefficient for the allele
} SimParameters;

typedef struct {
    int replicate; // Replicate number
    int population_size; // Population size
    int generation; // Generation number
    int initial_allele_frequency; // Initial allele frequency
    int final_allele_frequency; // Final allele frequency
} SimResults;

/*
 * Run the Wright-Fisher simulation with the given parameters.
 * Writes the results to a specified output file.
*/
void run_simulation(SimParameters params);





