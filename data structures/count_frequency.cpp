typedef struct node {
int data;
	node *left, *right;
} *tree;

void updateFreq(tree t, int freq[]) {
	if (t != nullptr) {
		freq[t->data]++;
		updateFreq(t->left, freq);
		updateFreq(t->right, freq);
	}
}

void findMostFrequent(tree t) {
	// Initialize the frequency array
	static int freq[1000000];
	for (int i = 0; i < 1000000; ++i) 
		freq[i] = 0;
	//Tree crossing and update of the frequency matrix
	updateFreq(t, freq);

	//find and print the most frequency value(0 if the tree is empty)
	int best = 0;
	for (int i = 0; i < 1000000; ++i)
		if (freq[i] > freq[best]) 
			best = i;
		cout << "Number " << best << " occurs " << freq[best] << " time(s).\n";
}