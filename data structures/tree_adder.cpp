int treeAdder(tree t, int min, int max){
	if(t == NULL)
		return 0;
	if((t->value < min) || (t->value > max))
		return t->value + treeAdder(t->left) + treeAdder(t->right);
	else
		return treeAdder(t->left) + treeAdder(t->right);
}