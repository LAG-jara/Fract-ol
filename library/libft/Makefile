# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 14:27:09 by alajara-          #+#    #+#              #
#    Updated: 2023/07/27 17:06:32 by alajara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifneq (,$(findstring xterm,${TERM}))
	DEF_CLR     := \033[0;39m
	GRAY        := \033[0;90m
	RED         := \033[0;91m
	GREEN       := \033[0;92m
	YELLOW      := \033[0;93m
	BLUE        := \033[0;94m
	MAGENTA     := \033[0;95m
	CYAN        := \033[0;96m
	WHITE       := \033[0;97m
endif

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_atoi.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memmove.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_itoa.c \
	ft_split.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c  \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_printf.c \
	ft_utils_hex.c \
	ft_utils_dec.c \
	ft_utils_txt.c \
	ft_utils_ptr.c 

# incluir printf y GNL	

OBJS = ${SRCS:.c=.o}
RM = rm -f
DEPS = ${SRCS:.c=.d}

%.o: %.c Makefile
	@${CC} ${CFLAGS} -I./ -c $< -o $@
	@printf "\r\t${BLUE}Compiling: ${YELLOW}$<${DEF_CLR}                      \r"

all:
	@$(MAKE) -s ${NAME}

${NAME}:: ${OBJS} libft.h Makefile
	@ar crs ${NAME} ${OBJS}
	@printf "\n$(GREEN)[ $(NAME) compiled! ]$(DEF_CLR)\n"

$(NAME)::
	@echo "$(WHITE)$(NAME) $(DEF_CLR)library is up to date."

-include ${DEPS}

clean:
	@${RM} ${OBJS} ${DEPS}
	@echo "${RED}[ DESTRUCTION ${GREEN}successful ]${DEF_CLR}"

fclean:
	@$(MAKE) clean
	@${RM} ${NAME}

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re bonus
