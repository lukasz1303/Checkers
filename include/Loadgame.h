#pragma once
#include "../include/Game.h"
#include "LoadException.h"
//!  Klasa Loadgame. 
/*!
  Klasa sluzaca do wczytywania wczesniej zapisanego stanu rozgrywki
*/
class Loadgame :public Game {
private:
	//!zmienna okreslajaca ile figur bedzie uzywane po wczytaniu gry
	int ilosc = 0;

public:
	//! Metoda wczytujaca dane z pliku
	/*! 
	\brief Otwiera plik z danymi dotyczacymi stanu gry oraz przypisuje odpowiednie wartosci do zmiennych wykorzystywanych do poprawnego rozpoczecia rozgrywki.
	*/
	void load();
	//! Konstruktor wczytywanej gry.
	/*!
	  Konstruktor który pozwala nam kontynuowaæ rozgrywke
	*/
	Loadgame();
	//! Destruktor wczytywanej gry.
	/*!
	  Destruktor wczytywanej gry.
	*/
	~Loadgame();
};