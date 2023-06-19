##
## EPITECH PROJECT, 2023
## B-YEP-400-REN-4-1-zappy-martin.boucault
## File description:
## Makefile
##

INC_SERV    =	./includes/					\
				./protocol

SRC_SERV	=	./src_server

CMD_AI		=	cmd_AI

CMD_GUI		=	cmd_GUI


SRCSERV = 		$(SRC_SERV)/main.c						\
				$(SRC_SERV)/print_usage.c				\
				$(SRC_SERV)/coms.c						\
				$(SRC_SERV)/server.c					\
				$(SRC_SERV)/store_coms.c				\
				$(SRC_SERV)/other_functions_server.c	\
				$(SRC_SERV)/check.c						\
				$(SRC_SERV)/create_other.c				\
				$(SRC_SERV)/utils.c						\
				$(SRC_SERV)/utils2.c					\
				$(SRC_SERV)/delete.c					\
				$(SRC_SERV)/inventory.c					\
				$(SRC_SERV)/set_coord_client.c			\
				$(SRC_SERV)/comete.c					\
				$(SRC_SERV)/map.c						\
				$(SRC_SERV)/team.c						\
				$(SRC_SERV)/login.c						\
				$(SRC_SERV)/$(CMD_AI)/broadcast.c		\
				$(SRC_SERV)/$(CMD_AI)/connect_to.c		\
				$(SRC_SERV)/$(CMD_AI)/eject.c			\
				$(SRC_SERV)/$(CMD_AI)/forks.c			\
				$(SRC_SERV)/$(CMD_AI)/forward.c			\
				$(SRC_SERV)/$(CMD_AI)/incantation.c		\
				$(SRC_SERV)/$(CMD_AI)/invent.c			\
				$(SRC_SERV)/$(CMD_AI)/left.c			\
				$(SRC_SERV)/$(CMD_AI)/look.c			\
				$(SRC_SERV)/$(CMD_AI)/right.c			\
				$(SRC_SERV)/$(CMD_AI)/set.c				\
				$(SRC_SERV)/$(CMD_AI)/take.c			\
				$(SRC_SERV)/$(CMD_GUI)/bct.c			\
				$(SRC_SERV)/$(CMD_GUI)/edi.c			\
				$(SRC_SERV)/$(CMD_GUI)/msz.c			\
				$(SRC_SERV)/$(CMD_GUI)/pdi.c			\
				$(SRC_SERV)/$(CMD_GUI)/pex.c			\
				$(SRC_SERV)/$(CMD_GUI)/pgt.c			\
				$(SRC_SERV)/$(CMD_GUI)/pie.c			\
				$(SRC_SERV)/$(CMD_GUI)/plv.c			\
				$(SRC_SERV)/$(CMD_GUI)/ppo.c			\
				$(SRC_SERV)/$(CMD_GUI)/seg.c			\
				$(SRC_SERV)/$(CMD_GUI)/smg.c			\
				$(SRC_SERV)/$(CMD_GUI)/suc.c			\
				$(SRC_SERV)/$(CMD_GUI)/ebo.c			\
  				$(SRC_SERV)/$(CMD_GUI)/enw.c			\
  				$(SRC_SERV)/$(CMD_GUI)/pbc.c			\
  				$(SRC_SERV)/$(CMD_GUI)/pdr.c			\
  				$(SRC_SERV)/$(CMD_GUI)/pfk.c			\
  				$(SRC_SERV)/$(CMD_GUI)/pic.c			\
  				$(SRC_SERV)/$(CMD_GUI)/pin.c			\
  				$(SRC_SERV)/$(CMD_GUI)/pnw.c			\
  				$(SRC_SERV)/$(CMD_GUI)/sbp.c			\
  				$(SRC_SERV)/$(CMD_GUI)/sgt.c			\
  				$(SRC_SERV)/$(CMD_GUI)/sst.c			\
  				$(SRC_SERV)/$(CMD_GUI)/tna.c			\
  				$(SRC_SERV)/$(CMD_GUI)/mct.c

SRCENCAPS = network/Network.cpp\

SRCIA = IA/IA.cpp\
		Materiaux/Materiaux.cpp\
		IA/CommunicateWithServer.cpp

SRCGUI = 	GUI/Camera.cpp\
			GUI/Cube.cpp\
			GUI/CommunicateWithServer.cpp\
			GUI/Display.cpp\
			GUI/IsometricMap.cpp\

OBJSERV = $(SRCSERV:.c=.o)

OBJIA = $(SRCIA:.cpp=.o)

OBJGUI = $(SRCGUI:.cpp=.o)

OBJENCAPS = $(SRCENCAPS:.cpp=.o)

NAMESERV = zappy_server

NAMEIA = zappy_ai

NAMEGUI = zappy_gui

CXX = g++

CC	= gcc

CXXFLAGS = -Wall -Wextra -std=c++17 -I./include -g3

CFLAGS	=   -Wall -Wextra $(foreach INCL,$(INC_SERV),-I$(INCL))

all: $(NAMESERV) $(NAMEIA) $(NAMEGUI)

serv : $(NAMESERV)

$(NAMESERV): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(CC) $(CFLAGS) -c -o $*.o $<

ia : $(NAMEIA)

gui : $(NAMEGUI)

debug: CFLAGS += -g
debug: serv

$(NAMESERV): $(OBJSERV)
	$(CXX) $(OBJSERV) -o $(NAMESERV) $(CFLAGS)

$(NAMEIA): $(OBJIA) $(OBJENCAPS)
	$(CXX) $(OBJIA) $(OBJENCAPS) -o $(NAMEIA) $(CXXFLAGS)

$(NAMEGUI): $(OBJGUI) $(OBJENCAPS)
	$(CXX) $(OBJGUI) $(OBJENCAPS) -lsfml-graphics -lsfml-window -lsfml-system -o $(NAMEGUI) $(CXXFLAGS)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
	rm -f $(OBJIA)
	rm -f $(OBJGUI)
	rm -f $(OBJSERV)

fclean: clean
	rm -f $(NAMESERV)
	rm -f $(NAMEIA)
	rm -f $(NAMEGUI)

re: fclean all

.PHONY:	clean fclean re all