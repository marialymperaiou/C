#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BSIZE 1<<15

char buffer[BSIZE];
int bpos = 0, bsize = 0;

int readInt() 
{
	int d = 0, x = 0;
	char c;
	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}
 
typedef struct node_t node_t, *heap_t;
typedef struct edge_t edge_t;
struct edge_t {
	node_t *nd;	
	edge_t *sibling;
	double len;	
};
struct node_t {
	edge_t *edge;	
	node_t *via;	
	double dist;	
	char name[8];	
	int heap_idx;	
};

#define BLOCK_SIZE (1024 * 32 - 1)

edge_t *edge_root = 0, *e_next = 0;
 
void add_edge(node_t *a, node_t *b, double d)
{
	if (e_next == edge_root) {
		edge_root = (edge_t*)malloc(sizeof(edge_t) * (BLOCK_SIZE + 1));
		edge_root[BLOCK_SIZE].sibling = e_next;
		e_next = edge_root + BLOCK_SIZE;
	}
	--e_next;
 
	e_next->nd = b;
	e_next->len = d;
	e_next->sibling = a->edge;
	a->edge = e_next;
}
 
void free_edges()
{
	for (; edge_root; edge_root = e_next) {
		e_next = edge_root[BLOCK_SIZE].sibling;
		free(edge_root);
	}
}
 
heap_t *heap;
int heap_len;
double final;
 
void set_dist(node_t *nd, node_t *via, double d)
{
	int i, j;
 
	if (nd->via && d >= nd->dist) return;
 
	nd->dist = d;
	nd->via = via;
 
	i = nd->heap_idx;
	if (!i) i = ++heap_len;

	for (; i > 1 && nd->dist < heap[j = i/2]->dist; i = j)
		(heap[i] = heap[j])->heap_idx = i;
 
	heap[i] = nd;
	nd->heap_idx = i;
}
 
node_t * pop_queue()
{
	node_t *nd, *tmp;
	int i, j;
 
	if (!heap_len) return 0;
 
	nd = heap[1];
	tmp = heap[heap_len--];
 
	for (i = 1; i < heap_len && (j = i * 2) <= heap_len; i = j) {
		if (j < heap_len && heap[j]->dist > heap[j+1]->dist) j++;
 
		if (heap[j]->dist >= tmp->dist) break;
		(heap[i] = heap[j])->heap_idx = i;
	}
	heap[i] = tmp;
	tmp->heap_idx = i;
	return nd;
}
 
void calc_all(node_t *start)
{
	node_t *lead;
	edge_t *e;
 
	set_dist(start, start, 0);
	while ((lead = pop_queue()))
		for (e = lead->edge; e; e = e->sibling)
			set_dist(e->nd, lead, lead->dist + e->len);
}
 
void show_path(node_t *nd)
{
	if (nd->via == nd) 
		printf("%s", nd->name);
	else if (!nd->via) 
		printf("%s(unreached)", nd->name);
	else {
		show_path(nd->via);
	}
	final=nd->dist;
}
 
int main(void)
{  
	int i, j, k, l, w ,target=0, a=0, b, m=0,arxi=0;
#define N_NODES 1000000
    int *cost = (int*)calloc(sizeof(int),N_NODES);
	node_t *nodes = (node_t*)calloc(sizeof(node_t), N_NODES);
    l = readInt();
    w = readInt();
	for (i = 0; i < l; i++) {
        for (j = 0; j < w; j++) {
            cost[a] = readInt();
            if ((m!=0)&&(cost[a]==0)) target=a;
            if ((m==0)&&(cost[a]==0)) {arxi=a;m++;}
            a++;
            }
            }       
	for (i = 0; i < l; i++) {
        for (j = 0; j < w; j++) {      
               b=i*w+j;
               if (i>0){
                        k=i-1;
                        while (k>=0){
                              a=k*w+j;
                              if (cost[a]==4000) k=-1;
                              else add_edge(nodes+b,nodes+a,cost[a]);
                              k--;
                        }
                        }
               if (i<(l-1)){
                          k=i+1;
                          while (k<=(l-1)){
                                a=k*w+j;
                                if (cost[a]==4000) k=l;
                                else add_edge(nodes+b,nodes+a,cost[a]);
                                k++;
                                }
                                }
               if (j>0){
                        k=j-1;
                        while (k>=0){
                              a=i*w+k;
                              if (cost[a]==4000) k=-1;
                              else add_edge(nodes+b,nodes+a,cost[a]);
                              k--;
                        }
                        }
               if (j<(w-1)){
                          k=j+1;
                          while (k<=(w-1)){
                                a=i*w+k;
                                if (cost[a]==4000) k=w;
                                else add_edge(nodes+b,nodes+a,cost[a]);
                                k++;
                                }
                                }
            }
            }
	heap = (node_t**)calloc(sizeof(heap_t), N_NODES + 1);
	heap_len = 0;
	calc_all(nodes+arxi);
	show_path(nodes + target);
	printf("%g",final);
	putchar('\n');
	return 0;
}
