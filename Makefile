SRC	=	src/main.cpp			\
		src/Sfml.cpp			\
		src/Triangle.cpp		\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	Triangle

CXXFLAGS	=	-std=c++17 -g3

SFML_DIR	=	external/SFML
SFML_BUILD	=	$(SFML_DIR)/build

INCLUDES	=	-I$(SFML_DIR)/include

LDFLAGS	=	-L$(SFML_BUILD)/lib -Wl,-rpath=$(SFML_BUILD)/lib \
			-lsfml-graphics -lsfml-window -lsfml-system \
			-lX11 -lXrandr -lXi -lXxf86vm -lXcursor -lXinerama -lXext \
			-lpthread -ldl -lm -lGL -ludev -lfreetype -lharfbuzz

BLUE	=	\e[34m
BOLD	=	\e[1m
CYAN	=	\e[36m
DEFAULT	=	\e[0m
GREEN	=	\e[32m
MAGEN	=	\e[35m
RED		=	\e[31m

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "$(BOLD)$(BLUE)Compiling $(NAME)...$(DEFAULT)"
	@g++ -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "$(BOLD)$(GREEN)$(NAME) compiled successfully!$(DEFAULT)"

%.o: %.cpp
	@g++ $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo -e "$(BOLD)$(RED)Cleaning object files...$(DEFAULT)"
	@rm -f $(OBJ)
	@echo -e "$(BOLD)$(GREEN)Object files cleaned successfully!$(DEFAULT)"

fclean:	clean
	@echo -e "$(BOLD)$(RED)Cleaning $(NAME)...$(DEFAULT)"
	@rm -f $(NAME)
	@echo -e "$(BOLD)$(GREEN)$(NAME) cleaned successfully!$(DEFAULT)"

re:	fclean all
