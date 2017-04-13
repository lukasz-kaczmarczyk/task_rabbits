#ifndef RABBITS_H
#define RABBITS_H

#include <stdio.h>
#include <stdlib.h>
//data input setting
typedef enum { NOK, OK } bool;

typedef struct data_in
{
	unsigned char day; // information after number of "day" elapsed 
	unsigned int rabbits_first; //number of rabbits in first day
	unsigned int rabbits_second; //number of rabbits in second day
	unsigned int rabbits_quantity; //number of rabbits after n days
	
	struct data_in *next;
	struct data_in *prev;
	
}data_input;

void save_to_file(char *file_name, data_input *in);
bool read_data(data_input *data_list, char *file_name);
void free_data(data_input *data_list);

#endif

