#pragma once
#include <cmath>
#include <set> 
#include <iostream>
#include "../include/Scaleable.h"

using namespace sf;
using namespace std;

//!  Klasa Pawn. 
/*!
  Klasa reprezentujaca pionek do gry
*/

class Pawn : public Scaleable
{
	/* zmienna ktora wskazuje, czy pionek jest damka*/ /**/
	bool king = false;
	/*zmienna ktora wskazuje, czy pionek jest czarny*/
	bool black = false;
	/*zmienna ktora wskazuje, czy pionek moze bic*/
	bool canCapture = false;
	/*zmienna ktora wskazuje, czy pionek zostal zbity*/
	bool captured = false;
	/*zmienna ktora wskazuje, czy pionek pionek byl damka na koniec tury*/
	bool kingLastTurn = false;

	int /*zmienna przechowujaca wspolrzedne x pionka*/ coordinateX, /*zmienna przechowujaca wspolrzedne y pionka*/ coordinateY;

	/*set przechowujacy pary wspolrzednych pionka ktore pionek moze wykonac gdy ma bicie*/
	set<pair<int, int>> moves;

	/*textura damki pionka*/
	Texture kingTexture;

public:

	//! Konstruktor Pionka.
	/*!
	  Konstruktor ktory tworzy pionka do gry
	*/
	Pawn();

	//! Konstruktor Pionka.
	/*!
	  Konstruktor ktory tworzy pionka do gry z inicjacj¹ tekstury t pionka
	\param t textura pionka
	*/
	Pawn(Texture t);

	//! Metoda sluzaca do zmiany wpsolrzednych pionka
	/*!
	  \brief Metoda sluzaca do zmiany wpsolrzednych x i y pionka
	  \param x wspolrzedna x
	  \param y wspolrzedna y
	*/
	void setCoordinates(int x, int y);

	//! Metoda sluzaca do ustawienia zminnej kingLastTurn
	/*!
	  \brief Metoda sluzaca do ustawienia zminnej kingLastTurn na stan k
	  \param k wartosc jaka ma byc zapisana w zmiennej
	*/
	void setKingLastTurn(bool k);

	//! Metoda sluzaca do ustawienia zminnej black
	/*!
	  \brief Metoda sluzaca do ustawienia zminnej black na true
	*/
	void setBlack();

	//! Metoda sluzaca do ustawienia zminnej king
	/*!
	  \brief Metoda sluzaca do ustawienia zminnej king na true
	*/
	void setKing();
	//! Metoda sluzaca do ustawienia zminnej capture
	/*!
	  \brief Metoda sluzaca do ustawienia zminnej capture na true
	*/
	void setCaptured();
	//! Metoda sluzaca do sprawdzenia czy pionek ma bicie
	/*!
	  \brief Metoda sluzaca do sprawdzenia czy pionek ma bicie na podstawie obecnego ustawienia pionkow w tablicy tab
	  /param tab tablica reprezentujaca obecne ustawienie pionkow
	*/
	void hasCapture(int tab[8][8]);
	//! Metoda sluzaca do ustawienia textury damki
	/*!
	  \brief Metoda sluzaca do ustawienia textury damki na texture t
	  /param t textura damki
	*/
	void setKingTexture(Texture t);
	//! Metoda sluzaca do pobrania wartosci zmiennej canCapture
	/*!
	  \brief Metoda sluzaca do pobrania wartosci zmiennej canCapture
	*/
	bool getCanCapture();
	//! Metoda sluzaca do pobrania wartosci zmiennej kingLastTurn
	/*!
	  \brief Metoda sluzaca do pobrania wartosci zmiennej kingLastTurn
	*/
	bool getKingLastTurn();
	//! Metoda sluzaca do sprawdzenia czy pionek jest czarny
	/*!
	  \brief Metoda sluzaca do sprawdzenia czy pionek jest czarny
	*/
	bool isBlack();
	//! Metoda sluzaca do sprawdzenia czy pionek jest damka
	/*!
	  \brief Metoda sluzaca do sprawdzenia czy pionek jest damka
	*/
	bool isKing();
	//! Metoda sluzaca do sprawdzenia czy pionek jest zbity
	/*!
	  \brief Metoda sluzaca do sprawdzenia czy pionek jest zbity
	*/
	bool isCaptured();
	//! Metoda sluzaca do sprawdzenia czy pionek moze sie ruszyc
	/*!
	  \brief Metoda sluzaca do sprawdzenia czy pionek moze sie ruszyc na podstawie danych w tablicy tab
	  \param tab tablica z obecnym ulozeniem pionkow
	*/
	bool canMove(int tab[8][8]);

	//! Metoda sluzaca do zaladownia textury damki
	/*!
	  \brief Metoda sluzaca do zaladownia textury damki
	*/
	void loadKingTexture();

	//! Metoda sluzaca do pobrania wspolrzednych pionka
	/*!
	  \brief Metoda sluzaca do pobrania wspolrzednych x i y pionka
	*/
	Vector2u getCoordinates();

	//! Metoda sluzaca do obliczenia skali pionka
	/*!
	  \brief Metoda sluzaca do obliczenia skali pionka na podstawie szerokosci planszy boardWidth i wysokosci planszy boardHeight
	  \param boardWidth szerokosc planszy
	  \param boardHeight wysokosc planszy
	*/
	virtual Vector2f calculateScale(float boardWidth, float boardHeight);

	//! Metoda sluzaca do obliczenia pozycji pionka
	/*!
	  \brief Metoda sluzaca do obliczenia pozycji pionka po wykonaniu nim ruchu, sprwadzajac przy tym czy dane pole jest dowzowlone dla tego pionka
	  \param boardPosition pozycja planszy
	  \param boardSize rozmair planszy
	  \param newPosition pozycja pionka po puszczniu przycisku myszy
	  \param tab tablica z aktualnym rozlozeniem pionkow
	*/
	Vector2f calculatePosition(Vector2f boardPosition, Vector2f boardSize, Vector2f newPosition, int tab[8][8]);
};