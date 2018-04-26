#include <stdio.h>
#include <stdlib.h>
// April 2015

int cmp(const void *a, const void *b)
{
        return ( *(int*)a - *(int*)b );
}
 
int main(int argc , char *argv[]){
	FILE *file = fopen(argv[1],"r");
	int N,M,i,j,t,z,l,g,q;
	bool flag;
	fscanf(file,"%d %d",&N,&M);
	int C[N];
	for(i=0;i<N;i++) C[i] = 1; 
	if (M==0) for (i=0;i<N;i++) printf("%d ",i+1);
	else{
		int P[M][N],k[M],r[M]; 
		for(i=0;i<M;i++){
			fscanf(file,"%d",&k[i]);
			for(j=0;j<k[i];j++) fscanf(file,"%d",&P[i][j]);
		}
		         
		for(i=0;i<M;i++) {
			qsort(P[i],k[i],sizeof(int),cmp);
			r[i] = k[i];
		}
		
		C[0]=0;
		i=0;
		z=1;
		t=0;
		while(1){
			
			/*for (j=0;j<N;j++) printf("%d ",C[j]);
            printf("\n");*/
			
			for(l=0;l<M;l++) r[l] = k[l];  
            l=0;
            
			while(l < N){
                if (C[l] == 0) for (g=0;g<M;g++) for(q=0;q<k[g];q++) if (l+1 == P[g][q]) r[g]--;  
                l++;
            }
            
			flag = true;
            for (g=0;g<M;g++) if (r[g] == k[g]) flag = false;
            if (flag) break;
            
            j = N-1;
            t=0;
            while(C[j] == 0) {
            	j--;
            	t++;
            }
            
            if (t == z) {
            	z++;
            	for(j=0;j<z-1;j++) C[N-j-1] = 1;
            	for(j=0;j<z;j++) C[j] = 0;	
            }
            else{
            	j = N-t-1;
            	while(C[j] == 1) j--;
            	C[j] = 1;
            	i = j + 1;
            	for (j=0;j<t;j++) C[N-j-1] = 1;
            	for (j=0;j<=t;j++) C[i+j] = 0;
            	
            }   
		}
		
		for(j=0;j<N;j++) if (C[j] == 1) printf("%d ",j+1);
	}
}

