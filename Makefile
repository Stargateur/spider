##
## Makefile for makefile in /home/plasko_a/projet/epitech/cpp_spider
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Sun Oct 18 06:48:22 2015 Antoine Plaskowski
## Last update Sun Oct 18 06:58:36 2015 Antoine Plaskowski
##

SERVER		=	spider_server

CLIENT		=	spider_client

CXX		?=	g++

RM		=	rm

MAKE		=	make

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=	

INCLUDE		=	-I include -I include/server -I include/client

CFLAGS		+=	-Wall -Wextra -O$(LEVEL)
CFLAGS		+=	-ansi -pedantic
CFLAGS		+=	$(INCLUDE)
CFLAGS          +=      -D _POSIX_SOURCE -D _GNU_SOURCE -D _XOPEN_SOURCE

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic
CXXFLAGS	+=	$(INCLUDE)

ifeq ($(CC), clang)
CFLAGS		+=	-Weverything -Wno-padded -Wno-disabled-macro-expansion
endif

ifeq ($(CXX), clang++)
CXXFLAGS	+=	-Weverything -Wno-padded -Wno-disabled-macro-expansion
endif

ifneq ($(DEBUG), no)
CFLAGS		+=	-g
CXXFLAGS	+=	-g
endif

ifneq ($(COLOR), no)
CFLAGS		+=	-fdiagnostics-color
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

all		:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(OBJ_SERVER)
			$(CC) $(OBJ_SERVER) -o $(SERVER) $(LDFLAGS)

$(CLIENT)	:	$(OBJ_CLIENT)
			$(CXX) $(OBJ_CLIENT) -o $(CLIENT) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ_SERVER)
			$(RM) -f $(OBJ_CLIENT)
			$(RM) -f $(DPD_SERVER)
			$(RM) -f $(DPD_CLIENT)

fclean		:	clean
			$(RM) -f $(SERVER)
			$(RM) -f $(CLIENT)

re		:	fclean
			$(MAKE) -C . all

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
