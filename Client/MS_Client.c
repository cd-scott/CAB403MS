//CAB403 Assignment 2018 Sem2 - Client main
//Written by Grant Dare n9476512
//in conjunction with Callum Scott

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h>

#define MAXDATASIZE 300
#define NUM_TILES_X 9
#define NUM_TILES_Y 9
#define NUM_MINES 10

typedef struct{
	int adjacent_mines;
	bool revealed;
	bool is_flag;
} Tile;

//Client authentication variables
char username[30];
char password[30];
void Menu(void);

int minesRemaining = 0;
void initialiseGame(void);
void drawGame(void);
char coord[NUM_TILES_Y] = {'A','B','C','D','E','F','G','H','I'};
Tile game[NUM_TILES_X][NUM_TILES_Y];
bool playing = false;

int main(int argc, char* argv[]){
	int sockfd, numbytes, i=0;  
	char buf[MAXDATASIZE];
	struct hostent *he;
	struct sockaddr_in host_addr;
	/*
	//process the input arguments
	if (argc != 3) {
		fprintf(stderr,"usage: client_hostname port_number\n");
		exit(1);
	}

	//Connect to the server
	if ((he=gethostbyname(argv[1])) == NULL) {
		herror("gethostbyname");
		exit(1);
	}
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(atoi(argv[2]));
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);
	
	if (connect(sockfd, (struct sockaddr *)&their_addr, \
	sizeof(struct sockaddr)) == -1) {
		perror("connect");
		exit(1);
	}
	*/

	//User menu
	printf("===============================================\n");
	printf("Welcome to the online Minesweeper gaming system\n");
	printf("===============================================\n\n");
	printf("You are required to log on with your registered user name and password.\n\n");
	printf("User name:");
	scanf("%s", &username);
	printf("Password:");
	scanf("%s", password);
	//TODO: send this and check the server. For client testing, assume correct.
	while(1){
		//show the main menu
		Menu();

		//loop the play logic while playing
		while(playing){
			char selection[10];
			char tile[10];
			drawGame();
			printf("Choose an option:\n<R> Reveal a tile\n<P> Place flag\n<Q> Quit game\n\n");
			printf("Option (R, P, Q): ");
			scanf(" %c", &selection);
			printf("%c\n", selection);
			if(*selection == 'R' || *selection == 'r'){
				printf("\nSelect a tile to reveal (eg:A1): ");
				scanf(" %c", &tile);
				//TODO send this data to the server and then update the tile states based on this data
			}
			else if(*selection == 'P' || *selection == 'r'){
				printf("\nSelect a tile to place a flag on (eg:A1): ");
				scanf(" %c", &tile);
				//TODO send this data to the server and then update the tile states based on this data
			}
			printf("\n");
			

		}
	}
}

void Menu(void){
	int selection = 0;
	//play menu
	printf("Welcome to the Minesweeper gaming system.\n\n");
	printf("Please enter a selection:\n<1> Play Minesweeper\n<2> Show Leaderboard\n<3> Quit\n\n");
	printf("Selection option (1-3):");
	scanf("%d", &selection);

	switch(selection){
		case 1:
			initialiseGame();
			playing = true;
			break;
		case 2:
			//show leaderboard
			break;
		default:
			exit(1);
	}
}

void initialiseGame(void){
	//initialise the Minesweeper
	minesRemaining = NUM_MINES;
	for(int i = 0; i < NUM_TILES_Y; i++){
		for(int d = 0; d < NUM_TILES_X; d++){
			//starting state is everything is no flag and not revealed
			game[d][i].is_flag = false;
			game[d][i].revealed = false;
			game[d][i].adjacent_mines = 0;
		}
	}
}

void drawGame(void){

	//setup the Y frame
	printf("Remaining mines: %d\n\n", minesRemaining);
	for(int i = 1; i <= NUM_TILES_X; i++){
		printf("\t%d", i);
	}
	printf("\n");
	for(int i = 1; i <= NUM_TILES_X; i++){
		printf("\t-");
	}
	printf("\n");

	for(int i = 0; i<NUM_TILES_Y; i++){
		//write the X coordinate to the start of the line
		printf("%c |\t", coord[i]);
		for(int d = 0; d<= NUM_TILES_X; d++){
			//if flagged then print that, ignore adjacent tiles parameter
			if(game[d][i].is_flag==true){
				printf("+\t");
			}
			//if revealed is true then print the adjacent tiles parameter
			else if(game[d][i].revealed==true){
				printf("%d\t", game[d][i].adjacent_mines);
			}
			//else ignore and print nothing
			else{
				printf(" \t");
			}
		}
		printf("\n\n");
	}

}