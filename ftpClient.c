#include "ftpClient.h"

int makeClientSocket(const char *hostname, int port){
    int sock;
    struct hostent *host;
    struct sockaddr_in addr;
    if((host = gethostbyname(hostname)) == NULL ){
        perror(hostname);
        abort();
    }
    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&addr, 0, sizeof(addr));
    addr.sin_family         = AF_INET;
    addr.sin_port           = htons(port);
    addr.sin_addr.s_addr    = *(long*)(host->h_addr);
    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) != 0){
        CLOSESOCKET(sock);
        perror(hostname);
        abort();
    }
    return sock;
}

int ftpConnect(ctxClient* contextClient, const char * ipServer, int serverPort)
{	

	 if(contextClient == NULL)
	 {
          return -1;
	  }
	  memset(contextClient, 0, sizeof(ctxClient));
	  
	  contextClient->serverAddress = (char*)realloc(contextClient->serverAddress,strlen(ipServer)*sizeof(char));
	  
	  strcpy(contextClient->serverAddress,ipServer);
	  
		contextClient->controleSock = makeClientSocket(contextClient->serverAddress ,serverPort);


	return 0;
}



void printPrompt(void) {
	printf("my_ftp> ");
	fflush(stdout);
}

void printHelp(void){
	printf("Les commandes FTP sont les suivantes :\n");
	printf("------------------------------------------------------------\n");
	printf(" exit 	       Quitte le ftp\n");
	printf(" open  	       Connecte le client sur le serveur\n");
	printf(" close 	       Connecte le client sur le serveur\n");
	printf(" cd  	       Changement du repertoire courant\n");
	printf(" pwd   	       Affiche le repertoire courant\n");
	printf(" get           Telechargement d`un fichier\n");
	printf(" put           Envoie un fichier sur le serveur\n");    
	printf(" del           Suppression d`un fichier\n");
	printf(" mkd           Creation d`un repertoire\n");
	printf(" rmd           Suppression d`un repertoire\n");
	printf(" ls           Affiche la liste des fichier dans le repertoire courant\n");
	printf(" help          Liste des commandes reconnues par le client\n");
	printf("------------------------------------------------------------\n");
}

int main(int argc, char *argv[]){
		
		int mySock=0;
		char cmd[1024], *param;
		int connecte = 0;
		ctxClient* client = (ctxClient*)malloc(1*sizeof(ctxClient));
		client->serverAddress = (char*)malloc(1*sizeof(char));
	
		printf("Pour voir la liste des commandes supportées tappez 'help' :\n");

		do{
			printPrompt();	
			fgets(cmd, sizeof(cmd), stdin);		
			param = strchr(cmd,' ');
			
			if (param) {
					*param=0;
						param++;
				}

			if(strcmp(cmd,"open\n\0")==0){
				if(connecte){
					printf("Vous êtes déja connecté à un serveur. \n");
				}
				else{
					printf("OK connect to server !\n");
					mySock = ftpConnect(client,"127.0.0.1", 21);

				}
			}
			else if(strcmp(cmd,"close\n\0")==0){
				printf("cd : Work in progress\n");
			}
			else if(strcmp(cmd,"cd\n\0")==0){
				printf("cd : Work in progress\n");
			}
			else if(strcmp(cmd,"pwd\n\0")==0){
				printf("pwd : Work in progress\n");
			}
			else if(strcmp(cmd,"get\n\0")==0){
				printf("get : Work in progress\n");
			}
			else if(strcmp(cmd,"put\n\0")==0){
				printf("put : Work in progress\n");
			}
			else if(strcmp(cmd,"del\n\0")==0){
				printf("del : Work in progress\n");
			}
			else if(strcmp(cmd,"mkd\n\0")==0){
				printf("mkd : Work in progress\n");
			}
			else if(strcmp(cmd,"rmd\n\0")==0){
				printf("rmd : Work in progress\n");
			}
			else if(strcmp(cmd,"dir\n\0")==0){
				printf("dir : Work in progress\n");
			}
			else if(strcmp(cmd,"help\n\0")==0){
				printHelp();
			}
			else if(strcmp(cmd,"exit\n\0")==0);
			else if(strcmp(cmd,"\n\0")==0);
			else{
				printf("Commande non reconnue \n");
			}
			
		}while(strcmp(cmd,"exit\n\0"));
	
	
    return 0;
}

