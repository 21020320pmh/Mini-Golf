all:
	g++ -Isrc/include -Lsrc/lib -o main main.cpp ball.cpp entity.cpp hole.cpp renderwindow.cpp tile.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 