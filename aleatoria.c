#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>

#define N 10
enum movement{su, giu, dx, sx};

typedef struct{
		int x;
		int y;
	}pos;

int main(){

	srand(time(NULL));
	char campo[N][N], lettera='A';
	enum movement move;
	pos position;

	position.x=0;
	position.y=0;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			campo[i][j]='.';
	}
	
	

	while(lettera<='Z'){
		move=rand()%4;
		if((campo[position.y+1][position.x]!='.') && (campo[position.y-1][position.x]!='.') &&
		   (campo[position.y][position.x+1]!='.') && (campo[position.y][position.x-1]!='.')){
		   	campo[position.y][position.x]=lettera;
			break;
		}
		if(move==su && position.y-1>=0 && campo[position.y-1][position.x]=='.'){
			campo[position.y][position.x]=lettera;
			lettera++;
			position.y--;
		}

		if(move==giu && position.y+1<N && campo[position.y+1][position.x]=='.'){
			campo[position.y][position.x]=lettera;
			lettera++;
			position.y++;
		}
		if(move==dx && position.x+1<N && campo[position.y][position.x+1]=='.'){
			campo[position.y][position.x]=lettera;
			lettera++;
			position.x++;
		}
		if(move==dx && position.x-1>=0 && campo[position.y][position.x-1]=='.'){
			campo[position.y][position.x]=lettera;
			lettera++;
			position.x--;
		}
	}

	printf("\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%c ", campo[i][j]);
		printf("\n");
	}
	
	return 0;
}