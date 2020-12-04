#include<stdio.h>
#include<stdlib.h>
struct Individual
{
    int fitness;
    int geneLength;
    int genes[5];
};
void initialize(struct Individual* obj)
{
    obj->fitness=0;
    obj->geneLength=5;
    for(int i=0;i<obj->geneLength;i++)
    {
        obj->genes[i]=rand()%2;
    }
}
void calculateFitness(struct Individual* obj)
{
    obj->fitness = 0;
    for (int i = 0; i < obj->geneLength; i++)
    {
        if (obj->genes[i] == 1)
        {
            ++obj->fitness;
        }
    }
}
int main()
{
    struct Individual obj;
    initialize(&obj);
    calculateFitness(&obj);
    printf("%d",obj.fitness);
    return 0;
}
