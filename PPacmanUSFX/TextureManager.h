#pragma once
#include<iostream>
#include<map>
#include "Texture.h"
#include "AnimationFrames.h"
#include "SDL_Mixer.h"
using namespace std;

class TextureManager
{

private:
	const string pathPacmanClasico = "Resources/PacMan.bmp";
	const string pathFantasmaClasico1 = "Resources/Blinky.bmp";
	const string pathFantasmaClasico2 = "Resources/Clyde.bmp";
	const string pathFantasmaClasico3 = "Resources/Inkey.bmp";
	const string pathFantasmaClasico4 = "Resources/Pinky.bmp";
	const string pathFrutaClasico = "Resources/Frutas.png";
	const string pathMonedaClasico = "Resources/Monedas02.jpg";
	const string pathSuperMonedaClasico = "Resources/Monedas03.jpg";
	const string pathParedClasico = "Resources/wall.bmp";
	const string pathParedClasicoAdapter = "Resources/wall_sprite.bmp";

	const string pathPacmanGalactico = "Resources/PacMan.bmp";
	const string pathFantasmaGalactico1 = "Resources/fantasmaamarillo.bmp ";
	const string pathFantasmaGalactico2 = "Resources/azul.png ";
	const string pathFantasmaGalactico3 = "Resources/fantasma.png ";
	const string pathFantasmaGalactico4 = "Resources/fantasmarojo.bmp ";
	const string pathFrutaGalactico = "Resources/espacial2.png";
	const string pathMonedaGalactico = "Resources/monedagalactico1.png";
	const string pathSuperMonedaGalactico = "Resources/Monedas03.jpg";
	const string pathParedGalactico = "Resources/WallTextures.png";

	Texture* pacmanClasicoTexture;
	Texture* fantasmaClasico1Texture;
	Texture* fantasmaClasico2Texture;
	Texture* fantasmaClasico3Texture;
	Texture* fantasmaClasico4Texture;
	Texture* frutaClasicoTexture;
	Texture* monedaClasicoTexture;
	Texture* superMonedaClasicoTexture;
	Texture* paredClasicoTexture;
	Texture* paredClasicoAdapterTexture;

	Texture* pacmanGalacticoTexture;
	Texture* fantasmaGalactico1Texture;
	Texture* fantasmaGalactico2Texture;
	Texture* fantasmaGalactico3Texture;
	Texture* fantasmaGalactico4Texture;
	Texture* frutaGalacticoTexture;
	Texture* monedaGalacticoTexture;
	Texture* superMonedaGalacticoTexture;
	Texture* paredGalacticoTexture;

	AnimationFrames* framesAnimacionPacmanClasico;
	AnimationFrames* framesAnimacionFantasmaClasico;

private:
	map<string, Texture*> mapTexturas;
	map<string, AnimationFrames*> mapFramesAnimaciones;
	
	map<string, SDL_Texture*> mapTexturasSDL;
	
	map<string, Mix_Music*> mMusic;
	map<string, Mix_Chunk*> mSFX;
	SDL_Renderer* renderer;

	TextureManager();
	~TextureManager();

	static TextureManager* instancia;
public:
	static TextureManager* getInstancia();

	//Metodos accesores
	SDL_Renderer* getRenderer() { return renderer; }
	void setRenderer(SDL_Renderer* _renderer) { renderer = _renderer; }

	void inicializarRecursos();
	void inicializarRecursosSDL(SDL_Renderer* _renderer);

	Texture* getTextura(string _key) { return mapTexturas[_key]; }
	AnimationFrames* getFramesAnimacion(string _key) { return mapFramesAnimaciones[_key]; }

	Mix_Music* getMusic(string filename);
	Mix_Chunk* getSFX(string filename);

	void addTextura(string _key, Texture* _textura);
	void addFramesAnimacion(string _key, AnimationFrames* _framesAnimacion);
	void free();

	//Metodos propuesta nueva
	bool load(string fileName, string _key, SDL_Renderer* _renderer);

	void clearTextureMap();
	void clearFromTextureMap(string _key);

	void draw(string _key, int x, int y, int width, int height, SDL_Renderer* _renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(string _key, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer, double angle, int alpha, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawTile(string _key, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer);
};

