#include<stdio.h>

const int m=910;  // number of rows(movies)
const int n=21;   // number of columns(genre)

int main(){
    // creating a file pointer to data.txt and opening file in read only mode
    FILE *fptr=fopen("data.txt","r");
    // making matrix
    float matrix[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            fscanf(fptr,"%f",&matrix[i][j]);
        }
    }
    fclose(fptr);  //closing file
    return 0;
}