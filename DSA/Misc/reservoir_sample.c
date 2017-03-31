/**
 * Reservoir sampling is a family of randomized algorithms for randomly choosing a sample
 * of k items from a list P containing n items, where n is either a very large or unknown
 * number. Typically n is large enough that the list doesn't fit into main memory.
 *
 * https://en.wikipedia.org/wiki/Reservoir_sampling
 */

#include <stdio.h>
#include <stdlib.h>

#define POPULATION_SIZE 2000
#define SAMPLE_SIZE 100

unsigned int get_random_value(unsigned int min, unsigned int max)
{
    return arc4random_uniform(max - min) + min;
}

int *reservoir_sample(int *population)
{
    unsigned int i, j;

    int *sample = (int *) calloc(SAMPLE_SIZE, sizeof(int));

    for (i = 0; i < SAMPLE_SIZE; i++) {
        sample[i] = population[i];
    }

    for (i = SAMPLE_SIZE + 1; i < POPULATION_SIZE; i++) {
        j = get_random_value(1, i + 1);
        if (j <= SAMPLE_SIZE) {
            sample[j] = population[i];
        }
    }

    return sample;
}

int main()
{
    int population[POPULATION_SIZE];

    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = get_random_value(1, POPULATION_SIZE);
    }

    int *sample = reservoir_sample(population);

    for (int i = 0; i < SAMPLE_SIZE; i++) {
        printf("%d ", sample[i]);
    }

    return 0;
}
