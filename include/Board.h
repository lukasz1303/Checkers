#pragma once
#include "../include/Scaleable.h"

using namespace sf;

//!  Klasa Board. 
/*!
  Klasa reprezentujaca plansze do gry
*/

class Board : public Scaleable {
	
public:
	//! Konstruktor Planszy.
	/*!
	  Konstruktor ktory tworzy plansze do gry
	*/
	Board();

	//! Konstruktor Planszy z inicjacja textury.
	/*!
	  Konstruktor ktory tworzy plansze do gry i przypisuje jej dana texture t
	  \param t textura planszy
	*/
	Board(Texture t);

	//! Wirtualna metoda do obliczania skali planszy.
	/*!
	  \brief Oblicza skale planszy wzgledem szerokosci okna screenWidth i wysokoœci okna screenHeight
	  \param screenWidth szerokosc okna.
	  \param screenHeight wysokosc okna.
	*/
	virtual Vector2f calculateScale(float screenWidth,float screenHeight);
	
	//!  Metoda obliczania skali planszy.
	/*!
	  \brief Oblicza pozycje planszy na podstawie szerokosci okna screenWidth i wysokosci okna screenHeight
	  \param screenWidth szerokosc okna.
	  \param screenHeight wysokosc okna.
	*/
	Vector2f calculatePosition(float screenWidth, float screenHeight);
};