#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "Entity.h"
#include "Ball.h"	
#include "Tile.h"
#include "Hole.h"

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "SDL_Init has failed. Error: " << SDL_GetError() << std::endl;
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	if ( TTF_Init() < 0 )
		fprintf(stderr, "Couldn't initialize TTF: %s\n",SDL_GetError());
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	return true;
}

bool SDLinit = init();

RenderWindow window("Mini-Golf", 320, 480);

SDL_Texture* ballTexture = window.loadTexture("res/gfx/ball.png");
SDL_Texture* holeTexture = window.loadTexture("res/gfx/hole.png");
SDL_Texture* pointTexture = window.loadTexture("res/gfx/point.png");
SDL_Texture* tileDarkTexture32 = window.loadTexture("res/gfx/tile32_dark.png");
SDL_Texture* tileDarkTexture64 = window.loadTexture("res/gfx/tile64_dark.png");
SDL_Texture* tileLightTexture32 = window.loadTexture("res/gfx/tile32_light.png");
SDL_Texture* tileLightTexture64 = window.loadTexture("res/gfx/tile64_light.png");
SDL_Texture* ballShadowTexture = window.loadTexture("res/gfx/ball_shadow.png");
SDL_Texture* bgTexture = window.loadTexture("res/gfx/bg.png");
SDL_Texture* uiBgTexture = window.loadTexture("res/gfx/UI_bg.png");
SDL_Texture* levelTextBgTexture = window.loadTexture("res/gfx/levelText_bg.png");
SDL_Texture* powerMeterTexture_FG = window.loadTexture("res/gfx/powermeter_fg.png");
SDL_Texture* powerMeterTexture_BG = window.loadTexture("res/gfx/powermeter_bg.png");
SDL_Texture* powerMeterTexture_overlay = window.loadTexture("res/gfx/powermeter_overlay.png");
SDL_Texture* endscreenOverlayTexture = window.loadTexture("res/gfx/end.png");
SDL_Texture* splashBgTexture = window.loadTexture("res/gfx/splashbg.png");

Mix_Chunk* chargeSfx = Mix_LoadWAV("res/sfx/charge.mp3");
Mix_Chunk* swingSfx = Mix_LoadWAV("res/sfx/swing.mp3");
Mix_Chunk* holeSfx = Mix_LoadWAV("res/sfx/hole.mp3");

SDL_Color white = { 255, 255, 255 };
SDL_Color black = { 0, 0, 0 };
TTF_Font* font32 = TTF_OpenFont("res/font/font.ttf", 32);
TTF_Font* font48 = TTF_OpenFont("res/font/font.ttf", 48);
TTF_Font* font24 = TTF_OpenFont("res/font/font.ttf", 24);

Ball balls[1] = {Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0)};
std::vector<Hole> hole = {Hole(Vector2f(0, 0), holeTexture)};

int level = 0;
std::vector<Tile> loadTiles(int level)
{
	std::vector<Tile> temp = {};
	switch(level) 
	{
		case 0:
		break;
		case 1:
			temp.push_back(Tile(Vector2f(64*3, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*4, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*0, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*1, 64*3), tileDarkTexture64));
		break;
		case 2:
			temp.push_back(Tile(Vector2f(64*2, 64*3), tileDarkTexture64));
		break;
		case 3:
			temp.push_back(Tile(Vector2f(32*0, 32*6), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*1, 32*6), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*4, 32*6), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*5, 32*6), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(64*3, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*4, 64*3), tileDarkTexture64));
		break;
		case 4:
			temp.push_back(Tile(Vector2f(32*4, 32*10), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(32*1, 32*5), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*3, 32*3), tileDarkTexture32));
		break;
		case 5:
			temp.push_back(Tile(Vector2f(32*3, 32*1), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*1, 32*3), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*4, 32*2), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*2, 32*4), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*5, 32*3), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*3, 32*5), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*6, 32*4), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*4, 32*6), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*8, 32*6), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*5), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*10), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*4, 32*9), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*8, 32*9), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*3, 32*10), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*5, 32*12), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*6, 32*11), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*10), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*4, 32*7), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(32*8, 32*7), tileDarkTexture64));
		break;

	}
	return temp;
}

std::vector<Tile> tiles = loadTiles(level);

bool gameRunning = true;
bool mouseDown = false;
bool mousePressed = false;
bool swingPlayed = false;

SDL_Event event;

int state = 0; //0 = title screen, 1 = game, 2 = end screen

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

