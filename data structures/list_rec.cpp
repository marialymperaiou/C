typedef struct node {
	string data;
	node *next;
} *list;

bool printFunny(list l) {
	if (l == nullptr) return false;
	if (!printFunny(l->next)) {
		cout << l->data << " ";
		return true;
	} 
	else {
		return false;
	}
}