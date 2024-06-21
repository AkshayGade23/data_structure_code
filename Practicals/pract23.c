#include <stdio.h>
#define MAX_SIZE 9 //Size of hash table
int hash_table[MAX_SIZE]; //Hash table
//Function to insert element into hash table using linear probing
void insert(int key)
{
    int index = key % MAX_SIZE; //Calculate index using modulo 9
    //Check if the slot is empty
    if (hash_table[index] == -1)
    {
        hash_table[index] = key;
    }
    else
    {
    	int i;
        //If the slot is full, check the next slot using linear probing
        for (int j = 1,i = 1; i < MAX_SIZE && j < 4 ; i++,j++)
        {
            int new_index = (index + i) % MAX_SIZE; //Calculate new index
            if (hash_table[new_index] == -1)
            {
                hash_table[new_index] = key;
                break;
            }
            else if (i == MAX_SIZE - 1) //If hash table is full, throw an error
            {
                printf("Error: Hash table full Can't insert %d\n",key);
            }
        }
    }
}
int main()
{
	int i;
    //Initialize hash table with -1
    for (i = 0; i < MAX_SIZE; i++)
    {
        hash_table[i] = -1;
    }

    insert(5);
    insert(14);
    insert(22);
    insert(31);
    insert(40);
    insert(49);
    insert(58);
    insert(67);
    insert(76); 
    insert(60); //This will throw an error because the hash table is full
    //Print out the hash table
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", hash_table[i]);
    }
  return 0;
}



        