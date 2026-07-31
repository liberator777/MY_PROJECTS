#include <stdio.h>
#pragma warning(disable:4996)

int Differentiation(int cf[], int n) {

    int df[n]; 

    for(int i = n; i >= 0; i--) {
       df[i] = cf[i]*(i) ;
    }
    printf("result(differentiated): ");
    printf("\n");
    for(int j = n; j>=0; j--) {
        if (j > 0) {
            if (j > 1) {
                printf("%dx^%d",df[j],j-1);
                printf(" + ");
            }
            else {
                printf("%d",cf[j]);
            }
        }else {
            printf("\n");
        }
        
    }


}

int integral(int cf[], int n) {


    int k = n+1;
    float df[k]; 

    printf("result(integraled): \n");
    for (int i = n+1;i>=0;i--) {
        df[i] = ((float)cf[i-1]/i);
    }
    
    for(int j = n+1; j>=0;j--) {
         if (j>=1) {
            printf("%.1fx^%d",df[j],j);
            printf(" + ");
         }
         else {
            printf("C");
         }
    }
    
}


int main(void) {
    int n;
    int cf[n];
    
    printf("enter the highest degree: " ); scanf("%d",&n);

    for(int i = n;i>=0;i--) {
        printf("enter the coefficient of %dth power: ", i); scanf("%d",&cf[i]);
    }

    printf("your expression is: \n ");

    for(int j = n; j >= 0; j--) {

        if(j!=0) {
            printf("%dx^%d",cf[j],j);
            printf(" + ");
        }
        else {
            printf("%d",cf[j]);
        }
       
    }

    printf("\n\n");
    Differentiation(cf,n);
    integral(cf,n);
    printf("\n");
      
}