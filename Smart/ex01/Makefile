# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 10:55:00 by lsoto-do          #+#    #+#              #
#    Updated: 2024/06/11 09:57:05 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = s[O]lid
CFLAGS      = -std=c++98 -pedantic -g -Wall -Wextra -Werror
TESTFLAGS	= -lgtest -lgtest_main  -fprofile-arcs -ftest-coverage
CC			= c++
RM          = rm -rf
SRCS_PATH	= src/
OBJS_PATH	= obj/
DEPS_PATH	= deps/

MAKE_OBJ_DIR	=	$(OBJS_PATH) $(DEPS_PATH)
INCS        = -I./includes

#Colors


DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
LIGHT_GREEN = \033[1;92m

###
 
SRC        		=	main.cpp
				
DEPS			= 	$(addprefix $(DEPS_PATH), $(SRC:.cpp=.d))

OBJS 			=	$(addprefix $(OBJS_PATH), $(SRC:.cpp=.o))

all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(LIGHT_GREEN)Created $(NAME) executable$(DEF_COLOR)"
	
$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp | $(MAKE_OBJ_DIR)
			@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCS) $(DEFINES) -MMD -MP -c $< -o $@
			@mv $(basename $@).d $(patsubst $(SRCS_PATH)%,$(DEPS_PATH)%,$(dir $<))

$(MAKE_OBJ_DIR):
	@echo "$(GREEN)Creating $(NAME) Objs and Deps Directories $(DEF_COLOR)"
	@mkdir -p $(MAKE_OBJ_DIR)


-include $(DEPS)

TEST_SRC = test.cpp

TEST_EXEC = my_test

$(TEST_EXEC): $(TEST_SRC)
	$(CC) $(DEFINES) -g -o $(TEST_EXEC) $(TEST_SRC) $(TESTFLAGS) $(INCS) 



test: $(TEST_EXEC)
	./$(TEST_EXEC)
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report


clean: clean_objects

fclean:  clean_objects
	@$(RM) $(NAME) $(TEST_EXEC) my_test* coverage*
	@echo "$(GREEN)$(NAME) executable cleaned!$(DEF_COLOR)"

clean_objects:
	@echo "$(GREEN)$(NAME) Objects and Dependencies cleaned!$(DEF_COLOR)"
	@$(RM) -r $(OBJS_PATH) $(DEPS_PATH)


re: fclean all 

.PHONY: all fclean clean re 
