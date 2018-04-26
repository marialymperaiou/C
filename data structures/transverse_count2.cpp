int traverseCount(tree t){
	if(t == NULL)
		return 0;
	if(t->left != NULL && t->right != NULL)
		return 1 + traverseCount(t->left) + traverseCount(t->right);
	else
		return traverseCount(t->left) + traverseCount(t->right);
}