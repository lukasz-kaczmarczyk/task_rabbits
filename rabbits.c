#include "rabbits.h"



static data_input *data;

static int read_sets_number(char *file_name);
static bool create_list(data_input *head, int list_length);

bool read_data(data_input *data_list, char *file_name)
{	
	data_input *list_it;
	bool result = NOK;
	int i = 0, sets_number = 0;
	FILE *fp;
	char tmp[10];
	fp = fopen(file_name , "r");
	
	list_it = data_list;
	
	if (NULL == file_name) {
    	perror("Error: file pointer is null.");
    	result = NOK;
        }

    
        if (NULL == fgets(tmp, 6, fp)) {
     		result = NOK;
        } else {
       		sets_number = atoi(tmp);
    			
        }
	
       		
       		
        if (NOK == create_list(data_list, sets_number)) { //create list in memory{
		perror("list of data creating error!!!");
		result = NOK;
	}	
		
	for (i = 0; i < sets_number; i++) {
	    //compute_rabbits(list_it);
	}
       

   fclose(fp);
   result = atoi(tmp);
   return result;
	
	

}

void free_data(data_input **data_list)
{
   data_input *tmp;

   while (NULL != *data_list) {
       tmp = *data_list;
       *data_list = (*data_list)->next;
       free(tmp);
    }

}

int compute_rabbits(data_input in)
{
	int result, tmp1, tmp2, i = 3;
	switch (in.day) {
		case 1:
			result = in.rabbits_first;
			break;
		case 2:
			result = in.rabbits_second;
			break;
		default:
			tmp1 = in.rabbits_first;
			tmp2 = in.rabbits_second;
			for (; i <= in.day; i++)
			{
				result = tmp1 + tmp2;
				tmp1 = tmp2;
				tmp2 = result;
				
			}	
	}
	
	return result;
}

static int read_sets_number(char *file_name)
{
	FILE *fp;
	int result = 0;
	char *tmp;
	fp = fopen(file_name , "r");
	if (NULL == file_name) {
        	perror("Error: file pointer is null.");
        	result = 0;
    	}
    
       if (NULL == fgets(tmp, 6, fp)){
       		result = 0;
       } 

   fclose(fp);
   result = atoi(tmp);
   return result;
	
}

bool create_list(data_input *head, int list_length)
{
	data_input *tmp_data = head;
	int i;
		
	//create head:
	tmp_data = malloc(sizeof(data_input));
	if (NULL == tmp_data) {
        	perror("\n Node creation failed \n");
        	return NOK;
    	} else {
    		tmp_data->next = NULL;
    		tmp_data->prev = NULL;
    			
	}
	
	for (i = 0;i<list_length;++i) {
		tmp_data->next = malloc(sizeof(data_input));
		
		if(NULL == tmp_data->next)
    		{
        		printf("\n Node creation failed \n");
        		return NOK;
    		}
		else
    		{
    			++tmp_data;
    			tmp_data->next = NULL;
    			
		}
    		
	}
	return OK;
}