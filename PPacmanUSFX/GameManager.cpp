#include "GameManager.h"


using namespace std;

GameManager* GameManager::instancia = nullptr;

GameManager* GameManager::crearInstancia() {
	if (instancia == nullptr) {
		instancia = new GameManager();
	}

	return instancia;
}

GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;

	juego_en_ejecucion = true;
	//tipoFabrica = new FactoryPacmanClasico;
	//tipoFabrica = new FactoryPacmanGalactico;
}

int GameManager::onExecute() {
    if (onInit() == false) {
        return -1;
    }
		
	srand(time(nullptr));

	TileGraph tileGraphGM(20, 19, 800, 600);
	textureManager = TextureManager::getInstancia();
	textureManager->setRenderer(gRenderer);
	textureManager->inicializarRecursosSDL(gRenderer);
	//TextureManager::getInstancia()->inicializarRecursosSDL(gRenderer);
	GameActor::tileGraph = &tileGraphGM;
	//generadorNivelJuego = new MapGenerator(&tileGraphGM, textureManager, SCREEN_WIDTH, SCREEN_HEIGHT, tipoFabrica);
	generadorNivelJuego = new MapGenerator(&tileGraphGM, /*textureManager,*/ SCREEN_WIDTH, SCREEN_HEIGHT);
	generadorNivelJuego->load("Resources/mapa.txt");
	/*generadorNivelJuego->populate(actoresJuego);*/

    SDL_Event Event;

    while (juego_en_ejecucion) {

		for (int i = 0; i < generadorNivelJuego->vectorObjetosJuego.size(); i++) {
			if (generadorNivelJuego->vectorObjetosJuego[i]->getEliminar()) {
				generadorNivelJuego->vectorObjetosJuego.erase(remove(generadorNivelJuego->vectorObjetosJuego.begin(), generadorNivelJuego->vectorObjetosJuego.end(), generadorNivelJuego->vectorObjetosJuego[i]), generadorNivelJuego->vectorObjetosJuego.end());
			}
		}

		generadorNivelJuego->Score();

        while (SDL_PollEvent(&Event)) {
            onEvent(&Event);
			for (int i = 0; i < generadorNivelJuego->vectorObjetosJuego.size(); i++) {
				generadorNivelJuego->vectorObjetosJuego[i]->handleEvent(&Event);
			}
        }

		auto idob = generadorNivelJuego->vectorObjetosJuego[3]->getIdObjeto();

		////Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);

		//Update screen
		
        onLoop();
        onRender();
		SDL_RenderPresent(gRenderer);
    }

    onCleanup();

    return 0;
}

bool GameManager::onInit() { 
    //Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Pacman USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == nullptr)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == nullptr)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				if (TTF_Init()== -1) {
					cout << "Error inicializacion SDL_ttf" << TTF_GetError() << endl;
					success = false;
				}

				////Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}


			Texture::renderer = gRenderer;
		}
	}

	return success;
};

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};

void GameManager::onLoop() {};

void GameManager::onRender() {
	for (int i = 0; i < generadorNivelJuego->vectorObjetosJuego.size(); i++) {
		generadorNivelJuego->vectorObjetosJuego[i]->update();
		generadorNivelJuego->vectorObjetosJuego[i]->render();
	}
};

void GameManager::onCleanup() {
	
	SDL_Quit();
};