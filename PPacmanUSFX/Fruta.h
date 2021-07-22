#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>

#include "GameActor.h"
#include "Texture.h"
#include "TileGraph.h"
#include "Tile.h"

using namespace std;

enum TipoFruta {
	TIPO_FRUTA_GUINDA,
	TIPO_FRUTA_PLATANO,
	TIPO_FRUTA_NARANJA,
	TIPO_FRUTA_FRUTILLA,
	TIPO_FRUTA_MAXIMO
};

class Fruta : public GameActor {
protected:

	TipoFruta tipoFruta;

	int tiempoVisible;
	int tiempoInvisible;

	int contadorTiempoVisible;
	int contadorTiempoInvisible;
	int numeroFrutaVisible;

	//GameObjectType returType() { return FRUTA; }
public:

	//vector<Texture*>frutaTexture;
	//Constructores y destructores
	Fruta(Tile* _tile, Texture* _texture);
	~Fruta();

	//Metodos accesores
	
	TipoFruta getTipoFruta() { return tipoFruta; }
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoInvisible() { return tiempoInvisible; }

	void setTipoFruta(TipoFruta _tipoFruta) { tipoFruta = _tipoFruta; }
	void setTiempoVisible(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoInvisible(int _tiempoInvisible) { tiempoInvisible = _tiempoInvisible; }
	void setTileActual(Tile* _tileNuevo) {};

	// Metodos varios

	// Manejador de eventos de la fruta
	//void handleEvent(SDL_Event& e);

	// Mostrar u ocultar la fruta
	void update() {};
	// Renderizar imagen fruta
	//void render();
};


