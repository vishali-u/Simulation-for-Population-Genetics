// Functions to run the Wright-Fisher simulation
#include "simulation.h"
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

void runSimulation(SimParameters params) {

    // Initialize random number generator (RNG)
    // Use the Mersenne Twister algorithm 
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, time(NULL)); // seeds the RNG

    int N = params.population_size;
    double p;

    // TODO: Write each replicate result to a file
    // Run the simulations for the given number of replicates
    for (int rep = 0; rep < params.num_reps; rep++) {
        p = params.initial_allele_frequency;

        for (int gen = 0; gen < params.generations; gen++) {
            unsigned int X = gsl_ran_binomial(r, p, (2 * N));
            double p = (double) X / (2 * N);
        }
    }

    gsl_rng_free(r); 
}