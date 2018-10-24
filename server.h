#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> //Write
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <sys/wait.h>


/* ---- Defines ---- */
#define PORT                12345
#define PORT_LENGTH         6
#define NO_FLAGS            0
#define BACKLOG             10
#define BUF_SIZE            256
#define DISCONNECT_SIGNAL   "QUIT"
#define PLAY_MINESWEEPER    1
#define SHOW_LEADERBOARD    2
#define QUIT                3
#define USERNAME_LENGTH     10
#define PASSWORD_LENGTH     10
#define MAX_CLIENTS         10


/* ---- Menu Graphics ---- */
const char WELCOME_MESSAGE[] = "\n"
                              "=============================================\n"
                              "\n"
                              " Welcome to the Online Minesweeper the Game System\n"
                              "\n"
                              "=============================================\n"
                              "\n";

const char LOGIN_PROMPT[] = "You are required to logon with your username and password:\n";

const char USERNAME_PROMPT[] = "\nPlease enter your username --> ";
const char PASSWORD_PROMPT[] = "\nPlease enter your password --> ";

const char *AUTH_FILE = "Authentication.txt";

const char AUTH_FAILED[] = "\nYou entered either an incorrect username or password - disconnecting...\n";

const char MAIN_MENU[] = "\n"
                        "\n"
                        "===== Main Manu =====\n"
                        "\n"
                        "<1> Play Minesweeper\n"
                        "<2> Show Leaderboard\n"
                        "<3> Quit\n";

const char MENU_PROMPT[] = "\nSelection option (1 - 3) --> ";

const char NO_LEADERBOARD[] = "\n==============================================================================\n"
                              "\nThere is no information currently stored in the Leader Board. Try again later.\n"
                              "\n==============================================================================\n";