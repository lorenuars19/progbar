# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/19 09:27:25 by lorenuar          #+#    #+#              #
#    Updated: 2020/03/19 14:36:40 by lorenuar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= libprogbar.a

CC			= gcc

ifeq ($(D), 1)
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address
else
CFLAGS	= -Wall -Werror -Wextra
endif

OBJDIR	= objs/
SRCDIR	= src/
INCDIR	= include/

CFLAGS += -I $(INCDIR)

SRC 	= $(wildcard $(SRCDIR)*.c)
SRCS	=	$(notdir $(SRC))
OBJ		= $(SRCS:.c=.o)
OBJS	=	$(addprefix $(OBJDIR), $(OBJ))

MAIN	= main.c
EXNAME	= test

GR	= \033[32;1m
RE	= \033[31;1m
RC	= \033[0m

# Rules

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(GR)& Linking into $(NAME)$(RC)"
	@ar -rcs $(NAME) $(OBJS)

$(OBJS) : $(SRC)
	@echo "$(GR)+ Compiling $(SRC)$(RC)"
	@$(CC) $(CFLAGS) -c $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

run : $(NAME)
#@echo "$(GR)> Running $(EXNAME)$(RC)"
	@$(CC) $(CFLAGS) -c $(MAIN)
	@$(CC) $(CFLAGS) -o $(EXNAME) $(MAIN:.c=.o) $(NAME)
	@printf "\ec"
	@./$(EXNAME)

clean :
	@echo "$(RE)- Removing $(OBJS)$(RC)"
	@rm -rf $(OBJDIR)

fclean : clean
	@echo "$(RE)- Removing $(NAME) & $(EXNAME)$(RC)"
	@rm -rf $(NAME) $(EXNAME)

re : fclean all

echo :
	echo "$(OBJDIR)"
	echo "$(SRCDIR)"
	echo "$(INCDIR)"
	echo "$(SRC)"
	echo "$(OBJ)"
	echo "$(OBJS)"
	echo "$(MAIN)"
	echo "$(EXNAME)"

.PHONY : all run clean fclean re echo
