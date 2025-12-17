#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

int main()
{
    PNODE ptr = NULL;

    // Create the node 
    ptr = (PNODE) malloc (sizeof(NODE));

    // Use the node
    
    // free the node
    free(ptr);

    return 0;
}
