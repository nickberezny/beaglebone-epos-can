#include <stdio.h>
#include <stdlib.h>
#include "datalog.h"

FILE *fptr;

void init_datalog()
{
	printf("fopen!\n");
  	fptr = fopen("test_datalog.txt","w");
  	printf("fopen!\n");
	return;
}

void print_data()
{
	printf("fprint!\n");
	fprintf(fptr, "test test test!!!\n");
	printf("fprint!\n");
	fclose(fptr);
	return;
}

