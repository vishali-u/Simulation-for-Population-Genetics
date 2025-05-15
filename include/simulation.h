// Header file for simulation functions
#include <stdbool.h>

typedef struct {
    int population_size; // Number of individuals in the population
    int generations;     // Number of generations to simulate
    double initial_allele_frequency; // Initial frequency of the allele (A)
    int num_reps; // Number of repetitions for the simulation
    bool enable_mutation; // Flag to enable mutation
    bool enable_selection; // Flag to enable selection 
    double forward_mutation_rate; // Forward mutation rate for the allele (A -> a)
    double backward_mutation_rate; // Backward mutation rate for the allele (a -> A)
    double selection_coefficient; // Selection coefficient for the allele
} SimParameters;

typedef struct {
    int replicate; // Replicate number
    int population_size; // Population size
    int generation; // Generation number
    double initial_allele_frequency; // Initial allele frequency
    double final_allele_frequency; // Final allele frequency
} SimResult;

/*
 * Run the Wright-Fisher simulation with the given parameters.
 * Writes the results to a specified output file.
*/
SimResult *run_simulation(SimParameters params);

/*
* Write the results to a file called "simulation_results.txt".
*/
void writeResultsToFile(SimResult *results, int num_results);




