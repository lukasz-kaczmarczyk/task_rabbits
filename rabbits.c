#include "rabbits.h"
#include <string.h>
#include <assert.h>



static data_input *data;

static int read_sets_number(char *file_name);
static bool create_list(data_input *head, int list_length);
static void read_data_set(FILE *fp, data_input *head);
static data_input *create_node();
static void display_list(data_input *list);
//static char * strsep(char **sp, char *sep);
static int compute_rabbits(data_input in);
static void save_quantity(FILE *fp, int in);

static int sets_number;

bool execute(data_input *data_list, char *file_name)
{	
	data_input *list_it;
	bool result = OK;
	int i = 0;
	FILE *fp;
	char tmp[10];
	fp = fopen(file_name , "r+");
	
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
	
	//display_list(data_list);
	
	while (NULL != list_it) {
		read_data_set(fp,list_it);
		list_it->rabbits_quantity = compute_rabbits(*list_it);
		save_quantity(fp, list_it->rabbits_quantity);
		printf("result: %d\n", list_it->rabbits_quantity);
		list_it = list_it->next;
	}
       
   fclose(fp);
   result = atoi(tmp);
   return result;
}

void free_data(data_input *data_list)
{
   data_input *tmp;

   while (NULL != data_list) {
       tmp = data_list;
       data_list = data_list->next;
       free(tmp);
    }

}

static int compute_rabbits(data_input in)
{
	int result, tmp1, tmp2, i = 3;
	data_input tmp = in;
	
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
    
       if (NULL == fgets(tmp, 6, fp)) {
       		result = 0;
       } 

   fclose(fp);
   result = atoi(tmp);
   return result;
	
}

static void read_data_set(FILE *fp, data_input *data)
{
    	char *buffer = (char *)malloc(sizeof(char) * 100);
    	int val[3];
    	char *chunk = (char *)malloc(sizeof(char) * 100);
    	int i = 0;
    	
    	if (NULL == buffer) {
        	printf("Error allocating memory for line buffer.");
        	exit(1);
    	}
    	
    	fgets(buffer, 100, fp);
    	printf("\n----data-----: %s", buffer);
    	
    	while ((chunk = strsep(&buffer, " ") ) && (i < 3)) {
    		val[i] = atoi(chunk);
    		i++;
	}

    	data->day = val[0];
    	data->rabbits_first = val[1];
    	data->rabbits_second = val[2];
    	
    	free(buffer);
    	free(chunk);
}


bool create_list(data_input *head, int list_length)
{
	data_input *tmp = head;
	int i;
	head = create_node();
	for (i = 0;i<(list_length-1);i++) {
		tmp->next = create_node();
        tmp = tmp->next;
	}
	return OK;
}

static data_input *create_node() {
    data_input *node = malloc(sizeof(*node));
    assert(node != NULL);
    node->next = NULL;

    return node;
}

static void display_list(data_input *list)
{
    data_input *tmp = list;
    while(NULL != list) {
        list = list->next;
    }
}

static void save_quantity(FILE *fp, int in)
{
    fprintf(fp, "number of rabbits %d\n", in);
}
/*
static char * strsep(char **sp, char *sep)
    {
        char *p, *s;
        if (sp == NULL || *sp == NULL || **sp == '\0') return(NULL);
        s = *sp;
        p = s + strcspn(s, sep);
        if (*p != '\0') *p++ = '\0';
        *sp = p;
        return(s);
    }
*/
