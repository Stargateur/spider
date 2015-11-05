##
## Makefile for makefile in /home/plasko_a/projet/epitech/cpp_spider
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Sun Oct 18 06:48:22 2015 Antoine Plaskowski
## Last update Fri Nov  6 00:22:03 2015 Antoine Plaskowski
##

SERVER		=	spider_server

PATH_TIME	=	lib/time/

PATH_SOCKET	=	lib/socket/

PATH_PROTOCOLV1	=	lib/protocolv1/

PATH_DATABASE	=	lib/database/

CXX		?=	g++

RM		=	rm

MAKE		=	make

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=	-l dl

INCLUDE		=	-I include -I include/server -I include/client -I include/lib

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic -std=c++11
CXXFLAGS	+=	$(INCLUDE)

ifeq ($(CXX), clang++)
CXXFLAGS	+=	-Weverything -Wno-padded -Wno-disabled-macro-expansion -Wno-c++98-compat -Wno-return-type-c-linkage -Wno-c++98-compat-pedantic
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

include			server.mk

DPD_SERVER	=	$(SRC_SERVER:.cpp=.dpd)

OBJ_SERVER	=	$(SRC_SERVER:.cpp=.o)

all		:	$(SERVER) $(TIME) $(SOCKET)
			$(MAKE) -C $(PATH_TIME)
			$(MAKE) -C $(PATH_SOCKET)
			$(MAKE) -C $(PATH_PROTOCOLV1)
			$(MAKE) -C $(PATH_DATABASE)

$(SERVER)	:	$(OBJ_SERVER)
			$(CXX) $(OBJ_SERVER) -o $(SERVER) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ_SERVER)
			$(RM) -f $(DPD_SERVER)
			$(MAKE) -C $(PATH_TIME) clean
			$(MAKE) -C $(PATH_SOCKET) clean
			$(MAKE) -C $(PATH_PROTOCOLV1) clean
			$(MAKE) -C $(PATH_DATABASE) clean

fclean		:	clean
			$(RM) -f $(SERVER)
			$(MAKE) -C $(PATH_TIME) fclean
			$(MAKE) -C $(PATH_SOCKET) fclean
			$(MAKE) -C $(PATH_PROTOCOLV1) fclean
			$(MAKE) -C $(PATH_DATABASE) fclean

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

include			$(DPD_SERVER)
