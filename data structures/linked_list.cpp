struct node {
char *word;
struct node *next;
};

struct node *remDupl(struct node *myList){
	struct node *ptr;
	struct node *temp;
	if (myList == NULL)
		return myList; 													//check if empty list
	ptr = myList;
	while (ptr->next != NULL) {
		if (strcmp(ptr->word, ptr->next->word) == 0) { 					//if we find string match
			temp = ptr->next->next; 									//keep where the 2nd node points
			free(ptr->next);
			//delete node
			ptr->next = temp;
			//restore pointer
		} 
		else
			ptr = ptr->next;
	//check next 2 nodes
	}
}