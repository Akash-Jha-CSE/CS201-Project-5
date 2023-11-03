#include<stdio.h>
#include<stdlib.h>

int main(){
    float f;
    FILE *fptr=fopen("new.txt","r");
    FILE*ptr=fopen("normalisedRatings.txt","w");
    for(int i=0;i<910;i++){
        for(int i=0;i<1000;i++){
            fscanf(fptr,"%f",&f);
            fprintf(ptr,"%f ",f);
        }
        fprintf(ptr,"\n");
    }
    return 0;
}
