#include "DoubleLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	linked_list_t * mylist = Init_List();
	
	for (int iterator = 0; iterator < 10; ++iterator)
	{
		Insert_At_Beginning(mylist, iterator);
		printf("Inserting %d at the beginning of the list.\n", iterator);
	}
	
	if (10 == Count(mylist))
	{
		printf("10 items on the stack now, as expected.\n");
	}
	else
	{
		printf("Found %d items on the stack, instead of 10\n", Count(mylist));
	}
	
	int expectedStacktop = 9;
	int stacktop = 0;
	while (! Empty(mylist))
	{
		Remove_From_Beginning(mylist, &stacktop);
		if (stacktop != expectedStacktop)
		{
			printf("Expected %d at the top of the stack but got %d\n", expectedStacktop, stacktop);
			exit(1);
		}
		else
		{
			printf("Got %d of the stack, as expected.\n", stacktop);
		}
		--expectedStacktop;
	}
	if (0 != stacktop)
	{
		printf("Expected 0 now that we should be at the bottom of the stack, but got %d\n", stacktop);
	}
	
	Delete_List(mylist);
	free(mylist);
	mylist = NULL;
	return 0;
}