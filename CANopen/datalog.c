#include <stdio.h>
#include <stdlib.h>
#include "datalog.h"

FILE *fptr;

void init_datalog()
{
  	fptr = fopen("test_datalog.txt","w");
  	printf("fopen\n");
	return;
}

void print_data(double *data, int size)
{
	for(int i = 0; i < size; i++)
	{
		fprintf(fptr, " %f,", data[i]);
	}

	fprintf(fptr, "\n");
	
	return;
}

void close_datalog()
{
	printf("fclose\n");
	fclose(fptr);
	printf("fclose\n");
	return;
}

