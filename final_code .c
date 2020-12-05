#include<stdio.h>	//to use the printf function
#include<conio.h>   //to use the getche function
#include<stdlib.h>  //to use the rand function
#include<string.h>


struct Individual
{
    int fitness;
    int geneLength;
    int genes[209];
};

typedef struct key_value
{
	char Time[50];
	char V1[50];
	char V2[50];
	char V3[50];
    char V4[50];
    char V5[50];
    char V6[50];
    char V7[50];
    char V8[50];
    char V9[50];
    char V10[50];
    char V11[50];
    char V12[50];
    char V13[50];
    char V14[50];
    char V15[50];
    char V16[50];
    char V17[50];
    char V18[50];
    char V19[50];
    char V20[50];
    char V21[50];
    char V22[50];
    char V23[50];
    char V24[50];
    char V25[50];
    char V26[50];
    char V27[50];
    char V28[50];
    char Amount[50];
    char Class[50];            // and so on for required no. of columns.
}dict;

/*---------------------------------------------------------------------------------------------------------------------*/



int main()
{

    int num;			// num is the no. of iterations
    int i,j;

    printf("\nWelcome to the Genetic Algorithm coded for Minor 1 \n"); // introduction to the program

enter: printf("\nPlease enter a positive number:  ");
    scanf("%d",&num);       // enter the no. of iterations in num


    if(num<1)                    // if a -ve number is inserted .. enter num again
    goto enter;

    	// Initialize the file pointers
	FILE *fp = fopen("E:\\Study Material\\New folder\\Book1.csv", "r"); //open in read mode
	if (!fp)
	{
		printf("error occured");
		return 0;
	}
	char buff[1024];      								  // stores the first 1024 lines into buff
	int row_count = 0;
	int field_count = 0;
	dict values[210];  										   //array to structs to store values

	i = 0;
	while(fgets(buff, 1024, fp))
	{
		field_count = 0;
		row_count++;
		if(row_count == 1)
		{
			continue;
        }												// we did not want to take the labels
		char *field = strtok(buff, ",");   						// seperate buff with commas
		while(field)
		{
			if(field_count == 0)
			{
				strcpy(values[i].Time, field);
			}

			if(field_count == 1)
			{
				strcpy(values[i].V1, field);
			}

			if(field_count == 2)
			{
				strcpy(values[i].V2, field);
			}

			if(field_count == 3)
			{
				strcpy(values[i].V3, field);
			}

            if(field_count == 4)
			{
				strcpy(values[i].V4, field);
			}

            if(field_count == 5)
			{
				strcpy(values[i].V5, field);
			}

            if(field_count == 6)
			{
				strcpy(values[i].V6, field);
			}

            if(field_count == 7)
			{
				strcpy(values[i].V7, field);
			}

            if(field_count == 8)
			{
				strcpy(values[i].V8, field);
			}

            if(field_count == 9)
			{
				strcpy(values[i].V9, field);
			}

            if(field_count == 10)
			{
				strcpy(values[i].V10, field);
			}

            if(field_count == 11)
			{
				strcpy(values[i].V11, field);
			}

            if(field_count == 12)
			{
				strcpy(values[i].V12, field);
			}

			if(field_count == 13)
			{
				strcpy(values[i].V13, field);
			}

			if(field_count == 14)
			{
				strcpy(values[i].V14, field);
			}

			if(field_count == 15)
			{
				strcpy(values[i].V15, field);
			}

			if(field_count == 16)
			{
				strcpy(values[i].V16, field);
			}

			if(field_count == 17)
			{
				strcpy(values[i].V17, field);
			}

			if(field_count == 18)
			{
				strcpy(values[i].V18, field);
			}

			if(field_count == 19)
			{
				strcpy(values[i].V19, field);
			}

			if(field_count == 20)
			{
				strcpy(values[i].V20, field);
			}

			if(field_count == 21)
			{
				strcpy(values[i].V21, field);
			}

			if(field_count == 22)
			{
				strcpy(values[i].V22, field);
			}

			if(field_count == 23)
			{
				strcpy(values[i].V23, field);
			}

			if(field_count == 24)
			{
				strcpy(values[i].V24, field);
			}

			if(field_count == 25)
			{
				strcpy(values[i].V25, field);
			}

			if(field_count == 26)
			{
				strcpy(values[i].V26, field);
			}

			if(field_count == 27)
			{
				strcpy(values[i].V27, field);
			}

			if(field_count == 28)
			{
				strcpy(values[i].V28, field);
			}

			if(field_count == 29)
			{
				strcpy(values[i].Amount, field);
			}

			if(field_count == 30)
			{
				strcpy(values[i].Class, field);
			}

			field = strtok(NULL, ",");        //Update field value
			field_count++;

		}
		i++;
	}
	fclose (fp);

//now lets create a function to print all the values of the array.


	printValues(values);

	int chromosome[300];

	/*Code for fitness*/

    struct Individual obj[210];                          //for loop used for calculating the fitness of individual object
	for(int k=0;k<210;k++)
    {
		initialize(&obj[k]);
    	calculateFitness(&obj[k]);
	}

    selection(&obj);                                     //function for roulette wheel



    return 0;
}                                            	//end of main

