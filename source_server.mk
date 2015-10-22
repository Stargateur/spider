##
## source_server.mk for source_server in /home/plasko_a/projet/epitech/cpp_spider
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Sun Oct 18 06:51:58 2015 Antoine Plaskowski
## Last update Thu Oct 22 02:03:43 2015 Antoine Plaskowski
##

PATH_SRC	=	source/
PATH_SERVER	=	$(PATH_SRC)server/
PATH_LIB	=	$(PATH_SRC)lib/

SRC_SERVER	=	$(PATH_SERVER)main.cpp
SRC_SERVER	+=	$(PATH_LIB)ITime.cpp
SRC_SERVER	+=	$(PATH_LIB)ISocket.cpp
SRC_SERVER	+=	$(PATH_SERVER)create_binded_socket.cpp
SRC_SERVER	+=	$(PATH_SERVER)accept_client.cpp
