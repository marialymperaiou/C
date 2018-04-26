#include <stdio.h>
#include<stdbool.h>

int main()
{
	 int c,i,j,k,count=0,line[120];
	 bool check=true;
	 FILE *f1;
	 f1=fopen("FIL.txt","rt");
	 c=fgetc(f1);
	 i=0;
	 while (c!=EOF){
	   while (c!='\n' && c!=EOF){
		    if (c=='$') 
		    	check=false;
		    line[i++]=c;
		    c=fgetc(f1);
	   }
	   line[i++]=c;

	   if (!check) for(j=0;j<i;j++) 
	   		printf("%c",line[j]);
	   else{
		    j=0;
				while (j<i){
				if (line[j]>='a' && line[j]<='z'){
				   while (line[j]>='a' && line[j]<='z'){
				    	count++;
				    	j++;
				   }
				   printf("%d",count);
				   for (k=0;k<count-1;k++) putchar('-');
				   		count=0;
				}
			 	else {
			  		putchar(line[j]);
			  		j++;
			 	}
			}
	   }
	   i=0;
	   check=true;
	   if (c!=EOF) 
	   		c=fgetc(f1);
	  } 
	 return 0;
}