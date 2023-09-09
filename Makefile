# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 18:26:19 by alajara-          #+#    #+#              #
#    Updated: 2023/06/08 20:16:50 by alajara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		#===========#
# 		||VARIABLES||
#		#===========#

# -=-=-=-=- NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME        := fractol
MKFL        := Makefile

# -=-=-=-=- CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_CLR     := \033[0;39m
GRAY        := \033[0;90m
RED         := \033[0;91m
GREEN       := \033[0;92m
YELLOW      := \033[0;93m
BLUE        := \033[0;94m
MAGENTA     := \033[0;95m
CYAN        := \033[0;96m
WHITE       := \033[0;97m

# -=-=-=-=- PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

INC_DIR := inc/								# Headers 
#SRC_DIR := src/							# Archivos main

OBJ_DIR := .objs/
DEP_DIR := .deps/

LIBS	= library/
LIB_DIR = $(LIBS)libft/

# -=-=-=-=- CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

UNAME	= $(shell uname -s)
CFLAGS	= -Wall -Wextra -Werror -W 
#XFLAGS	= -fsanitize=address -g
DFLAGS	= -MT $@ -MMD -MP
MFLAGS	= -lm -O3 -Ofast

ifeq ($(UNAME), Darwin)
	GFLAGS	= -framework OpenGL -framework Appkit -lm
	MLX_DIR	= ./$(LIBS)mlx_Darwin/
	CC		= clang
else ifeq ($(UNAME), Linux)
	GFLAGS	= -L$(MLX_DIR) -lmlx -lX11 -lm -lXext
	MLX_DIR	= ./$(LIBS)mlx_Linux/
	CC		= gcc
endif

AR	= ar -rcs
RM	= rm -f
MK	= mkdir -p
CP	= cp -f

# -=-=-=-=- FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBRARY = $(LIB_DIR) $(MLX_DIR)libmlx.a

INCLUDE = -I$(INC_DIR) -I$(MLX_DIR) \
			-I$(LIB_DIR)

SRCS	+= fractol.c \
		colors.c \
		frac_init.c \
		fractals.c \
		hooker.c \
		mlx_utils.c
		
OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addprefix $(DEP_DIR), $(addsuffix .d, $(basename $(SRCS))))

# -=-=-=-=- RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: makelib $(NAME)

makelib:
	@$(MAKE) -s -C $(MLX_DIR)
	@$(MAKE) -s -C $(LIB_DIR)
	
$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(MFLAGS) $(XFLAGS) $(OBJS) $(GFLAGS) -L $(LIBRARY) -lft -o $(NAME)
	@printf "\n$(GREEN)[ $(NAME) compiled! ]$(DEF_COLOR)\n"
	
$(NAME)::
	@echo "$(WHITE)$(NAME) $(DEF_CLR)library is up to date."

clean:
	@$(MAKE) -s clean -C $(LIB_DIR)
	@$(MAKE) -s clean -C $(MLX_DIR)
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR)
	@echo "$(BLUE)[ Test object and dependencies files cleaned. ]$(DEF_COLOR)"
	
fclean:
	@$(MAKE) -s clean -C $(MLX_DIR)
	@$(MAKE) -s fclean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR) $(BIN_DIR)
	@$(RM) $(NAME)
	@echo "$(WHITE)[ All objects, dependencies and executables removed. ]$(DEF_COLOR)"
	
re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all
	@echo "$(GREEN)[ Cleaned and rebuilt everything for Test project. ]$(DEF_COLOR)"

norm:
	@norminette fractol.h macro.h $(SRCS)
	
$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MK) $(dir $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))
	@printf "\r$(BLUE)\tCompiling: $(YELLOW)$< $(DEF_CLR)                   \r"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))
	
-include $(DEPS)

.PHONY: all clean fclean re norm
