SRC_DIR=	Src/
INC_DIR=	./Include/
DYN_DIR=	Src/lib/

DYN_SRC=	PuzzleWin.cpp \
		PuzzleSprite.cpp \
		PuzzleGame.cpp 

DYN2_SRC=	TetrisGame.cpp \
		TetrisPart.cpp \
		TetrisMap.cpp \
		TetrisWin.cpp \
		TetrisOver.cpp

OTHERDYN_SRC=	AWin.cpp \
		Button.cpp

GRAPH_SRC=	Choose.cpp \
		AWin.cpp \
		Win.cpp \
		Leave.cpp \
		Button.cpp

SRC_FILE=	$(addprefix $(SRC_DIR), $(GRAPH_SRC)) \
		$(addprefix $(SRC_DIR), main.cpp)

DYN_SRC_FIN=	$(addprefix $(SRC_DIR), $(GRAPH_SRC)) \
		$(addprefix $(DYN_DIR), $(DYN_SRC))

DYN2_SRC_FIN=	$(addprefix $(SRC_DIR), $(GRAPH_SRC)) \
		$(addprefix $(DYN_DIR), $(DYN2_SRC))

DYN_OBJ=	$(DYN_SRC_FIN:.cpp=.o)

DYN2_OBJ=	$(DYN2_SRC_FIN:.cpp=.o)

SRC_OBJ=	$(SRC_FILE:.cpp=.o)

CPPFLAGS=	 -I$(INC_DIR) -g

LIBS=		-L./home/grocko_t/SFML-2.0/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lm -I ./leap/include -L ./leap -lLeap

NAME=		LeapArcade

NAME_DYN=	./Ressources/Game/PuzzleGame.so

NAME_DYN2=      ./Ressources/Game/TetrisGame.so


all:		lib $(NAME)


$(NAME):	$(SRC_OBJ)
		g++ -o $@ $(SRC_OBJ) -L /home/grocko_t/SFML-2.0/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lm -I ./leap/include -L ./leap -lLeap

lib:		$(DYN_OBJ) $(DYN2_OBJ)
		g++ -shared -o $(NAME_DYN) $(DYN_OBJ) -I ./leap/include -L ./leap -lLeap
		g++ -shared -o $(NAME_DYN2) $(DYN2_OBJ) -I ./leap/include -L ./leap -lLeap

%.o:            %.cpp
	g++ -fPIC -o $@ -c $< $(CPPFLAGS) -I /home/grocko_t/SFML-2.0/include -I ./leap/include -L ./leap -lLeap

clean:
	rm -f $(SRC_OBJ) $(DYN_OBJ) $(DYN2_OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all