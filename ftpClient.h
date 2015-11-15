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
#include <errno.h>
#include <malloc.h>
#include <stddef.h>
#ifdef __unix__
#   include <unistd.h>
#   include <sys/socket.h>
#   include <netdb.h>
#   define SOCKLEN_T socklen_t
#   define CLOSESOCKET close
#endif
#define h_addr h_addr_list[0]

#define MAXBUFFER 2048
#define TRUE 1
#define FALSE 0

#define FTP_CLIENT_DEFAULT_TIMEOUT   20000
#define FTP_CLIENT_SOCKET_MIN_TX_BUFFER_SIZE   1430
#define FTP_CLIENT_SOCKET_MIN_RX_BUFFER_SIZE   1430




typedef struct {
	char * serverAddress;
	int	passivMode;
	int controleSock;
	int dataSock;
	char buffer[MAXBUFFER];
}ctxClient;


int ftpConnect(ctxClient* contextClient, const char * Server, int serverPort);
int ftpLogin(ctxClient* contextClient, const char * username, const char * password);
int ftpSetPort(ctxClient* contextClient, const char * ipaddrServer, int port);
int ftpSendCommand(ctxClient* contextClient, const char * command);
int ftpReceiveCommand(ctxClient* contextClient);
