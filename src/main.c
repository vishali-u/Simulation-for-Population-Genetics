// Entry-point for the program
// Initialize the program, check command line arguments, and run the simulation

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "simulation.h"

static struct option long_options[] = {
    {"population_size", required_argument, 0, 'N'},
    {"generations", required_argument, 0, 'G'},
    {"initial_allele_frequency", required_argument, 0, 'p'},
    {"num_reps", required_argument, 0, 'r'},
    {"enable_mutation", no_argument, 0, 'm'},
    {"enable_selection", no_argument, 0, 's'},
    {"forward_mutation_rate", required_argument, 0, 'F'},
    {"backward_mutation_rate", required_argument, 0, 'B'},
    {"selection_coefficient", required_argument, 0, 'S'},
    {0, 0, 0, 0}
};

/*
* Parse command line arguments and set the simulation parameters.
*/
SimParameters parse_arguments(int argc, char *argv[]) {
    int c;
    int option_index = 0; 
    SimParameters params = {0};

    // Parse command line arguments
    while ((c = getopt_long(argc, argv, "N:G:p:r:msF:B:S:", long_options, &option_index)) != -1) {
        switch (c) {
            case 'N':
                params.population_size = atoi(optarg);
                break;
            case 'G':
                params.generations = atoi(optarg);
                break;
            case 'p':
                params.initial_allele_frequency = atof(optarg);
                break;
            case 'r':
                params.num_reps = atoi(optarg);
                break;
            case 'm':
                params.enable_mutation = true;
                break;
            case 's':
                params.enable_selection = true;
                break;
            case 'F':
                params.forward_mutation_rate = atof(optarg);
                if (!params.enable_mutation) {
                    fprintf(stderr, "Mutation rate was given but the flag is not set. Please check your input.\n");
                    exit(1);
                }
                break;
            case 'B':
                params.backward_mutation_rate = atof(optarg);
                if (!params.enable_mutation) {
                    fprintf(stderr, "Mutation rate was given but the flag is not set. Please check your input.\n");
                    exit(1);
                }
                break;
            case 'S':
                params.selection_coefficient = atof(optarg);
                if (!params.enable_selection) {
                    fprintf(stderr, "Selection coefficient was given but the flag is not set. Please check your input.\n");
                    exit(1);
                }
                break;
            case '?':
                // Handle unknown options
                fprintf(stderr, "Unknown option: %s\n", argv[optind - 1]);
                exit(0);
            default:
                fprintf(stderr, "Usage: %s --population_size N --generations G --initial_allele_frequency p --num_reps r [--enable_mutation] [--enable_selection] [--mutation_rate M] [--selection_coefficient S]\n", argv[0]);
                exit(0);
        }
    }
    return params;
}

/*
* Check if all the parameters are valid.
* If not, print an error message and exit the program.
*/
void validate_parameters(SimParameters params) {

    if (params.population_size <= 0) {
        fprintf(stderr, "Invalid population size. Please check your input.\n");
        exit(1);
    }
    if (params.generations <= 0) {
        fprintf(stderr, "Invalid number of generations. Please check your input.\n");
        exit(1); 
    }
    if (params.initial_allele_frequency < 0 || params.initial_allele_frequency > 1) {
        fprintf(stderr, "Invalid initial allele frequency. Please check your input.\n");
        exit(1); 
    }
    if (params.num_reps <= 0) {
        fprintf(stderr, "Invalid initial allele frequency. Please check your input.\n");
        exit(1); 
    }
    if (params.forward_mutation_rate < 0 || params.forward_mutation_rate > 1) {
        fprintf(stderr, "Invalid mutation rate. Please check your input.\n");
        exit(1);
    }
    if (params.backward_mutation_rate < 0 || params.backward_mutation_rate > 1) {
        fprintf(stderr, "Invalid mutation rate. Please check your input.\n");
        exit(1);
    }
    if (params.selection_coefficient < 0 || params.selection_coefficient > 1) {
        fprintf(stderr, "Invalid selection coefficient. Please check your input.\n");
        exit(1);
    }
}

/*
* Run the simulation.
*/
int main(int argc, char *argv[]) {
    // Parse command line arguments
    SimParameters params = parse_arguments(argc, argv);

    // Validate parameters
    validate_parameters(params);

    // Run the simulation
    SimResult *results = run_simulation(params);
    writeResultsToFile(results, params.num_reps * params.generations);
}