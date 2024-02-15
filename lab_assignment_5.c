#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int counter = 0;
	node *nCounter = head;

	while(nCounter != NULL) {
	counter++;
	nCounter = nCounter->next;
	}
	//Increases counter before it goes to the next node

	return counter;
}

//  parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function will return "abc"
char* toCString(node* head)
{
	node *charReader = head;
	
	int listLength = length(head), i = 0;

	char *letterList = malloc((listLength+1) * sizeof(char));
	//Character array to contain letters

	if(letterList == NULL) {
		return NULL;
	} //Checks if malloc was successful.

	for(i = 0; i<listLength; i++) {
		letterList[i] = charReader->letter;
		charReader = charReader->next;
	} //Fills in the character array

	letterList[i] = '\0';
  // Inserts a null character at the end of the string.

	return letterList;
}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->letter = c; // Assigning a letter to the new node
 	newNode->next = NULL; // Initializing newNode pointer to NULL

  node *temp = *pHead; //Creating a temporary node to traverse the list.

  if (newNode == NULL) {
        return;
	} // Checking if the node is allocated correctly.

	if(*pHead == NULL) {
		*pHead = newNode;
	} // Sets the created node as the head in case the list is empty.

	else {
		while(temp->next != NULL) {
		temp = temp->next;
	} // Traverses to the end of the list

	temp->next = newNode; // Directs last node in the list to the new node
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* temp = *pHead; 
    while (temp != NULL) {
        *pHead = temp->next;
        free(temp);
        temp = *pHead;
    }
    *pHead = NULL;
    // Traverses through the list and frees each node
  
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}