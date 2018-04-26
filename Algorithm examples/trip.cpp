    #include <iostream>  
    #include <cstdio>  
    #include <cstring>  
    #include <list>  
    #include <vector>  
    #include <algorithm>  
       
    using namespace std;  
       
    // LocalTree class represents a directed LocalTree using adjacency list representation  
    class LocalTree  
    {  
    public:  
        LocalTree( int vNum )  
        {  
            V = vNum;  
            adj.resize( vNum );  
      
            visited = new bool[V];  
            depth = new int[V];  
        }  
      
        ~LocalTree( )  
        {  
            delete[] visited;  
            delete[] depth;  
        }  
      
        void addEdge( int v, int u )  
        {  
            adj[v].push_back(u);  
            adj[u].push_back(v);  
        }  
      
        void DFS( int v )  
        {  
            for ( int i = 0; i < V; ++i )  
                visited[i] = false;  
           
            // Call the recursive search once,  
            // because the tree is connected.  
            depth[v] = -1;  
            maxDepth = v;  
            dfsSearch( v, v, visited, depth );  
        }  
      
        int getMaxDepth()  
        {  
            return depth[maxDepth];  
        }  
      
        int getMaxDepthNode()  
        {  
            return maxDepth;  
        }  
      
    private:  
        int V;  // Number of Vertices in the Tree.  
        vector< list<int> > adj;    // Array of Linked Lists.  
        bool *visited;  
        int *depth;  
        int maxDepth;  
      
        void dfsSearch( int v, int parent, bool visited[], int depth[] )  
        {  
            // Mark the current node as visited.  
            visited[v] = true;  
            depth[v] = depth[parent] + 1;  
      
            //cout << v << " " << depth[v] << endl;  
      
            if ( depth[ v ] > depth[ maxDepth ] )  
                maxDepth = v;  
           
            // Recursive call to all unvisited nodes.  
            list<int>::iterator i;  
            for( i = adj[v].begin(); i != adj[v].end(); ++i )  
                if( !visited[*i] )  
                    dfsSearch( *i, v, visited, depth );  
        }  
    }; 


struct edge
{
int vertexIndex;
struct edge *edgePtr;
}edge;

struct vertex
{
int vertexKey;
int visited;
struct edge *edgePtr;
}vertex;


void insertVertex(struct vertex *g, int vertexKey, int *vertexCount)
{
g[*vertexCount].vertexKey=vertexKey;
g[*vertexCount].edgePtr=NULL;
g[*vertexCount].visited=0;
(*vertexCount)++;
}

void insertEdge(struct vertex *g,int vertex1, int vertex2)
{
struct edge *e,*e1,*e2;
e=g[vertex1].edgePtr;
while(e&& e->edgePtr)
{
    e=e->edgePtr;
}
e1=(struct edge *)malloc(sizeof(*e1));
e1->vertexIndex=vertex2;
e1->edgePtr=NULL;
if(e)
e->edgePtr=e1;
else
g[vertex1].edgePtr=e1;

e=g[vertex2].edgePtr;
while(e&& e->edgePtr)
{
    e=e->edgePtr;
}
e2=(struct edge *)malloc(sizeof(*e2));
e2->vertexIndex=vertex1;
e2->edgePtr=NULL;
if(e)
e->edgePtr=e2;
else
g[vertex2].edgePtr=e2;
}

void dfs(struct vertex *g,int vertex1)
{
g[vertex1].visited=1;
printf("%d ",vertex1);
struct edge *e;
e=g[vertex1].edgePtr;

while(e)
{
    if(!(g[e->vertexIndex].visited))
    dfs(g,e->vertexIndex);

    e=e->edgePtr;
}
}

int height (int *p,int n){
    int *q,max,i,j,h;
    q=(int*)calloc((n+2),sizeof(int));
    q[1]=1;
    max=1;
    for(i=2;i<=(n+1);i++){
                          h=0;
                          j=i;
                          while(q[j]==0){
                                         j=p[j];
                                         h++;
                                         }
                          q[i]=q[j]+h;
                          if (q[i]>max) max=q[i];
                          }    
    max=max-1;
    free(q);
    return max;
}

int main(){
    int *p,n,t,*y,m,i,max,thesi,profit,junk,*best,j,a1,a2;
    scanf("%d",&m);
    y=(int*)malloc((m+1)*sizeof(int));
    best=(int*)malloc((m+1)*sizeof(int));
    for(i=0;i<m;i++){
                     scanf("%d",&n);
                     if (n==1) {y[i]=0;scanf("%d",&junk);}
                     else{
                          n--;
                          p=(int*)malloc((n+2)*sizeof(int));
                          p[1]=-1;
                          for (t=2;t<=(n+1);t++){
                                                scanf("%d",&p[t]);
                                                }
                          y[i]=height(p,n);
                          free(p);
                          }
                     }
    max=0;
    thesi=0;
    for(i=1;i<m;i++){
                     profit=i+y[i];
                     if(profit>=max){     //skepsou to (=) !!!
                                     max=profit;
                                     thesi=i;
                                     }
                     }
    best[0]=max;
    for (i=1;i<m;i++){
        if (i==thesi) {
                      max=0;
                      for(j=1;j<m;j++){
                                       profit=y[(j+i)%m]+j+1;
                                       if (profit>=max){
                                                        max=profit;
                                                        thesi=(j+i)%m;
                                                        }
                                       }
                      best[i]=max;
                      }
        else{
                      a1=y[i-1]+m-1;
                      a2=y[thesi]+thesi-i;
                      if(a1>a2){
                                best[i]=a1;
                                thesi=i-1;
                                }
                      else best[i]=a2;
             }
             }
    max=0;
    for(i=0;i<m;i++){
                     if(best[i]>max) max=best[i];
                     }
    printf("%d\n",max);
    system("pause");
    return 0;
}
