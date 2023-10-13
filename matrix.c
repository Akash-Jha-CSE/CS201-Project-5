#include<stdio.h>

const int m=910;  // number of rows in movies vs genre(number of movies)
const int n=21;   // number of columns in movies vs genre(number of genre)
const int a=21;   // number of rows in genre vs users(number of genre)
const int b=1000; // number of columns in genre vs users(number of users)

int main(){
    // creating a file pointer to data.txt and opening file in read only mode
    FILE *fptr=fopen("data.txt","r");
    // making matrix of movies vs genre
    float matrix[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            fscanf(fptr,"%f",&matrix[i][j]);
        }
    }
    fclose(fptr);  //closing file

    // making matrix of genre vs users
    int user[a][b];
    fptr=fopen("user.txt","r");
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            fscanf(fptr,"%d",&user[i][j]);
        }
    }
    fclose(fptr);

    float usermovies[b];  // making array for matrix multiplication of matrix and user
    // 2d array is not made as it required a large space which was giving segmentation fault
    float max=0;  // maximum of movies vs user matrix for normalisation
    fptr=fopen("rating.txt","w");   // file for movies vs user matrix
    // in these for loops matrix and user are multiplied and stored in rating.txt
    for(int i=0;i<m;i++){
        for(int j=0;j<b;j++){
            usermovies[j]=0; 
            for(int k=0;k<n;k++){
                usermovies[j]=usermovies[j]+matrix[i][k]*user[k][j];
            }
            if(usermovies[j]>max)  max=usermovies[j];
            fprintf(fptr,"%f ",usermovies[j]);
        }
        fprintf(fptr,"\n");
    }
    fclose(fptr);
    fptr=fopen("rating.txt","r");  // for reading movies vs users ratings
    FILE *ptr=fopen("normalised.csv","w");  // normalised ratings(0-10)
    float ele;   
    // int hese loops ratings are normalised and stored in normalised.csv
    for(int i=0;i<m;i++){
        for(int j=0;j<b;j++){
            fscanf(fptr,"%f",&ele);
            ele=ele/max*10;
            fprintf(ptr,"%f,",ele);
        }
        fprintf(ptr,"\n");
    }
    return 0;
}