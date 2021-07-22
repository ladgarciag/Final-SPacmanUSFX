#include "Game.h"
#include "PlayState.h"

Game* Game::instance = 0;

Game::Game() : mainwindow(0), maindrawer(0),
	boolrunning(false),	statemachine(0)
{
	// add some level files to an array
	//levelfiles.push_back("Content/map1.tmx");
	//m_levelFiles.push_back("assets/map2.tmx");
	// start at this level
	//It can be level 1 or level 2 for now
	//m_currentLevel = 1;
}

Game::~Game()
{
	// we must clean up 
	maindrawer = 0;
	mainwindow = 0;
}

bool Game::init(const char * title, int xpos, int ypos, bool fullscreen)
{
	int flags = 0;
	//store the game width and height
	gamewidth = GeneralParameters::Instance()->Getxaxmax();
	gameheight = GeneralParameters::Instance()->Getyaxmax();
	//fullscrren is bool
	if (fullscreen)
	{
		//get the enumration value for fullscreen
		flags = SDL_WINDOW_FULLSCREEN;
	}
	//attempt to initialse SDL
	//could just init audio etc.
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL inti success";
		//init the window
		mainwindow = SDL_CreateWindow
			(title, xpos, ypos, gamewidth, gameheight, flags);
		if (mainwindow != 0)//check window init success
		{
			std::cout << "window vreation success\n";
			maindrawer = SDL_CreateRenderer(mainwindow, -1, SDL_RENDERER_ACCELERATED);
			if (maindrawer != 0)
			{
				std::cout << "main drawer success/n";
				SDL_SetRenderDrawColor(maindrawer, 129, 191, 212, 5);
			}
			else
			{
				std::cout << "drawer init failed\n";
				return false;//draw init failed
			}
		}
		else
		{
			std::cout << "window init failed\n";
			return false;
		}
	}
	else
	{
		std::cout << "window init failed\n";
		return false;
	}

	//load some sound effect here
	//register some GameObjsect here
	// start the menu state
	statemachine = new StateMachine();
	/*cange ste tells statemachine a new state is coming
	statemachine will call onenter for that state*/
	statemachine->changeState(new PlayState());

	boolrunning = true;
	return true;
}

void Game::draw()
{
	SDL_RenderClear(maindrawer);
	statemachine->draw();
	SDL_RenderPresent(maindrawer);
}

void Game::update()
{
	statemachine->update();
}
//Handle any incoming events
void Game::handleevents()
{
	InputHandler::Instance()->update();
}
/*Clean the:
-InputManager
-StateMachine
-InputManger
*/
void Game::clean()
{
	std::cout << "cleaning game\n";
	//TheInputHandler::Instance()->clean();
	statemachine->clean();
	statemachine = 0;
	//delete m_pStateMachine;
	TextureManager::Instance()->clearTextureMap();
	SDL_DestroyWindow(mainwindow);
	SDL_DestroyRenderer(maindrawer);
	SDL_Quit();
}
