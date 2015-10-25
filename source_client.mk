##
## source_client.mk for source_client in /home/plasko_a/projet/epitech/cpp_spider
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Sun Oct 18 06:51:47 2015 Antoine Plaskowski
## Last update Sun Oct 25 00:18:05 2015 Antoine Plaskowski
##

PATH_SRC	=	source/
PATH_CLIENT	=	$(PATH_SRC)client/

SRC_CLIENT	=	$(PATH_CLIENT)main.cpp
SRC_CLIENT	+=	$(PATH_CLIENT)../server/Option.cpp
SRC_CLIENT	+=	$(PATH_CLIENT)../server/DynamicLinkLibrary.cpp
