    #include<stdio.h>
    #include<stdlib.h>
    
    long long int i,m,j,k,a,b,u,v,n,t,v1,v2,ne=1;
    long long int max,maxcost=0,d=0,kk,parent[300000];
    long long int find(long long int i);
    long long int uni(long long int i,long long int j);
    
int main(){
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&kk);
    
    long long int** cost;  
    cost= (long long int**) malloc((n+1)*sizeof(long long int*));  
    for (i = 0; i < (n+1); i++)  
    cost[i] = (long long int*) malloc((n+1)*sizeof(long long int)); 
    
    long long int* duration;
    duration=(long long int*) malloc (m*sizeof(long long int));
    
    for(i=1;i<=m;i++){
                      scanf("%lld",&v1); scanf("%lld",&v2);
                      scanf("%lld",&t);
                      cost[v1][v2]=t;
                      cost[v2][v1]=t;
                      duration[i]=0;
                      }
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
                      if (cost[i][j]==0) cost[i][j]=-1;
                      }
        }
    while(ne < n){
             for(i=1,max=0;i<=n;i++){
                                       for(j=1;j <= n;j++){
                                                 if(cost[i][j] > max){
                                                               max=cost[i][j];
                                                               a=u=i;
                                                               b=v=j;
                                                               }
                                                 }
                                       }
             u=find(u);
             v=find(v);
             if(uni(u,v)){
                          ne++;
                          duration[d]=max;
                          d++;
                          maxcost +=max;
                          }
             cost[a][b]=cost[b][a]=-1;
             }
    if ((d-kk-1)>=0) printf("%lld\n",duration[d-kk-1]);
    else printf("infinity\n");
    return 0;
}

    long long int find(long long int i){
    while(parent[i])
    i=parent[i];
    return i;
    }
    
    long long int uni(long long int i,long long int j){
    if(i!=j){
    parent[j]=i;
    return 1;
    }
    return 0;
    }
