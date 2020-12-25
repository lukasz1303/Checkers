#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "../include/Pawn.h"
#include "../include/Board.h"
#include "../include/DrawableArray.h"
#include <string>
#include <fstream>
#include <ostream>
#include <iosfwd>
#include "../include/TextureException.h"
using namespace sf;
//!  Klasa Mainmenu. 
/*!
  Klasa tworzaca menu glowne w ktorym wybieramy porzadane opcje, jak miedzy innymi wczytanie rozgrywki
*/

class Mainmenu
{
private:
	//! zmienna okreslajaca obecnie wybrana przez uzytkownika opcje
	int selectedItemIndex;
	//!zmienna okreslajaca szerokosc okna
	int width1 = 1100;
	//!zmienna okreslajaca wysokosc okna
	int height1 = 800;
	//! Czcionka uzywana przy wyswietlaniu tekstu na ekranie
	Font font;
	//! 4 Opcje zawarte w glownym menu
	Text text[4];
	//! zasady zawarte w opcji Rules
	Text zasadytxt[6];
	//!imiona graczy
	Text nick[2];
	//!opis wskazujacy do ktorego gracza nalezy dane imie
	Text player[2];
	//! tekstura tla
	Texture backgroundtexture;
	//!sprite z tekstury tla
	Sprite background;
	//!pozycja myszy na ekranie
	Vector2i mouse_position;
	//! tekst wpisany przez uzytkownika podczas podawania imion graczy
	string playerInput;
	//!zmienna boolowska mowiaca czy wprowadzono juz imiona
	bool wprowadzononicki = false;
	//!zmienna boolowska pokazujaca czy gracz pierwszy ma juz imie
	bool playerHasName1 = false;
	//!zmienna boolowska pokazujaca czy gracz drugi ma juz imie
	bool playerHasName2 = false;
public:
	//! Konstruktor Menu.
	/*!
	  Konstruktor ktory tworzy menu zalezne od szerokosci \width i wyskosci \height okna, tworzac takze opcje ktore beda w nim uzywane.
	  \param width szerokosc okna
	  \param height wysokosc okna
	*/
	Mainmenu(float width, float height);
	~Mainmenu();
	
	//! Metoda wyswietlajaca Menu
	/*!
	  Metoda ktora wyswietla opcje i tlo w menu
	*/
	void draw(RenderWindow &window);

	//! Metoda podajaca wybrana opcje
	/*!
	  Metoda ktora zwraca numer opcji wybranej przez uzytkownika
	*/
	int wybranaopcja() { return selectedItemIndex; };

	//! Metoda sledzaca pozycje mysze
	/*!
	  Metoda ktora podaje pozycje myszy oraz zaleznie od niej zmienia elementy menu
	*/
	void ustawmyszke(RenderWindow& window);

	//! Metoda sluzaca do pokazywania okna w ktorym wczytywane sa imiona graczy
	/*!
	  \brief wyswietla okno ktore ulatwia uzytkownikowi wprowadzenie imion dla obu zawodnikow uzywajac do tego stworzonego okna
	  \param window okno w ktorym wyswietlone zostanie wpisywanie imion 
	*/
	void oknonickname(RenderWindow& window);
	//! Metoda sluzaca do wczytania imion obu graczy
	/*!
	  \brief metoda zajmujaca sie danymi wpisywanymi przez uzytkownika, oraz okreslajaca czy imiona graczy zostaly wpisane czy nie
	  \param event pomaga okreslic czy oraz jaki tekst podaje uzytkownik
	*/
	void loadPlayersNames(Event event);
	//! Metoda sluzaca do zapisania imion obu graczy
	/*!
	  \brief metoda zajmujaca sie zapisywaniemi imion graczy do pliku po to by mogly one byc uzyte przy wczytywaniu rozgrywki
	*/
	void savenicknames();
	//! Metoda sluzaca do pokazywania okna w ktorym podane sa zasady
	/*!
	  \brief wyswietla okno ktore zawiera zasady potrzebne do gry w warcaby
	  \param window okno w ktorym wyswietlone zostana zasady gry
	*/
	void zasady(RenderWindow& window);
};