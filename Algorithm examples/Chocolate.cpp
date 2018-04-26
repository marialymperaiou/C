    # include <stdlib.h>  
    # include <stdio.h>  
    # include <math.h>  
      
    void quick_sort (long long int *a,long long int n) {  
        if (n < 2)  
            return;  
        long long int p = a[n / 2];  
        long long int *l = a;  
        long long int *r = a + n - 1;  
        while (l <= r) {  
            if (abs(*l) < abs(p)) {  
                l++;  
            }  
            else if (abs(*r) > abs(p)) {  
                r--;  
            }  
            else {  
                int t = *l;  
                *l = *r;  
                *r = t;  
                l++;  
                r--;  
            }  
        }  
        quick_sort(a, r - a + 1);  
        quick_sort(l, a + n - l);  
    }  
           
      
    int main () {  
        long long int n,*p,i,target,zero_finder=-1,time=0,amount=0,k=0;  
        div_t fact;  
        scanf("%lld",&n);  
        scanf("%lld",&target);  
        p = (long long int *)malloc((2*n+1) * sizeof(long long int));  
        p[0]=0;  
        for(i=1;i<=2*n;i++){  
                         scanf("%lld",&p[i]);  
                         if (i%2==0) p[i]=-p[i];  
                         }  
        quick_sort(p,2*n+1);  
        i=1;  
        while (amount<target){  
        amount=amount+(abs(p[i])-abs(p[i-1]))*k;  
        if (p[i]>=0) amount++;  
        if (amount==target) {time=abs(p[i]);break;}  
        if (p[i]>=0) k++;  
        else k--;  
        if(p[i]==0){zero_finder++;}  
        if((p[i]==0)&&(zero_finder%2!=0)) {amount--;k--;k--;}  
        i++;  
        }  
        if(time==0){  
        if (p[i-1]>0) k--;  
        else k++;  
        i--;  
        if(p[i]>0)  fact= div((amount-target-1),k);  
        else fact=div((amount-target),k);  
        time=abs(p[i])-fact.quot;  
        }  
        printf("%lld\n",time);       
        return 0;  
    }  










