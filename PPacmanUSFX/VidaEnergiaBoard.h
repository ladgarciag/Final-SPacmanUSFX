#include "GUI/Panel.h"
#include "Texture.h"
#include "GameActor.h"

class VidaEnergiaBoard
	:public Panel
{
private:

	static VidaEnergiaBoard* instancia;

	VidaEnergiaBoard(SDL_Renderer* _renderer, int _posicionX, int _posicionY, int _ancho, int _alto, string _nombre, string _texto);
	~VidaEnergiaBoard();
public:

	static VidaEnergiaBoard* getInstancia(SDL_Renderer* _renderer, int _posicionX, int _posicionY, int _ancho, int _alto, string _nombre, string _texto);





};