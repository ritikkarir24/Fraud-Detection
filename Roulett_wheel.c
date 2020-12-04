
/*Roulett wheel implementation*/


void selection(Chromosome * chromosome)
{

    double totalFitness=0;
    double totalProbability=0;
    double probability=0;
    double rndNumber;
    double min,max;

    int i;

    min=0.0;
    max=1.0;

    for(i=0;i<POPULATION_SIZE;i++)
    {
        totalFitness += chromosome[i].fitness;
    }

    for(i=0;i<POPULATION_SIZE;i++)
    {
        chromosome[i].probability = (chromosome[i].fitness)/totalFitness;
        printf("Chromosome %d with probability %f\n",i, chromosome[i].probability);
    }

    srand((unsigned)time(NULL));
    for(i=0;i<POPULATION_SIZE;i++)
    {
        rndNumber = ((double)rand()/(double)RAND_MAX);

        if(chromosome[i].probability >= rndNumber)
        {
            printf("Chromosome %d selected \n",i);
        }
    }
}


















Solution for problem:


double rndNumber = rand() / (double) RAND_MAX;
double offset = 0.0;
int pick = 0;

for (i = 0; i < POPULATION_SIZE; i++) {
    offset += chromosome[i].probability;
    if (rndNumber < offset) {
        pick = i;
        break;
    }
}

printf("Chromosome %d selected.\n", pick);
