The genetic algorithm implemented here aims to solve the N-Queens problem by evolving solutions through selection, crossover, and mutation. The problem involves placing N chess queens on an N×N chessboard so that no two queens threaten each other. This implementation utilizes a genetic algorithm approach to find optimal solutions by iteratively evolving populations of board configurations.
The parameters utilized in this algorithm include the population size (POP_SIZE) and the mutation probability (MUTATE_PROB). These parameters influence the search space exploration and solution convergence. By varying these parameters and tracking performance metrics, such as average generations and fitness, this implementation aims to analyze the algorithm's behavior under different settings.
Q.1
 
POP_SIZE	MUTATE_PROB	#Average fitness times	Average generations	Average Execution time (Sec)
16 queens	 16	 10	 305207	11133	 6.69378/30
32 queens	 32	 10	 2052780	19008	 146.015/30
64 queens	 10	 10	 1210045	65222	 343/855/30
96 queens	7	10	1898269	182376	1428.7/30
128 queens	6	6	4058859	580149	5073.55/30
Q.2 Analyzing the impact of population size and mutation rate on the search process reveals significant insights into solving the N-Queens problem efficiently.
Population Size:
The population size (POP_SIZE) directly influences the diversity and exploration capacity of the genetic algorithm. Smaller populations like 16 queens with a POP_SIZE of 16 lead to faster convergence but might compromise solution quality due to limited exploration. Larger populations, such as 32 queens with a POP_SIZE of 32, allow for greater diversity and better solutions but may require more generations to converge.
As seen in the results, increasing the population size generally results in improved average fitness times. For instance, moving from 16 queens to 32 queens with a doubled population size significantly enhances the average fitness times from 305207 to 2052780, signifying a better search performance.
Mutation Rate:
The mutation rate (MUTATE_PROB) affects the balance between exploration and exploitation. A lower mutation rate might limit the algorithm's ability to explore new solution spaces, trapping it in local optima. On the other hand, higher mutation rates can disrupt good solutions too frequently, hindering convergence.
In the provided results, maintaining a consistent mutation rate of 10% for various queen sizes appears to yield competitive average fitness times. However, varying the mutation rate for 64 and 96 queens showcased fluctuating performance, indicating a sensitive balance between exploration and exploitation.
The genetic algorithm implemented here aims to solve the N-Queens problem by evolving solutions through selection, crossover, and mutation. The problem involves placing N chess queens on an N×N chessboard so that no two queens threaten each other. This implementation utilizes a genetic algorithm approach to find optimal solutions by iteratively evolving populations of board configurations.
The parameters utilized in this algorithm include the population size (POP_SIZE) and the mutation probability (MUTATE_PROB). These parameters influence the search space exploration and solution convergence. By varying these parameters and tracking performance metrics, such as average generations and fitness, this implementation aims to analyze the algorithm's behavior under different settings.
