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

DEFAULT	=	\033[0m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
BOLD	=	\033[1m

all:	$(NAME)

init:
	@echo "$(BOLD)$(BLUE)Download SFMl...$(DEFAULT)"
	@git submodule update --init --recursive
	@echo "$(BOLD)$(GREEN)DONE.$(DEFAULT)"
	@mkdir -p 	external/SFML/build
	@echo "$(BOLD)$(BLUE)Compiling SFMl librairy...$(DEFAULT)"
	@cd external/SFML/build && \
		cmake -B . -DCMAKE_POSITION_INDEPENDENT_CODE=ON .. -DSFML_BUILD_NETWORK=OFF -DSFML_BUILD_AUDIO=OFF -DCMAKE_INSTALL_PREFIX=$HOME/sfml && \
		cmake --build . && \
		cd lib && \
		ln -s libsfml-graphics-s.a libsfml-graphics.so && ln -s libsfml-window-s.a libsfml-window.so && ln -s libsfml-system-s.a libsfml-system.so && \
		export LD_LIBRARY_PATH="external/SFML/build/lib:$LD_LIBRARY_PATH"
	@echo "$(BOLD)$(GREEN)DONE.$(DEFAULT)"

$(NAME):	$(OBJ)
	@echo "$(BOLD)$(BLUE)Compiling $(NAME)...$(DEFAULT)"
	@g++ -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo "$(BOLD)$(GREEN)$(NAME) compiled successfully!$(DEFAULT)"

%.o: %.cpp
	@g++ $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(BOLD)$(RED)Cleaning object files...$(DEFAULT)"
	@rm -f $(OBJ)
	@echo "$(BOLD)$(GREEN)Object files cleaned successfully!$(DEFAULT)"

fclean:	clean
	@echo "$(BOLD)$(RED)Cleaning $(NAME)...$(DEFAULT)"
	@rm -f $(NAME)
	@echo "$(BOLD)$(GREEN)$(NAME) cleaned successfully!$(DEFAULT)"

re:	fclean all
