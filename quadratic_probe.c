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
 
void main()
{
	int choice, key, value, n, c;
 
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item*));
	init_array();
 
	do {
		printf("Implementation of Hash Table in C with Quadratic Probing.\n\n");
		printf("MENU-: \n1.Inserting item in the Hash table" 
                              "\n2.Removing item from the Hash table" 
                              "\n3.Check the size of Hash table" 
                              "\n4.Display Hash table"
		       "\n\n Please enter your choice-:");
 
		scanf("%d", &choice);
 
		switch(choice)
                {
 
		case 1:
 
		      printf("Inserting element in Hash table \n");
		      printf("Enter key and value-:\t");
		      scanf("%d %d", &key, &value);
		      insert(key, value);
 
		      break;
 
		case 2:
 
		      printf("Deleting in Hash table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);
 
		      break;
 
		case 3:
 
		      n = size_of_hashtable();
		      printf("Size of Hash table is-:%d\n", n);
 
		      break;
 
		case 4:
 
		      display();
 
		      break;
 
		default:
 
		       printf("Wrong Input\n");
 
		}
 
		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
 
	}while(c == 1);
 
	getch();
 
}
