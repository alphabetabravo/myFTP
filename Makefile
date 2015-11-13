################################################################################
# File Name       : Makefile                                                   #
# Created By      : MOLLARD Rémi                                               #
# Creation Date   : Octobre    1 , 2015                                        #
# Last Changed By : MOLLARD Rémi                                               #
# Last Changed    : Octobre 20 , 2015 :   19h00                                #
# Purpose         : Fichier Makefile pour le Gimly_Bot                         #
#                  - all   : Compile all source pour le serveur                #
#                  - clean : Clean all objects and executable                  #
#                                                                              #
################################################################################
EXECUTABLE=GimlyServer
SRCS=GimlyServer.cpp serverssl.cpp structureServer.cpp tools.cpp
CFLAGS= -W -ansi -Wall -pedantic
LDFLAGS= -lssl -lcrypto -lpthread
INCLUDES=
CC=g++
OBJECTS=$(SRCS:.cpp=.o)
all:  $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -f GimlyServer *.o
