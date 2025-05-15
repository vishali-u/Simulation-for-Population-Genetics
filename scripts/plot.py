# Plot the simulation results
import matplotlib.pyplot as plt
import pandas as pd
import os

def main():
    results_file = "simulation_results.tsv" 

    # Check if file exists
    if not os.path.exists(results_file):
        print("Results file not found. Please run the simulation first.")
        return

    # Load the TSV file
    try:
        df = pd.read_csv(results_file, sep="\t")
    except Exception as e:
        print(f"Failed to read file: {e}")
        return

    # Plotting
    plt.figure(figsize=(10, 6))
    for rep_id, group in df.groupby('Replicate'):
        plt.plot(group['Generation'], group['Final Allele Frequency'])

    plt.xlabel("Generation")
    plt.ylabel("Allele Frequency (p)")
    plt.title("Allele Frequency Over Generations (per replicate)")
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    main()
