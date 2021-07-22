#pragma once
#include "GUI/Panel.h"
#include "Texture.h"
#include "GameActor.h"

class ScoreBoard
	:public Panel
{
private:

	static ScoreBoard* instancia;

	ScoreBoard(SDL_Renderer* _renderer, int _posicionX, int _posicionY, int _ancho, int _alto, string _nombre, string _texto);
	~ScoreBoard();
public:

	static ScoreBoard* getInstancia(SDL_Renderer* _renderer, int _posicionX, int _posicionY, int _ancho, int _alto, string _nombre, string _texto);



	

};

