
#ifndef CONTEST
#include <iostream>
using namespace std;

struct list_node {
	int data;
	list_node *next;
};

struct tree_node {
	int data;
	tree_node *left, *right;
};

list_node * list(int x, list_node *next) {
list_node *n = new list_node;
n->data = x;
n->next = next;
return n;
}

tree_node * tree(int x, tree_node *left, tree_node *right) {
tree_node *n = new tree_node;
n->data = x;
n->left = left;
n->right = right;
return n;
}

#endif

//how many nodes of the list have value>x?
int list_count_greater_than(list_node *l, int x) {
	int i=0;
	while(l!=NULL){i=i+((l->data)>x);
		l=l->next;
	}
		return i;
}

//returns true if all the even number are before an odd one (no two even numbers in a row)
bool list_all_even_first(list_node *l) {
	bool bl=true;
	list_node *l1;
	l1=l;l=l->next;
	while((l!=NULL)&&(bl==true)){
		if ((l1->data % 2==0) && (l->data %2==0)) bl=false;
		l1=l;l=l->next;
}
return bl;
}

//returns 1 if the first list has less elements, 2 if the 2nd has less elements, and 3 if the 3rd list has less elements
//all the lists have different number of elements

//first, this function finds the number of elements of a list
int list_size(list_node *l){
	int i=0;
	while (l!=NULL){
		i++;l=l->next;
}
return i;
}
// so the lists can be compared
int list_shortest_of_three(list_node *l1, list_node *l2, list_node *l3) {
	int i1,i2,i3,ap;
	i1=list_size(l1);i2=list_size(l2);i3=list_size(l3);
	return ((i1<i2)&&(i1<i3))+((i2<i1)&&(i2<i3))*2+((i3<i1)&&(i3<i2))*3;
}

/* or
int list_shortest_of_three(list_node *l1, list_node *l2, list_node *l3) {
int i1,i2,i3,ap;
i1=list_size(l1);i2=list_size(l2);i3=list_size(l3);
if ((i1<i2)&&(i1<i3)) ap=1;
if ((i2<i1)&&(i2<i3)) ap=2;
if ((i3<i1)&&(i3<i2)) ap=3;
return ap;
}
*/

//returns the number of nodes with value>x
int tree_count_greater_than(tree_node *t, int x) {
	if(t==NULL)return 0;
		return (x<t->data)+tree_count_greater_than(t->left,x)+tree_count_greater_than(t->right,x);
	}


//returns the number of leaves (not nodes!) on k-level (root is at level 1)
int tree_leaves_at_level(tree_node *t, int k) {
if ((t==NULL)||(k==0)) return 0;
if (t->left == NULL && t->right==NULL && k==1) {return 1;}
else return tree_leaves_at_level(t->left, k-1)+tree_leaves_at_level(t->right, k-1);
}


//returns the specular copy of a tree
tree_node * tree_mirror(tree_node *t) {
if (t==NULL) return NULL;
tree_node *temp;
temp=new tree_node;
temp->data=t->data;
temp->left=tree_mirror(t->right);
temp->right=tree_mirror(t->left);
return temp;
}


#ifndef CONTEST
ostream & operator << (ostream & out, tree_node *t) {
if (t == nullptr)
out << "null";
else
out << "node(" << t->data << ", " << t->left << ", " << t->right << ")";
return out;
}

int main() {
	list_node *l = list(42, list(17, list(69, list(37, nullptr))));
	cout << "l = 42 -> 17 -> 69 -> 37" << endl;
	cout << "list_count_greater_than(l, 40) = "
	<< list_count_greater_than(l, 40) << endl;
	cout << "list_all_even_first(l) = "
	<< (list_all_even_first(l) ? "true" : "false") << endl;
	list_node *l2 = list(7, list(9, list(3, nullptr)));
	list_node *l3 = list(25, list(43, list(91, list(4, list(7, nullptr)))));
	cout << "l2 = 7 -> 9 -> 3" << endl;
	cout << "l3 = 25 -> 43-> 91 -> 4 -> 7" << endl;
	cout << "list_shortest_of_three(l, l2, l3) = "
	<< list_shortest_of_three(l, l2, l3) << endl << endl;
	cout << "list_shortest_of_three(l, l2, l3) = "
	<< list_shortest_of_three(l, l2, l3) << endl << endl;
	tree_node *t = tree(42,
		tree(17,
		tree(22, nullptr, tree(6, nullptr, nullptr)),
		tree(4, nullptr, tree(78, nullptr, nullptr))),
		tree(37,
		nullptr,
	tree(89, nullptr, nullptr)));
	cout << "t = " << t << endl;
	cout << "which means:" << endl;
	cout << "t = 42" << endl;
	cout << " / \\" << endl;
	cout << " 17 37" << endl;
	cout << " / \\ \\" << endl;
	cout << " 22 4 89" << endl;
	cout << " \\ \\" << endl;
	cout << " 6 78" << endl;
	cout << "tree_count_greater_than(t, 40) = "
	<< tree_count_greater_than(t, 40) << endl;
	cout << "tree_leaves_at_level(t, 3) = " << tree_leaves_at_level(t, 3) << endl;
	cout << "tree_mirror(t) = " << tree_mirror(t) << endl;
}

#endif