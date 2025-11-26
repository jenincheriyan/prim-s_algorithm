                                                                                                                                     prims_algoritm.c                                                                                                                                              
#include<stdio.h>
#include<stdlib.h>

int min, cost=0;
int mincost[99][99];
int visited[99];
int a,b,n;
int main(){

        FILE *file=fopen("graph.txt","r");

        if(file==NULL){

                printf("file not exit");
                return 1;
        }
        fscanf(file,"%d",&n);
        printf("Reading the file");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        fscanf(file,"%d",&mincost[i][j]);
                        if(mincost[i][j]==0){
                                mincost[i][j]=999;
                        }
                }
        }
        fclose(file);
        for (int i=0;i<n;i++){
                visited[i]=0;
        }
        printf("The edges of minimum spanning tree are:\n");

        visited[0]=1;
        for (int l=0; l<n-1; l++){
                min=999;
                for(int i=0;i<n;i++){
                        if(visited[i]){
                                for(int j=0;j<n;j++){
                                        if(!visited[j]&&mincost[i][j]<min){
                                                min=mincost[i][j];
                                                b=j;
                                        }
                                }
                        }
                }
        visited[b]=1;
        printf("%d edges(%d %d)\t cost:%d\n",l+1,a,b,min);
        cost+=min;
        }
        printf("\n Minimum cost: %d",cost);
        return 0;

}

