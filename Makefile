##
## Makefile for makefile in /home/plasko_a/projet/epitech/cpp_spider
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Sun Oct 18 06:48:22 2015 Antoine Plaskowski
## Last update Thu Oct 22 07:02:02 2015 Antoine Plaskowski
##

SERVER		=	spider_server

CLIENT		=	spider_client

PATH_TIME	=	lib/time/

PATH_SOCKET	=	lib/socket/

CXX		?=	g++

RM		=	rm

MAKE		=	make

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=	$(shell pkg-config --libs libssl libcrypto)
LIB		+=	$(shell mysql_config --libs)

INCLUDE		=	-I include -I include/server -I include/client -I include/lib
INCLUDE		+=	$(shell pkg-config --cflags libssl)
INCLUDE		+=	$(shell mysql_config --cflags)

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic -std=c++11
CXXFLAGS	+=	$(INCLUDE)

ifeq ($(CXX), clang++)
CXXFLAGS	+=	-Weverything -Wno-padded -Wno-disabled-macro-expansion
endif

ifneq ($(DEBUG), no)
CXXFLAGS	+=	-g
endif

ifneq ($(COLOR), no)
CXXFLAGS	+=	-fdiagnostics-color
endif

LDFLAGS		=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

include			source_server.mk
include			source_client.mk

DPD_SERVER	=	$(SRC_SERVER:.cpp=.dpd)

OBJ_SERVER	=	$(SRC_SERVER:.cpp=.o)

DPD_CLIENT	=	$(SRC_CLIENT:.cpp=.dpd)

OBJ_CLIENT	=	$(SRC_CLIENT:.cpp=.o)

all		:	$(SERVER) $(CLIENT) $(TIME) $(SOCKET)
			$(MAKE) -C $(PATH_TIME)
			$(MAKE) -C $(PATH_SOCKET)

$(SERVER)	:	$(OBJ_SERVER)
			$(CXX) $(OBJ_SERVER) -o $(SERVER) $(LDFLAGS)

$(CLIENT)	:	$(OBJ_CLIENT)
			$(CXX) $(OBJ_CLIENT) -o $(CLIENT) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ_SERVER)
			$(RM) -f $(OBJ_CLIENT)
			$(RM) -f $(DPD_SERVER)
			$(RM) -f $(DPD_CLIENT)
			$(MAKE) -C $(PATH_TIME) clean
			$(MAKE) -C $(PATH_SOCKET) clean


fclean		:	clean
			$(RM) -f $(SERVER)
			$(RM) -f $(CLIENT)
			$(MAKE) -C $(PATH_TIME) fclean
			$(MAKE) -C $(PATH_SOCKET) fclean

re		:	fclean
			$(MAKE) -C .

%.dpd		:	%.c
			$(CC) -MM $(<) -o $(@) $(CFLAGS) -MT $(<:.c=.o)

%.o		:	%.c
			$(CC) -c $(<) -o $(@) $(CFLAGS)

%.dpd		:	%.cpp
			$(CXX) -MM $(<) -o $(@) $(CXXFLAGS) -MT $(<:.cpp=.o)

%.o		:	%.cpp
			$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.c .dpd.c .o.cpp .dpd.cpp

include			$(DPD_SERVER) $(DPD_CLIENT)
