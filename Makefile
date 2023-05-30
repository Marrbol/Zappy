##
## EPITECH PROJECT, 2023
## bootstrap
## File description:
## Makefile
##

##				server part					##
INC			=	./includes/					\
				./protocol

SRC			=	./src_server

CMD_AI		=	cmd_AI

CMD_GUI		=	cmd_GUI

COMPIL 		= 	$(SRC)/main.c						\
				$(SRC)/print_usage.c				\
				$(SRC)/coms.c						\
				$(SRC)/server.c						\
				$(SRC)/store_coms.c					\
				$(SRC)/other_functions_server.c		\
				$(SRC)/check.c						\
				$(SRC)/create_other.c				\
				$(SRC)/help.c						\
				$(SRC)/utils.c						\
				$(SRC)/utils2.c						\
				$(SRC)/delete.c						\
				$(SRC)/inventory.c					\
				$(SRC)/$(CMD_AI)/broadcast.c		\
				$(SRC)/$(CMD_AI)/connect_to.c		\
				$(SRC)/$(CMD_AI)/eject.c			\
				$(SRC)/$(CMD_AI)/forks.c			\
				$(SRC)/$(CMD_AI)/forward.c			\
				$(SRC)/$(CMD_AI)/incantation.c		\
				$(SRC)/$(CMD_AI)/invent.c			\
				$(SRC)/$(CMD_AI)/left.c				\
				$(SRC)/$(CMD_AI)/look.c				\
				$(SRC)/$(CMD_AI)/right.c			\
				$(SRC)/$(CMD_AI)/set.c				\
				$(SRC)/$(CMD_AI)/take.c				\
				$(SRC)/$(CMD_GUI)/bct.c				\
				$(SRC)/$(CMD_GUI)/edi.c				\
				$(SRC)/$(CMD_GUI)/msz.c				\
				$(SRC)/$(CMD_GUI)/pdi.c				\
				$(SRC)/$(CMD_GUI)/pex.c				\
				$(SRC)/$(CMD_GUI)/pgt.c				\
				$(SRC)/$(CMD_GUI)/pie.c				\
				$(SRC)/$(CMD_GUI)/plv.c				\
				$(SRC)/$(CMD_GUI)/ppo.c				\
				$(SRC)/$(CMD_GUI)/seg.c				\
				$(SRC)/$(CMD_GUI)/smg.c				\
				$(SRC)/$(CMD_GUI)/suc.c				\
				$(SRC)/$(CMD_GUI)/ebo.c				\
  				$(SRC)/$(CMD_GUI)/enw.c				\
  				$(SRC)/$(CMD_GUI)/pbc.c				\
  				$(SRC)/$(CMD_GUI)/pdr.c				\
  				$(SRC)/$(CMD_GUI)/pfk.c				\
  				$(SRC)/$(CMD_GUI)/pic.c				\
  				$(SRC)/$(CMD_GUI)/pin.c				\
  				$(SRC)/$(CMD_GUI)/pnw.c				\
  				$(SRC)/$(CMD_GUI)/sbp.c				\
  				$(SRC)/$(CMD_GUI)/sgt.c				\
  				$(SRC)/$(CMD_GUI)/sst.c				\
  				$(SRC)/$(CMD_GUI)/tna.c

NAME	=	zappy_server

OBJ	=	$(COMPIL:.c=.o)

CFLAGS	=   -Wall -Wextra $(foreach INCL,$(INC),-I$(INCL))

all: $(NAME)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(CC) $(CFLAGS) -c -o $*.o $<

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug: CFLAGS += -g
debug: all

redirect: CFLAGS += &> error.log

malloc: fclean debug
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY:	clean fclean re all debug malloc
