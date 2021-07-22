#include "TextureManager.h"

TextureManager* TextureManager::instancia = nullptr;

void TextureManager::inicializarRecursosSDL(SDL_Renderer* _renderer)
{
	load(pathPacmanClasico, "pacman_clasico", _renderer);
	load(pathFantasmaClasico1, "fantasma_clasico1", _renderer);

}

void TextureManager::inicializarRecursos()
{
	// Texturas
	pacmanClasicoTexture = new Texture();
	pacmanClasicoTexture->loadFromImage(pathPacmanClasico);
	addTextura("pacman_clasico", pacmanClasicoTexture);
	
	fantasmaClasico1Texture = new Texture();
	fantasmaClasico1Texture->loadFromImage(pathFantasmaClasico1);
	addTextura("fantasma_clasico1", fantasmaClasico1Texture);
	fantasmaClasico2Texture = new Texture();
	fantasmaClasico2Texture->loadFromImage(pathFantasmaClasico2);
	addTextura("fantasma_clasico2", fantasmaClasico2Texture);
	fantasmaClasico3Texture = new Texture();
	fantasmaClasico3Texture->loadFromImage(pathFantasmaClasico3);
	addTextura("fantasma_clasico3", fantasmaClasico3Texture);
	fantasmaClasico4Texture = new Texture();
	fantasmaClasico4Texture->loadFromImage(pathFantasmaClasico4);
	addTextura("fantasma_clasico4", fantasmaClasico4Texture);

	frutaClasicoTexture = new Texture();
	frutaClasicoTexture->loadFromImage(pathFrutaClasico);
	addTextura("fruta_clasico", frutaClasicoTexture);

	monedaClasicoTexture = new Texture();
	monedaClasicoTexture->loadFromImage(pathMonedaClasico);
	addTextura("moneda_clasico", monedaClasicoTexture);

	superMonedaClasicoTexture = new Texture();
	superMonedaClasicoTexture->loadFromImage(pathSuperMonedaClasico);
	addTextura("supermoneda_clasico", superMonedaClasicoTexture);

	paredClasicoTexture = new Texture();
	paredClasicoTexture->loadFromImage(pathParedClasico);
	addTextura("pared_clasico", paredClasicoTexture);

	paredClasicoAdapterTexture = new Texture();
	paredClasicoAdapterTexture->loadFromImage(pathParedClasicoAdapter);
	addTextura("pared_clasico_adapter", paredClasicoAdapterTexture);

	pacmanGalacticoTexture = new Texture();
	pacmanGalacticoTexture->loadFromImage(pathPacmanGalactico);
	addTextura("pacman_galactico", pacmanGalacticoTexture);

	fantasmaGalactico1Texture = new Texture();
	fantasmaGalactico1Texture->loadFromImage(pathFantasmaGalactico1);
	addTextura("fantasma_galactico1", fantasmaGalactico1Texture);
	fantasmaGalactico2Texture = new Texture();
	fantasmaGalactico2Texture->loadFromImage(pathFantasmaGalactico2);
	addTextura("fantasma_galactico2", fantasmaGalactico2Texture);
	fantasmaGalactico3Texture = new Texture();
	fantasmaGalactico3Texture->loadFromImage(pathFantasmaGalactico3);
	addTextura("fantasma_galactico3", fantasmaGalactico3Texture);
	fantasmaGalactico4Texture = new Texture();
	fantasmaGalactico4Texture->loadFromImage(pathFantasmaGalactico4);
	addTextura("fantasma_galactico4", fantasmaGalactico4Texture);

	frutaGalacticoTexture = new Texture();
	frutaGalacticoTexture->loadFromImage(pathFrutaGalactico);
	addTextura("fruta_galactico", frutaGalacticoTexture);

	monedaGalacticoTexture = new Texture();
	monedaGalacticoTexture->loadFromImage(pathMonedaGalactico);
	addTextura("moneda_galactico", monedaGalacticoTexture);

	superMonedaGalacticoTexture = new Texture();
	superMonedaGalacticoTexture->loadFromImage(pathSuperMonedaGalactico);
	addTextura("supermoneda_galactico", superMonedaGalacticoTexture);

	paredGalacticoTexture = new Texture();
	paredGalacticoTexture->loadFromImage(pathParedGalactico);
	addTextura("pared_galactico", paredGalacticoTexture);


			
	// Frames de animacion
	framesAnimacionPacmanClasico = new AnimationFrames();
	framesAnimacionPacmanClasico->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	framesAnimacionPacmanClasico->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));
	addFramesAnimacion("pacman_clasico", framesAnimacionPacmanClasico);

	framesAnimacionFantasmaClasico = new AnimationFrames();
	framesAnimacionFantasmaClasico->addCuadroAnimacion("izquierda", new SDL_Rect({ 50, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("izquierda", new SDL_Rect({ 75, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	framesAnimacionFantasmaClasico->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));
	addFramesAnimacion("fantasma_clasico", framesAnimacionFantasmaClasico);
}

TextureManager::TextureManager()
{
	inicializarRecursos();
}

TextureManager::~TextureManager() {
	free();
}

TextureManager* TextureManager::getInstancia()
{
	if (instancia == nullptr) {
		instancia = new TextureManager();
		return instancia;
	}

	return instancia;
}

void TextureManager::addTextura(string _key, Texture* _textura)
{
	mapTexturas[_key] = _textura;
}

void TextureManager::addFramesAnimacion(string _key, AnimationFrames* _framesAnimacion)
{
	mapFramesAnimaciones[_key] = _framesAnimacion;
}



void TextureManager::free()
{
	//for (auto elementoMapTexturas : mapTexturas) {
	for (pair<string, Texture*> elementoMapTexturas : mapTexturas) {
		//delete elementoMapTexturas.second;
		mapTexturas.erase(elementoMapTexturas.first);
	}
}


bool TextureManager::load(string fileName, string _key, SDL_Renderer* _renderer)
{

	SDL_Surface* tempsurface = IMG_Load(fileName.c_str());
	//Checks
	if (tempsurface == 0)
	{
		cout << IMG_GetError();
		return false;
	}
	//Create a texture from temporary surface
	SDL_Texture* sdltexture = SDL_CreateTextureFromSurface(_renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	if (sdltexture != 0)
	{
		mapTexturasSDL[_key] = sdltexture;
		return true;
	}

	return false;
}

void TextureManager::draw(string _key, int x, int y,
	int width, int height, SDL_Renderer* _renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(_renderer, mapTexturasSDL[_key], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string _key, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer, double angle, int alpha, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_SetTextureAlphaMod(mapTexturasSDL[_key], alpha);
	SDL_RenderCopyEx(_renderer, mapTexturasSDL[_key], &srcRect, &destRect, angle, 0, flip);
}

void TextureManager::drawTile(string _key, int margin, int spacing, int x, int y,
	int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(_renderer, mapTexturasSDL[_key], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}


void TextureManager::clearTextureMap()
{
	mapTexturasSDL.clear();
}

void TextureManager::clearFromTextureMap(string _key)
{
	mapTexturasSDL.erase(_key);
}

Mix_Music* TextureManager::getMusic(string filename) 
{
	string fullPath = SDL_GetBasePath();
	fullPath.append("Resources/" + filename);


	if (mMusic[fullPath] == nullptr) {
		mMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
		if (mMusic[fullPath] == NULL )
			printf("Music Loading error: file-%s", filename.c_str(), Mix_GetError());
	}
	return mMusic[fullPath]; 
	 
}
Mix_Chunk* TextureManager::getSFX(string filename)
{
	string fullPath = SDL_GetBasePath();
	fullPath.append("Resources/" + filename);


	if (mSFX[fullPath] == nullptr) {
		mSFX[fullPath] = Mix_LoadWAV(fullPath.c_str());
		if (mSFX[fullPath] ==  NULL )
			printf("SFX Loading error: file-%s", filename.c_str(), Mix_GetError());
	}
	return mSFX[fullPath];

}
