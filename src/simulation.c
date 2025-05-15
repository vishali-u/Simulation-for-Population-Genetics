// Functions to run the Wright-Fisher simulation
#include "simulation.h"
#include <stdio.h>
#include <time.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/*
* Run the Wright-Fisher simulation with the given parameters.
* Return a pointer to the results structure.
*/
SimResult *run_simulation(SimParameters params) {

    // Initialize random number generator (RNG)
    // Use the Mersenne Twister algorithm 
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, time(NULL)); // seeds the RNG

    int N = params.population_size;
    double p;

    // Initialize an array to store the results of each replicate
    SimResult *results = malloc(params.num_reps * params.generations * sizeof(SimResult));

    if (results == NULL) {
        perror("malloc");
        exit(1);
    }
    
    // Run the simulations for the given number of replicates
    int replicate_index = 1;
    for (int rep = 1; rep < params.num_reps + 1; rep++) {
        p = params.initial_allele_frequency;
        SimResult result;

        for (int gen = 1; gen < params.generations + 1; gen++) {
            unsigned int X; 
            if (params.enable_mutation) {
                // Apply mutation
                double p_mut = p * (1 - params.forward_mutation_rate - params.backward_mutation_rate) + params.backward_mutation_rate;
                X = gsl_ran_binomial(r, p_mut, (2 * N));
            } else {
                X = gsl_ran_binomial(r, p, (2 * N)); 
            }
            p = (double) X / (2 * N);

            // Store results of current generation
            result.replicate = rep;
            result.population_size = N;
            result.generation = gen;
            result.initial_allele_frequency = params.initial_allele_frequency;
            result.final_allele_frequency = p;
            results[replicate_index] = result;
            replicate_index++;
        }
    }

    gsl_rng_free(r);
    return results;
}

/*
* Write the results to a file called "simulation_results.txt".
*/
void writeResultsToFile(SimResult *results, int num_results) {
    FILE *output_file = fopen("simulation_results.tsv", "w");

    if (output_file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Add the header to the output file
    fprintf(output_file, "Replicate\tPopulation Size\tGeneration\tInitial Allele Frequency\tFinal Allele Frequency\n");

    // Write the results to the output file
    for (int i = 0; i < num_results; i++) {
        fprintf(output_file, "%d\t%d\t%d\t%.2f\t%.2f\n",
                results[i].replicate,
                results[i].population_size,
                results[i].generation,
                results[i].initial_allele_frequency,
                results[i].final_allele_frequency);
    }

    fclose(output_file);
    free(results);
}