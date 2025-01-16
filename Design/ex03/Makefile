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

NAME        = Mediator
CFLAGS      = -pedantic -g -Wall -Wextra -Werror
TESTFLAGS	= -lgtest -lgtest_main  -fprofile-arcs -ftest-coverage
CC			= c++
RM          = rm -rf
SRCS_PATH	= src/
OBJS_PATH	= obj/
DEPS_PATH	= deps/
PERSON_PATH	= 	Person/
FORMS_PATH	= 	Forms/

MAKE_OBJ_DIR = $(OBJS_PATH) $(addprefix $(OBJS_PATH), $(PERSON_PATH) $(FORMS_PATH)) \
				$(addprefix $(DEPS_PATH), $(PERSON_PATH) $(FORMS_PATH))

INCS        = $(shell find ./includes -type d -exec echo -I{} \;)


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

PERSON_SRC		=  Headmaster.cpp Person.cpp 
PERSON_FILES	= $(addprefix $(PERSON_PATH), $(PERSON_SRC))


SRC        		=	main.cpp Mediator.cpp $(PERSON_FILES) 

DEPS			= 	$(addprefix $(DEPS_PATH), $(SRC:.cpp=.d))

OBJS 			=	$(addprefix $(OBJS_PATH), $(SRC:.cpp=.o))

all: $(NAME)


echo:
	@echo $(OBJS)
	@echo $(DEPS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(LIGHT_GREEN)Created $(NAME) executable$(DEF_COLOR)"
	
$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp | $(MAKE_OBJ_DIR) $(DEPS_PATH)
			@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCS) -MMD -MP -c $< -o $@
			@mv $(basename $@).d $(patsubst $(SRCS_PATH)%,$(DEPS_PATH)%,$(dir $<))


$(MAKE_OBJ_DIR):
	@echo "$(GREEN)Creating $(NAME) Obj Dir $(DEF_COLOR)"
	@mkdir -p $(MAKE_OBJ_DIR)


$(DEPS_PATH):
	@echo "$(GREEN)Creating $(NAME) Deps Dir $(DEF_COLOR)"
	@mkdir -p $(DEPS_PATH)


-include $(DEPS)

TEST_PATH	= tests/

TEST_SRC = test.cpp test_lists.cpp 

TEST_SRC := $(addprefix $(TEST_PATH), $(TEST_SRC))

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
