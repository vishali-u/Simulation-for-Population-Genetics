# Simulation for Population Genetics (Wright-Fisher Model)
Using a Wright-Fisher model, this command-line tool simulates the change in allele frequencies over multiple generations. It also extends the Wright-Fisher model by considering mutation according to Tataru et al., 2017. They determined that $z_{r+1} | z_{r} \sim Binom(2N, (1 - u - v)p + v)$, where $z_{r}$ is the allele frequency of A in generation $r$, $z_{r+1}$ is the allele frequency of A in generation $r+1$, $N$ is the population size, $u$ is the forward mutation rate (A -> a), v is the backward mutation rate (a -> A), and $p$ is the allele frequency of A (Tataru et al., 17). 

# Dependencies
* GCC
* GSL
* Python 3
   * matplotlib
   * pandas
 
# Input
This simulation accepts the following arguments:
* ```--population_size```: (int) Number of individuals in each generation
* ```--generations```: (int) Number of generations to simulate
* ```--initial_allele_frequency```: (float) Starting frequency of the allele A (0.0–1.0)
* ```--num_reps```: (int) Number of replicate simulations
* ```--enable_mutation```: (flag) Enable mutation (optional)
* ```--foward_mutation_rate```: (float) Forward mutation rate, A -> a (only valid if mutation is enabled)
* ```--backward_mutation_rate```: (float) Backward mutation rate, a -> A (only valid if mutation is enabled)

# Build Instructions
1. Make sure all dependencies are installed
2. Clone the repository
```bash
git clone https://github.com/vishali-u/Simulation-for-Population-Genetics
cd Simulation-for-Population-Genetics
```
3. Compile the program
```bash
make
```

# Running Instructions
1. Run the simulation with command-line arguments:
```bash
./main --population_size 1000 \
       --generations 50 \
       --initial_allele_frequency 0.03 \
       --num_reps 5 \
       --enable_mutation \
       --forward_mutation_rate 0.001 \
       --backward_mutation_rate 0.002
```
2. The results will be stored in the project directory in a file called ```simulation_results.tsv```.

3. Plot the results:
```bash
python3 scripts/plot.py
```

# References
 1. Tataru, P., Simonsen, M., Bataillon, T., & Hobolth, A. (2017). Statistical Inference in the Wright-Fisher Model Using Allele Frequency Data. Systematic biology, 66(1), e30–e46. https://doi.org/10.1093/sysbio/syw056
      * Eq. 10 was used in this simulation
 

