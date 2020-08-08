#include<stdio.h>
#include<stdlib.h>
 
struct item 
{
	int k;
	int value;
};
 
struct hashtable_item 
{
 
	int f;
	/*
	 * f = 0 - not present
	 * f = 1 - present
	 * f = 2 - duplicate
	*/
	struct item *data;
 
};
 
struct hashtable_item *array;
int size = 0;
int max = 10;
 
int hashcode(int k)
{
	return (k % max);
}
 
void init_array()
{
	int i;
	for (i = 0; i < max; i++) 
        {
		array[i].f = 0;
		array[i].data = NULL;
	}
}
 
 //INSERT
void insert(int k, int value)
{
	int index = hashcode(k);
 
	int i = index;
	int h = 1;
 
	struct item *new_item = (struct item*) malloc(sizeof(struct item));
	new_item->k = k;
	new_item->value = value;
 
	/* iterate untill empty */
	while (array[i].f == 1) 
        {
 
		if (array[i].data->k == k) 
                {
 
			/* when key matches */
			printf("\n update key value \n");
			array[i].data->value = value;
			return;
 
		}
		i = (i + (h * h)) % max;
		h++;
		if (i == index)
                {
			printf("\n Hash table is full\n");
			return;
		}
 
	}
 
	array[i].f = 1;
	array[i].data = new_item;
	printf("\n Key (%d) has been inserted\n", k);
	size++;
 
}
 
 //DELETE
void remove_element(int k)
{
	int index = hashcode(k);
	int i = index;
	int h = 1;
 
	while (array[i].f != 0)
        {
		if (array[i].f == 1  &&  array[i].data->k == k) 
                {
 
			/* data and key match*/
			array[i].f = 2;
			array[i].data = NULL;
			size--;
			printf("\n Key (%d) has been removed \n", k);
			return;
 
		}
		i = (i + (h * h)) % max;
		h++;
		if (i == index) 
                {
			break;
		}
	}
	printf("\n Key does not exist \n");
 
}
 
 //FETCH
void display()
{
 
	int i;
	for(i = 0; i < max; i++)
        {
		if (array[i].f != 1)
                {
			printf("\n Array[%d] has no elements \n", i);
		}
		else
                {
			printf("\n Array[%d] has elements \n  %d (key) and %d (value) \n", i, array[i].data->k, array[i].data->value);
		}
	}
 
}
 
int size_of_hashtable()
{
	return size;
}
 