/*---------------------------------------------FOR PRINTING THE DATA IN CSV FILE---------------------------------------------------------*/

void printValues(dict values[])
{
	for(int i =0; i<208; i++)
	{
		printf("Time -> %s, V1 -> %s, V2 -> %s, V3 -> %s, V4 -> %s, V5 -> %s, V6 -> %s, V7 -> %s, V8 -> %s, V9 -> %s, V10 -> %s, V11 -> %s, V12 -> %s, V13 -> %s, V14 -> %s, V15 -> %s, V16 -> %s, V17 -> %s, V18 -> %s, V19 -> %s, V20 -> %s, V21 -> %s, V22 -> %s, V23 -> %s, V24 -> %s, V25 -> %s, V26 -> %s V27 -> %s, V28 -> %s, Amount -> %s, Class -> %s \n \n", values[i].Time, values[i].V1, values[i].V2, values[i].V3, values[i].V4, values[i].V5, values[i].V6, values[i].V7, values[i].V8, values[i].V9, values[i].V10, values[i].V11, values[i].V12, values[i].V13, values[i].V14, values[i].V15, values[i].V16, values[i].V17, values[i].V18, values[i].V19, values[i].V20, values[i].V21, values[i].V22, values[i].V23, values[i].V24, values[i].V25, values[i].V26, values[i].V27, values[i].V28, values[i].Amount, values[i].Class);
	}
}

/*-------------------------------------------------------------------------------------------------------*/

/* Code for fitness criteria */

void initialize(struct Individual* obj)
{
    obj->fitness = 0;
    obj->geneLength = 6;
    for(int i=0; i<obj->geneLength; i++)
    {
        obj->genes[i]=rand()%2;                         //to pick out random variable in 0 & 1 format
    }
}
void calculateFitness(struct Individual* obj)
{
    obj->fitness = 0;
    for (int i = 0; i < obj->geneLength; i++)
    {
        if (obj->genes[i] == 0)
        {
            ++obj->fitness;
        }
    }
}
/*----------------------------------------------------------------------------------------------------------*/


/*Roulett wheel implementation*/

void selection(struct Individual *chromosome)
{

    double totalFitness = 0;
    double totalProbability = 0;
    double rndNumber;
    double min,max;

    int i;

    min = 0.0;
    max = 1.0;

    int POPULATION_SIZE = 209;

	double probability[209];
	for(i=0; i<POPULATION_SIZE; i++)
    {
        totalFitness += chromosome[i].fitness;
    }

    for(i=0; i<POPULATION_SIZE; i++)
    {
        probability[i] = (chromosome[i].fitness)/totalFitness;
        printf("Chromosome %d with probability %f\n",i, probability[i]);
    }
            printf("Chromosome %d selected \n",POPULATION_SIZE);

}
/*-------------------------------------------------------------------------------------------------------*/

