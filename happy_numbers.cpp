#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc , char *argv[]){
	FILE *file = fopen(argv[1],"r");
	long int A,B,y=0,d,happy = 0;
	int x,sum=0,q;
	fscanf(file,"%ld %ld",&A,&B);
	long int i = 1;
	int tetragwna[10];
	int j,xilia[730];
	for (j=0;j<10;j++){
		tetragwna[j] = j*j;
	}

	for (j=0;j<730;j++){
		xilia[j]=5;
	}
	
	while((i<=729)&&(i<=B)){
		y = i;
		d = y;
		while(1){
			if (y<730){
				if (xilia[y] == 1) {
					happy ++;
					if (i<730) xilia[i] = 1;
					break;
				}
				if (xilia[y] == 0) {
					if (i<730) xilia[i] = 0;
					break;
				}
			}

			x = y%10;
			sum = tetragwna[x];
			while (y/10 >= 1){
				y = y/10;
				x = y%10;
				sum+=tetragwna[x];
			}
			
			if (sum == 1) { 
				happy ++;
				xilia[d] = 1;
				xilia[i] = 1;
				break;
			}
			if ((sum==4)||(sum==16)||(sum==37)||(sum==58)||(sum==89)||(sum==145)||(sum==42)||(sum==20)){
				xilia[d] = 0;
				xilia[i] = 0;
				break;
			}
			
			y = sum;
			sum = 0;
		}
		i++;
	}
	
	if(A>729){
		happy = 0;
		i = A;
	}
	
	q = 1;
	sum = 0;
	
	while ((i-1)/q >= 1) {
		sum += tetragwna[((i-1)/q)%10];
		q *= 10;
	}

	int k;
	while(i<=B){
		k=0;
		q=1;
		x = ((i-1)/q)%10;

		while(x == 9){
			q *= 10;
			k++;
			x = ((i-1)/q)%10;
		}

		sum -= k*81;
		sum -= tetragwna[x];
		sum += tetragwna[x+1];

		if (xilia[sum] == 1) happy++;
		
		i++;
	}
		
	printf("%ld\n",happy);
	return 0;
}
