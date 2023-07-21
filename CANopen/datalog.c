#include <stdio.h>
#include <stdlib.h>
#include "datalog.h"



void init_datalog()
{
	FILE *fptr;
  	fptr = fopen("test_datalog.txt","w");
  	printf("fopen!\n");
	return;
}

void print_data()
{
	fprintf(fptr, "test test test!!!\n");
	printf("fprint!\n");
	fclose(fptr);
	return;
}

