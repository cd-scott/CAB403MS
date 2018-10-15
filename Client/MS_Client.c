//CAB403 Assignment 2018 Sem2 - Client
//Written by Grant Dare n9476512
//in conjunction with Callum Scott

string host;
string port;

int main(int argc, char* argv[]){

	//process the input arguments
	if(argc < 2 || argc > 3){
		println("You have incorrectly executed the client.");
		return 0;
	}
	else{
		host = argv[1];
		port = argv[2];
	}
	printf("%s\n", host);
	printf("%s\n", port);
}