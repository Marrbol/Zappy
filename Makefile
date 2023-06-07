##
## EPITECH PROJECT, 2023
## B-YEP-400-REN-4-1-zappy-martin.boucault
## File description:
## Makefile
##

SRCSERV = Server/Server.cpp\

SRCENCAPS = network/Network.cpp\

SRCIA = IA/IA.cpp\
		Materiaux/Materiaux.cpp\
		IA/CommunicateWithServer.cpp

SRCGUI = GUI/GUI.cpp\

OBJSERV = $(SRCSERV:.cpp=.o)

OBJIA = $(SRCIA:.cpp=.o)

OBJGUI = $(SRCGUI:.cpp=.o)

OBJENCAPS = $(SRCENCAPS:.cpp=.o)

NAMESERV = zappy_server

NAMEIA = zappy_ai

NAMEGUI = zappy_gui

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 -I./include -g3

all: $(NAMESERV) $(NAMEIA) $(NAMEGUI)

serv : $(NAMESERV)

ia : $(NAMEIA)

gui : $(NAMEGUI)

$(NAMESERV): $(OBJSERV)
	$(CXX) $(OBJSERV) -o $(NAMESERV) $(CXXFLAGS)

$(NAMEIA): $(OBJIA) $(OBJENCAPS)
	$(CXX) $(OBJIA) $(OBJENCAPS) -o $(NAMEIA) $(CXXFLAGS)

$(NAMEGUI): $(OBJGUI) $(OBJENCAPS)
	$(CXX) $(OBJGUI) $(OBJENCAPS) -o $(NAMEGUI) $(CXXFLAGS)

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
