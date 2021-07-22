#include "ScoreBoard.h"

using namespace std;

ScoreBoard* ScoreBoard::instancia = nullptr;

ScoreBoard* ScoreBoard::getInstancia(SDL_Renderer* _renderer, int _posicionX, int _posicionY, int _ancho, int _alto, string _nombre, string _texto) {
	if (instancia == nullptr) {
		instancia = new ScoreBoard( _renderer, _posicionX, _posicionY, _ancho, _alto, _nombre, _texto);
	}

	return instancia;
}

ScoreBoard::ScoreBoard(SDL_Renderer* _renderer, int _posicionX, int _posicionY, int _ancho, int _alto, string _nombre, string _texto):Panel(_renderer, _posicionX, _posicionY, _ancho, _alto, _nombre, _texto) {
    renderer = _renderer;
    panel = new SDL_Rect({ _posicionX, _posicionY, _ancho, _alto });
    nombre = _nombre;

    panelSDLColor = new SDL_Color({ 125, 25, 255 });
    setPanelColorRGBA(20, 255, 255, 255);
    setPanelColorRGBAEnfocado((int)(panelColorR * 0.5), (int)(panelColorG * 0.5), (int)(panelColorB * 0.5), (int)(panelColorA * 0.5));

    etiqueta = new SDL_Rect({ _posicionX + 1, _posicionY + 1, _ancho, _alto });
    etiquetaTamanoFuente = 15;

    etiquetaTexto = _texto;
    etiquetaFuente = TTF_OpenFont("Resources/dogicapixel.ttf", etiquetaTamanoFuente);
    etiquetaSDLColor = new SDL_Color({ 0, 70, 210 });
    setEtiquetaColorRGBA(20, 120, 220, 250);
    revisarActividadMouse = true;
    clickedOn = true;
}

