// Functions to run the Wright-Fisher simulation
#include "simulation.h"
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/*
* Run the Wright-Fisher simulation with the given parameters.
* Return a pointer to the results structure.
*/
SimResults *runSimulation(SimParameters params) {

    // Initialize random number generator (RNG)
    // Use the Mersenne Twister algorithm 
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, time(NULL)); // seeds the RNG

    int N = params.population_size;
    double p;

    // Initialize an array to store the results of each replicate
    SimResults *results = malloc(params.num_reps * params.generations * sizeof(SimResults));

    if (results == NULL) {
        perror("malloc");
        exit(1);
    }

    // TODO: Write each replicate result to a file
    // Run the simulations for the given number of replicates
    int replicate_index = 0;
    for (int rep = 0; rep < params.num_reps; rep++) {
        p = params.initial_allele_frequency;
        SimResults result;

        for (int gen = 0; gen < params.generations; gen++) {
            unsigned int X = gsl_ran_binomial(r, p, (2 * N));
            double p = (double) X / (2 * N);

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

    return results, params.num_reps * params.generations;
}

void writeResultsToFile(SimResults *results, int num_results) {
    
}