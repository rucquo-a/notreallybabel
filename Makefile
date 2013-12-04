SRC_DIR=	Src/
INC_DIR=	./Include/
DYN_DIR=	Src/lib/

DYN_SRC=	PuzzleWin.cpp \
		PuzzleSprite.cpp \
		PuzzleGame.cpp

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

DYN_OBJ=	$(DYN_SRC_FIN:.cpp=.o)

SRC_OBJ=	$(SRC_FILE:.cpp=.o)

CPPFLAGS=	-I$(INC_DIR) -g

LIBS=		-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lssl

NAME=		LeapArcade

NAME_DYN=	./Ressources/Game/PuzzleGame.so



all:		lib $(NAME)


$(NAME):	$(SRC_OBJ)
		g++ -o $@ $(SRC_OBJ) $(LIBS)

lib:		$(DYN_OBJ)
	g++ -shared -o $(NAME_DYN) $(DYN_OBJ)

%.o:            %.cpp
	g++ -fPIC -o $@ -c $< $(CPPFLAGS)

clean:
	rm -f $(SRC_OBJ) $(DYN_OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all