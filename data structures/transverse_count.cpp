int c = 0;//global

int traverseCount(tree t){
	if(t == NULL)
		return 0;
	if(t->left != NULL && t->right != NULL)
		++c;
	traverseCount(t->left);
	traverseCount(t->right);
	return c;
}