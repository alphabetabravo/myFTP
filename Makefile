################################################################################
# File Name       : Makefile                                                   #
# Created By      :                                                #
# Creation Date   :                                         #
# Last Changed By :                                                #
# Last Changed    : Octobre 20 , 2015 :   19h00                                #
# Purpose         : Fichier Makefile pour le client FTP                         #
#                  - all   : Compile all source pour le serveur                #
#                  - clean : Clean all objects and executable                  #
#                                                                              #
################################################################################
EXECUTABLE=ftpClient
SRCS=ftpClient.c
CFLAGS= -W -ansi -Wall -pedantic -std=c99
LDFLAGS=
INCLUDES=
CC=gcc
OBJECTS=$(SRCS:.c=.o)
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJECTS)

clean:
	rm $(OBJECTS) $(EXECUTABLE)
