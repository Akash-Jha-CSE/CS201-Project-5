#include<stdio.h>

const int movies=910; //number of movies in our dataset
const int genre=21; //number of genres

int main(){
    float data1=0,data=0,data2=0;
    char nline='\n',a,b,c;
    int x,count;
    FILE * file=fopen("votes.csv","r");
    FILE * f = fopen("frating.txt","w");
    FILE * file2 =fopen("data.txt","r");
    for(int i=0;i<movies;i++){
        count=0;
        fscanf(file,"%f",&data);
        data1=data/3000;
        fprintf(f,"%f  ",data1);
        while(count<22){
            fscanf(file2,"%f",&data2);
            fscanf(file2,"%c",&a);
            fscanf(file2,"%c",&b);
            fscanf(file2,"%c",&c);
            count++;
            if(data2==0){
                x=(int)data2;
                fprintf(f,"%d  ",x);
            } 
            else{
                fprintf(f,"%.1f  ",data2);
            }
        }
        fprintf(f,"%c",nline);
    }
    


}