#########################################
#				VARIABLES				#
#########################################

# Name of the lib to create 
NAME = libft.a

# Compiler and options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
D_SRCS 			= srcs/
D_INCS 			= incs/

D_BOOLEANS 		= booleans/
D_CONVERSIONS 	= conversions/
D_COUNTERS		= counters/
D_DPRINTF		= dprintf/
D_GNL 			= gnl/
D_LISTS 		= lists/
D_MEMORY 		= memory/
D_PRINTS 		= prints/
D_PROJECTS 		= projects/
D_STRINGS 		= strings/

D_OBJS 			= objs/

# Shortcuts
INCS 	= 	$(addprefix $(D_INCS), $(LST_INCS))

SRCS	= 	$(addprefix $(D_SRCS)$(D_BOOLEANS), $(LST_BOOLEANS))			\
			$(addprefix $(D_SRCS)$(D_CONVERSIONS), $(LST_CONVERSIONS))		\
			$(addprefix $(D_SRCS)$(D_COUNTERS), $(LST_COUNTERS))			\
			$(addprefix $(D_SRCS)$(D_PROJECTS)$(D_DPRINTF), $(LST_DPRINTF))	\
			$(addprefix $(D_SRCS)$(D_PROJECTS)$(D_GNL), $(LST_GNL))			\
			$(addprefix $(D_SRCS)$(D_LISTS), $(LST_LISTS))					\
			$(addprefix $(D_SRCS)$(D_MEMORY), $(LST_MEMORY))				\
			$(addprefix $(D_SRCS)$(D_PRINTS), $(LST_PRINTS))				\
			$(addprefix $(D_SRCS)$(D_STRINGS), $(LST_STRINGS))

OBJS	=	$(subst $(D_SRCS),$(D_OBJS),$(SRCS:.c=.o))

# Files
LST_INCS 		=	libft.h					ft_booleans.h 			\
					ft_conversions.h 		ft_counters.h 			\
					ft_lists.h 				ft_memory.h				\
					ft_prints.h				ft_strings.h 			\
					get_next_line.h			ft_dprintf.h

LST_BOOLEANS 	=	ft_isalpha.c 			ft_isdigit.c			\
					ft_isalnum.c			ft_isascii.c			\
					ft_isprint.c			is_in_charset.c			\
					ft_iswhitespace.c

LST_CONVERSIONS = 	ft_toupper.c 			ft_tolower.c			\
					ft_atoi.c				ft_itoa.c				\
					ft_itoabase.c			ft_strmapi.c 			\
					ft_striteri.c			ft_atoi_int.c

LST_COUNTERS 	=	ft_strlen.c				ft_strlcpy.c			\
					ft_strlcat.c			ft_arraylen.c			\
					ft_countwords.c

LST_DPRINTF		=	ft_dprintf.c			conversion_functions.c 			\
					buffer_functions.c

LST_GNL			=	get_next_line_utils.c	get_next_line.c		

LST_LISTS 		=	ft_lstnew.c				ft_lstadd_front.c 		\
					ft_lstsize.c			ft_lstlast.c 			\
					ft_lstadd_back.c 		ft_lstdelone.c 			\
					ft_lstclear.c			ft_lstiter.c 			\
					ft_lstmap.c

LST_MEMORY 		=	ft_memset.c				ft_bzero.c				\
					ft_memcpy.c				ft_memmove.c			\
					ft_memchr.c				ft_memcmp.c				\
					ft_calloc.c

LST_PRINTS 		= 	ft_putchar_fd.c			ft_putstr_fd.c			\
					ft_putendl_fd.c			ft_putnbr_fd.c

LST_PROJECTS 	=	ft_printf.c				get_next_line.c
			
LST_STRINGS 	=	ft_strchr.c				ft_strrchr.c			\
					ft_strncmp.c			ft_strnstr.c			\
					ft_strdup.c 			ft_substr.c 			\
					ft_strjoin.c 			ft_strtrim.c			\
					ft_split.c				ft_strjoin_realloc.c	\
					ft_split_charset.c		ft_strncpy.c

#########################################
#				   RULES				#
#########################################

.PHONY : all
all : $(NAME)

# How to create the lib
$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

# Compile the .c in .o to create the object files
$(D_OBJS)%.o: $(D_SRCS)%.c Makefile $(INCS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INCS)

.PHONY: dev
dev:
	$(MAKE) CFLAGS="-g3 -w" all
# Delete all the .o files
.PHONY : clean
clean :
	@echo "clean objs from /libft"
	@rm -rf $(D_OBJS)

# Delete all the .o files + the lib file
.PHONY : fclean
fclean :
	@$(MAKE) --no-print-directory clean
	@echo "clean $(NAME) from /libft"
	@rm -rf $(NAME)

# Delete everything and make
.PHONY : re
re :
	$(MAKE) fclean
	$(MAKE) all