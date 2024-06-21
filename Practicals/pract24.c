#include <stdio.h>
#include <stdlib.h>
#define SIZE 11
int hash_table[SIZE];
int hash_function(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int i;
    int index = hash_function(key);
    if (hash_table[index] != 0)
    {
        for (int j = 1, i = (index + 1) % SIZE;i != index && j < 3; i = (i + 1) % SIZE, j++)
        {
            if (hash_table[i] == 0)
            {
                hash_table[i] = key;
                printf("Key %d inserted at index %d\n", key, i);
                return;
            }
        }
        printf("Error: Hash table full\n");
    }
    else
    {
        hash_table[index] = key;
        printf("Key %d inserted at index %d\n", key, index);
    }
}
int main()
{
    insert(5);
    insert(16);
    insert(22);
    insert(31);
    insert(32);
    insert(21);
    return 0;
}
