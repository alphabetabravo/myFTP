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
