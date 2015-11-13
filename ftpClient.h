/*******************************************************************************
 * Created By       : Mollard Rémi
 * Creation Date    : 01/09/2015
 * Last Changed By  : Mollard Rémi
 * Last Change      : 20/09/2015 - 19:00
 * Purpose          : Fichier header du bot pour la partie client
 *
 *******************************************************************************/
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>


#define MAXBUFFER 2048
#define TRUE 1
#define FALSE 0

#define FTP_CLIENT_DEFAULT_TIMEOUT   20000
#define FTP_CLIENT_SOCKET_MIN_TX_BUFFER_SIZE   1430
#define FTP_CLIENT_SOCKET_MIN_RX_BUFFER_SIZE   1430




typedef struct ctxClient{
	IpAddr serverAddress;
	int	passivMode;
	Socket *controleSock;
	Socket *dataSock;
	char buffer[MAXBUFFER];
}struct_ctxClient;

int ftpConnect(ctxClient* contextClient, IpAddr Server, int serverPort);
int ftpLogin(ctxClient* contextClient, const char * username, const char * password);
int ftpSetPort(ctxClient* contextClient, IpAddr * ipaddrServer, int port);
int ftpSendCommand(ctxClient* contextClient, const * char command, int * replycode);

int main(int argc, char *argv[]){
	
	//printf("Use: %s (<server IP> | <host>) <user name> <password>\n", argv[0]);


	//int j = 0, nb;
	
	char cmd[1024], *param;
	//int i;
	
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
				//connectFTP(param);
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
	
	printf("Bye bye.");
	
	return 1;
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

int ftpConnect(ctxClient* contextClient, IpAddr ipServer, int serverPort)
{	
	error_t error;
	 if(contextClient == NULL)
	 {
          return ERROR_INVALID_PARAMETER;
	  }
	  memset(contextClient, 0, sizeof(ctxClient));
	  contextClient->serverAddr = *ipServer;
	  
	//Mode Passif ?
	  
	contextClient->controleSock = socketOpen(SOCKET_TYPE_STREAM, SOCKET_IP_PROTO_TCP);

	//Specify the size of the send buffer
	error = socketSetTxBufferSize(contextClient->controleSock,FTP_CLIENT_SOCKET_MIN_TX_BUFFER_SIZE);
 
    //Specify the size of the receive buffer
    error = socketSetRxBufferSize(contextClient->controleSock, FTP_CLIENT_SOCKET_MIN_RX_BUFFER_SIZE);

    //Connect to the FTP server
    error = socketConnect(contextClient->controleSocket, ipServer, serverPort);

	if(error)
	{
		//Clean up side effects
		socketClose(context->controlSocket);
		context->controlSocket = NULL;
	}

	//Return status code
	return error;
}
