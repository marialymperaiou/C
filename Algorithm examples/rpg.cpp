# include <stdlib.h>
# include <stdio.h>

FILE *fp;

struct vect{
      int x;
      int y;
};

int n,m,k,w[500][500];
struct vect p[500][500];

int min(int a,int b){
    if (a<b) return a;
    else return b;
}

struct vect rev(struct vect a){
       struct vect b;
       b.x=a.y;
       b.y=a.x;
       return b;
}

struct vect add(struct vect a,struct vect b){
       struct vect c;
       c.x=a.x+b.x;
       c.y=a.y+b.y;
       return c;
}

struct vect make(int a,int b){
       struct vect c;
       c.x=a;
       c.y=b;
       return c;
}

int first(struct vect a){
       int b;
       b=a.x;
       return b;
}

int second(struct vect a){
       int b;
       b=a.y;
       return b;
}

struct vect f_rev(int i,int j){
       int a,b;
       struct vect money,max;
       max.x=0;max.y=0;
       for(a=0;a<=min(n-i-1,k);a++){
                                    for(b=0;b<=min(m-j-1,k);b++){
                                                                if (p[i+a][j+b].x!=-1) {money=add(make(w[i+a][j+b],0),rev(p[i+a][j+b]));}
                                                                if ((a==0)&&(b==0)) money.x=0;
                                                                if (money.x>max.x) {max=money;}
                                                                else if(money.x==max.x) {
                                                                     if (money.y<max.y) {max=money;}
                                                                     }
                                                                }
                                                                }
       return max;    
}
       
int main(){
    struct vect x;
    int i,j,p1,p2;
    fp= fopen("input1.txt","r");
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&m);
    fscanf(fp,"%d",&k);
    for(i=0;i<n;i++){
                     for(j=0;j<m;j++){
                                      fscanf(fp,"%d",&w[i][j]);
                                      }
                                      }
    for(i=0;i<n;i++){
                     for(j=0;j<m;j++){p[i][j].x=-1;p[i][j].y=-1;}
                                      }
    p[n-1][m-1].x=0;
    p[n-1][m-1].y=0;
    for(j=m-1;j>=0;j--){
                        for(i=n-1;i>=0;i--){
                                            p[i][j]=f_rev(i,j);
                                           }
                                           }
     p1=first(p[0][0]);
     p2=second(p[0][0]);
     printf("%d %d\n",p1,p2);
     system("pause");
     return 0;
}                           
