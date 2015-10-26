##
## Makefile for Time in /home/plasko_a/projet/cplusplus/cpp_spider/lib/Time
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Thu Oct 22 01:26:02 2015 Antoine Plaskowski
## Last update Mon Oct 26 14:02:59 2015 Antoine Plaskowski
##

NAME		=	lib_time_linux.so

CXX		?=	g++

RM		=	rm

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=

INCLUDE		=	-I include -I ../../include/lib

CXXFLAGS	=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic -std=c++11
CXXFLAGS	+=	-fPIC
CXXFLAGS	+=	$(INCLUDE)

ifeq ($(CXX), clang)
CXXFLAGS	+=	-Weverything -Wno-padded -Wno-disabled-macro-expansion -Wno-return-type-c-linkage
endif

ifneq ($(DEBUG), no)
CXXFLAGS	+=	-g
endif

ifneq ($(COLOR), no)
CXXFLAGS	+=	-fdiagnostics-color
endif

LDFLAGS		=	$(LIB)
LDFLAGS		+=	-shared -Wl,-e,start_lib

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

SRC		=

include			source.mk

DPD		=	$(SRC:.cpp=.dpd)

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ)
			$(RM) -f $(DPD)

fclean		:	clean
			$(RM) -f $(NAME)

re		:	fclean
			$(MAKE) -C .

%.dpd		:	%.cpp
			$(CXX) -MM $(<) -o $(@) $(CXXFLAGS) -MT $(<:.cpp=.o)

%.o		:	%.cpp
			$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.cpp .dpd.cpp

include			$(DPD)
