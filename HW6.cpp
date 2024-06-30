#include <iostream>
#include <ctime>
#include <cstdlib>
#define SIZE 128
#define POP_SIZE 6
#define MUTATE_PROB 6
#define ANS_LIMIT 30
using namespace std;

int MAX_FITNESS;
long Total_Fit = 0;

typedef struct Individual{
    int board[SIZE];
    int fitness;
} Individual;

/* print the board */
int ind_print(Individual pop[POP_SIZE], int index, int info){
    for(int b = 0;b < SIZE;b++){
        cout << pop[index].board[b] << ' ';
    }
    cout << "fit : " << pop[index].fitness << " #Generation : " << info << endl;
    return info;
}

/* random generate a board with no-duplicated queen */
void random_input(int board[SIZE]){
    int temp, r, r2;
    for(int i = 0;i < SIZE;i++){
        board[i] = i;
    }
    for(int i = 0;i < SIZE * 50;i++){
        r = rand() % SIZE;
        r2 = rand() % SIZE;
        temp = board[r];
        board[r] = board[r2];
        board[r2] = temp;
    }
}

/* fitness measure with minimum conflict value */
int fitness_measure(int board[SIZE]){
    int fitness = MAX_FITNESS;
    for(int pos = 0;pos < SIZE;pos++){
        for(int i = 1;pos + i < SIZE;i++){
            if( (board[pos + i] == board[pos]) ||
                (board[pos + i] == board[pos] + i && board[pos] + i < SIZE) ||
                (board[pos + i] == board[pos] - i && board[pos] - i >= 0) ){
                fitness--;
            }
        }
    }
    Total_Fit++;
    return fitness;
}

/*  return a index of individual, and if someone of individual has a better fitness
    , will be selected more often */
int random_select(Individual pop[POP_SIZE]){
    int sum = 0, i;
    for(i = 0;i < POP_SIZE;i++){
        sum += pop[i].fitness;
    }
    sum = rand() % sum;
    for(i = 0;i < POP_SIZE;i++){
        sum -= pop[i].fitness;
        if(sum <= 0){
            break;
        }
    }
    return i;
}

/* crossover */
void reproduce(int child[SIZE], int x[SIZE], int y[SIZE]){
    int r = rand()%SIZE;
    for(int i = 0;i <= r;i++){
        child[i] = x[i];
    }
    for(int i = r + 1;i < SIZE;i++){
        child[i] = y[i];
    }
}

/* mutate */
void mutate(int child[SIZE]){
    int prob = rand() % 100;

    if(prob < MUTATE_PROB)
    {
        int select = rand() % SIZE, new_value = rand() % SIZE;

        child[select] = new_value;
    }
}

/* calculate the maximum conflict value */
int max_fitness_measure(int size){
    int sum = 0;
    for(int i = 1;i < size;i++){
        sum += i;
    }
    return sum;
}

/*  genetic algorithm
    ref : figure 4.17, Artificial Intelligence : A Modern Approach */
int main(){
clock_t startTime = clock();
srand(time(NULL));
    MAX_FITNESS = max_fitness_measure(SIZE);

    int node = 0, a = 0, sum = 0;

    while(a < ANS_LIMIT){
        Individual new_pop[POP_SIZE];
        for(int i = 0;i < POP_SIZE;i++){
            random_input(new_pop[i].board);
            new_pop[i].fitness = fitness_measure(new_pop[i].board);
        }

        bool ans = false;
        do{
            node++;
            // copy as origin population
            Individual pop[POP_SIZE];
            for(int i = 0;i < POP_SIZE;i++){
                pop[i] = new_pop[i];
            }

            for(int i = 0;i < POP_SIZE;i++){
                int x = random_select(pop);
                int y = random_select(pop);
                // new child individual should have an equal or better fitness value
                // ref : Modified Genetic Algorithm,
                // http://www.slideshare.net/SKAhsan/modified-genetic-algorithm-for-solving-nqueens-problem-54527086
                do{
                    reproduce(new_pop[i].board, pop[x].board, pop[y].board);
                    mutate(new_pop[i].board);
                    new_pop[i].fitness = fitness_measure(new_pop[i].board);
                }while(new_pop[i].fitness < pop[x].fitness || new_pop[i].fitness < pop[y].fitness);

                if(new_pop[i].fitness == MAX_FITNESS){
                    ans = true;
                    sum += ind_print(new_pop, i, node);
                    node = 0;
                    break;
                }
            }

        }while(ans == false);
        a++;
    }
    clock_t endTime = clock();
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "POP_SIZE: " << POP_SIZE << endl;
    cout << "MUTATE_PROB: " << MUTATE_PROB << "%" << endl;
    cout << "Average #generation: " << sum / ANS_LIMIT << endl;
    cout << "Average #fitness: " << Total_Fit / ANS_LIMIT << endl;
    cout << "Execution time: " << executionTime << " seconds" << endl;

    return 0;
}
