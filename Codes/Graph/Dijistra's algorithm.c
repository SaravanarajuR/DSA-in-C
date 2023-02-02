#include<stdio.h>
#include<stdlib.h>
#define c 9999
#define max 10

void dij(int graph[max][max],int n,int start){
	int cost[max][max],mindistance,nextnode,count,distance[max],visited[max];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(graph[i][j]==0){
				cost[i][j]=c;
			}else{
				cost[i][j]=graph[i][j];
			}
		}
	}
	
	for(int i=0;i<n;i++){
		distance[i]=cost[start][i];
		visited[i]=0;
	}
	
	distance[start]=0;
	visited[start]=1;
	count=1;
	
	while(count<n-1){
	mindistance=c;
	
		for(int i=0;i<n;i++){
			if(distance[i]<mindistance && !visited[i]){
				mindistance=distance[i];
				nextnode=i;
			}
		}
		printf("\nVisiting %d-",nextnode);
		visited[nextnode]=1;
		
		for(int i=0;i<n;i++){
			if(mindistance+cost[nextnode][i]<distance[i] && !visited[i]){
				distance[i]=mindistance+cost[nextnode][i];
			}
		}
		count++;
		for(int i=0;i<n;i++){
			printf("\n%d--->%d=%d",start,i,distance[i]);
		}
		printf("\nMatrix representation\n");
		for(int i=0;i<n;i++){
			cost[start][i]=distance[i];
		}
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}	
	}
	for(int i=0;i<n;i++){
			printf("\nDistance from %d to %d is %d",start,i,distance[i]);
		}	
	}

void main(){
	int n,u,d,graph[max][max];
	printf("Enter total number of nodes");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("Enter the distance between %d and %d",i,j);
				scanf("%d",&d);
				graph[i][j]=d;
		}
	}
	printf("Enter source node");
	scanf("%d",&u);
	dij(graph,n,u);
}