void loadLevel(int level)
{
	if (level > 5)
	{
		state = 2;
		return;
	}
	balls[0].setVelocity(0, 0);
    balls[0].setScale(1, 1);
	balls[0].setWin(false);

	tiles = loadTiles(level);

	switch (level)
	{
		case 0:
			balls[0].setPos(24 + 32*4, 24 + 32*11);

			hole.at(0).setPos(24 + 32*4, 22 + 32*2);
		break;
		case 1:
			balls[0].setPos(8 + 32*3, 8 + 32*9);

			hole.at(0).setPos(8 + 32, 6 + 32*2);
		break;
		case 2:
			balls[0].setPos(24 + 32*4, 24 + 32*11);

			hole.at(0).setPos(24 + 32*4, 22 + 32*2);
		break;
		case 3:
			balls[0].setPos(8 + 32*6, 8 + 32*10);

			hole.at(0).setPos(8 + 32*4, 6 + 32*4);
		break;
		case 4:	
			balls[0].setPos(24 + 32*2, 24 + 32*12);

			hole.at(0).setPos(24 + 32*1, 22 + 32*1);
		break;
		case 5:
			balls[0].setPos(24 + 32*2, 24 + 32*12);

			hole.at(0).setPos(24 + 32*1, 22 + 32*1);
		break;
	}
}

const char* getStrokeText()
{
	int biggestStroke = 0;
		biggestStroke = balls[0].getStrokes();

	std::string s = std::to_string(biggestStroke);
	s = "STROKES: " + s;
	return s.c_str();
}

const char* getLevelText(int side)
{
	int tempLevel = level;
	std::string s = std::to_string(tempLevel);
	s = "HOLE: " + s;
	return s.c_str();
}

void update()
{
	
	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

	mousePressed = false;
	//Get our controls and events
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = true;
				mousePressed = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = false;
			}
			break;
		}
	}

	if (state == 1)
	{
		for (Ball& b : balls)
		{
			b.update(deltaTime, mouseDown, mousePressed, tiles, hole, chargeSfx, swingSfx, holeSfx);
		}
		if (balls[0].getScale().x < -1 )
 		{
        	level++;
			loadLevel(level);
    	}
	}
}

void graphics()
{
	window.clear();
	window.render(0, 0, bgTexture);
	for (Hole& h : hole)
	{
		window.render(h);
	}
	for (Ball& b : balls)
	{
		if (!b.isWin())
		{
			window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
		}
		for (Entity& e : b.getPoints())
		{
			window.render(e);
		}
		window.render(b);
	}
	for (Tile& t : tiles)
	{ 
		window.render(t);
	}
	for (Ball& b : balls)
	{
		for (Entity& e : b.getPowerBar())
		{
			window.render(e);
		}
		window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
		
	}
	if (state != 2)
	{
		window.render(640/4 - 132/2, 480 - 32, levelTextBgTexture);
		window.renderCenter(-160, 240 - 16 + 3, getLevelText(0), font24, black);
		window.renderCenter(-160, 240 - 16, getLevelText(0), font24, white);

		window.render(32*2, 0, uiBgTexture);
		window.renderCenter(-32*5, -240 + 16 + 3, getStrokeText(), font24, black);
		window.renderCenter(-32*5, -240 + 16, getStrokeText(), font24, white);
	}
	else
	{
		window.render(0, 0, endscreenOverlayTexture);
		window.renderCenter(-32*5, 3 - 32, "YOU FINISH THE GAME !", font32, black);
		window.renderCenter(-32*5, -32, "YOU FINISH THE GAME !", font32, white);
		window.renderCenter(-32*5, 3 + 32, getStrokeText(), font32, black);
		window.renderCenter(-32*5, 32, getStrokeText(), font32, white);

	}
	window.display();
}

void titleScreen()
{
	if (SDL_GetTicks() < 2000)
	{
		if (!swingPlayed)
		{
			Mix_PlayChannel(-1, swingSfx, 0);
			swingPlayed = true;
		}
		//Get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				gameRunning = false;
				break;
			}
		}

		window.clear();
		window.render(0, 0, bgTexture);
		window.render(-32*5, -28, splashBgTexture);
		window.render(32*3 , 48*4 + 3, "Pham Hieu", font32, black);
		window.render(32*3 , 48*4, "Pham Hieu", font32, white);
		window.display();
	}
	else
	{
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					Mix_PlayChannel(-1, holeSfx, 0);
					state = 1;
				}
				break;
			}
		}
		window.clear();
		window.render(0, 0, bgTexture);
		window.render(32*3 + 18, 240 - 100 + 3 - 50 + 4*SDL_sin(SDL_GetTicks()*(3.14/1500)), "Mini-Golf", font32, black);
		window.render(32*3 + 18, 240 - 100 - 50 + 4*SDL_sin(SDL_GetTicks()*(3.14/1500)), "Mini-Golf", font32, white);
		window.render(32 + 16, 360 + 3, "LEFT CLICK TO START", font32, black);
		window.render(32 + 16, 360, "LEFT CLICK TO START", font32, white);
		window.display();
	}
}
void game()
{
	if (state == 0)
	{
		titleScreen();
	}
	else
	{
		update();
		graphics();
	}
}
int main(int argc, char* args[])
{
	loadLevel(level);
	while (gameRunning)
	{
		game();
	}

	window.cleanUp();
	TTF_CloseFont(font32);
	TTF_CloseFont(font24);
	SDL_Quit();
	TTF_Quit();
	return 0;
}