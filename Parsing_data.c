
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//PARSE THE DATA CSV FILE AND STORE INTO ARRAY OF STRUCTS

typedef struct key_value
{
	char Merchant_id[50];
	char Average_Amount_or_transaction_per_day[50];
	char Transaction_amount[50];
    char Is_declined[50];
    char Total_Number_of_declines_per_day[50];
    char isForeignTransaction[50];
    char isHighRiskCountry[50];
    char Daily_chargeback_avg_amt[50];
    char Six_month_avg_chbk_amt[50];
    char Six_month_chbk_freq[50];
    char isFradulent[50];            // and so on for required no. of columns.
}dict;

int main()
{
	// Initialize the file pointers
	FILE *fp = fopen("F:\\College Study Material\\Minor\\Dataset\\creditcardshort.csv  ", "r"); //open in read mode
	if (!fp)
	{
		printf("error occured");
		return 0;
	}
	char buff[1024];      								  // stores the first 1024 lines into buff
	int row_count = 0;
	int field_count = 0;
	dict values[999];  										   //array to structs to store values

	int i = 0;
	while(fgets(buff, 1024, fp))
	{
		field_count = 0;
		row_count++;
		if(row_count == 1)
		{
			continue;
        }														// we did not want to take the labels
		char *field = strtok(buff, ",");   						// seperate buff with commas
		while(field)
		{
		    if(field_count == 0)
			{
				strcpy(values[i].Merchant_id, field);
			}

			if(field_count == 1)
			{
				strcpy(values[i].Average_Amount_or_transaction_per_day, field);
			}

			if(field_count == 2)
			{
				strcpy(values[i].Transaction_amount, field);
			}

            if(field_count == 3)
			{
				strcpy(values[i].Is_declined, field);
			}

            if(field_count == 4)
			{
				strcpy(values[i].Total_Number_of_declines_per_day, field);
			}

            if(field_count == 5)
			{
				strcpy(values[i].isForeignTransaction, field);
			}

            if(field_count == 6)
			{
				strcpy(values[i].isHighRiskCountry, field);
			}

            if(field_count == 7)
			{
				strcpy(values[i].Daily_chargeback_avg_amt, field);
			}

            if(field_count == 8)
			{
				strcpy(values[i].Six_month_avg_chbk_amt, field);
			}

            if(field_count == 9)
			{
				strcpy(values[i].Six_month_chbk_freq, field);
			}

            if(field_count == 10)
			{
				strcpy(values[i].isFradulent, field);
			}

			field = strtok(NULL, ",");        //Update field value
			field_count++;

		}
		i++;
	}
	fclose (fp);

//now lets create a function to print all the values of the array.


	printValues(values);

	return 0;
}


void printValues(dict values[])
{
	for(int i =0; i<999; i++)
	{
		printf("Merchant_id -> %d, Average_Amount_or_transaction_per_day -> %d, Transaction_amount -> %d, Is_declined -> %d, Total_Number_of_declines_per_day -> %d, isForeignTransaction -> %d, isHighRiskCountry -> %d, Daily_chargeback_avg_amt -> %d, Six-month_avg_chbk_amt -> %d, Six-month_chbk_freq -> %d, isFradulent -> %d  \n \n", values[i].Merchant_id, values[i].Average_Amount_or_transaction_per_day, values[i].Transaction_amount, values[i].Is_declined, values[i].Total_Number_of_declines_per_day, values[i].isForeignTransaction, values[i].isHighRiskCountry, values[i].Daily_chargeback_avg_amt, values[i].Six_month_avg_chbk_amt, values[i].Six_month_chbk_freq, values[i].isFradulent);
	}
}
