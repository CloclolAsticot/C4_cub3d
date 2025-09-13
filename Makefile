#########################################
#				VARIABLES				#
#########################################

NAME = cub3D

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPFLAGS = -MMD -MP

# Directories
D_SRCS = srcs
D_INCS = incs
D_OBJS = objs

# Source Files
FILES 	= 	initialize_player.c

SRCS 	= 		$(addprefix $(D_SRCS)/, $(FILES))

# Include Files
INCS = -I ./$(D_INCS)

# Object Files
OBJS 	= 	$(patsubst $(D_SRCS)/%.c, $(D_OBJS)/%.o, $(SRCS))

# Dependency Files
DEPS	=	$(patsubst $(D_SRCS)/%.c, $(D_OBJS)/%.d, $(SRCS))

#########################################
#				   RULES				#
#########################################

.PHONY : all
all: makelibft $(D_OBJS) $(NAME)

$(D_OBJS)/%.o: $(D_SRCS)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I libft/incs -I minilibx-linux/ $(INCS) -c $< -o $@ 


$(D_OBJS):
	mkdir -p $(D_OBJS)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

.PHONY : makelibft
makelibft:
	@$(MAKE) --no-print-directory -C libft/

.PHONY : clean
clean:
	@echo "clean objs from /$(NAME)"
	@rm -rf $(D_OBJS)

.PHONY : fclean
fclean: 
	@$(MAKE) --no-print-directory clean
	@echo "clean $(NAME) from /$(NAME)"
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory fclean -C libft/

.PHONY : re
re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all