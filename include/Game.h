#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Pawn.h"
#include "../include/Board.h"
#include "../include/DrawableArray.h"
#include <string>
#include <fstream>
#include <windows.h>
#include "../include/TextureException.h"
#include "../include/LoadException.h"

#define WIN32_LEAN_AND_MEAN
//!  Klasa Game. 
/*!
  Klasa zajmujaca sie przebiegiem rozgrywki
*/
class Game
{
protected:
	Texture /*!tekstura bialego piona*/whitePawnTexture,/*! tekstura czarnego piona*/ blackPawnTexture, /*!tekstura bialego krola */whiteKingTexture,/*!tekstura czarnego krola */ blackKingTexture,/*!tekstura tla */ woodBackgroundTexture,/*!tekstura planszy */ boardTexture;
	//! czcionka uzywana do tekstu opisujacego imiona graczy, ture, czy tez przycisk do menu
	Font font;
	/*! tekst okreslajacy zwyciezce*/
	Text winner, /*! tekst okreslajacy imie pierwszego gracza*/ player1, /*! tekst okreslajacy imie drugiego gracza*/player2,/*! tekst okreslajacy ilosc bialych figur*/ amountOfWhiteText, /*! tekst okreslajacy ilosc czarnych figur*/amountOfBlackText,/*! tekst nad pionem pokazujacym ture*/ turnText,/*! tekst reprezentujacy powrot do menu*/powrot;
	//! obiekt klasy board
	Board Checkerboard;
	//! wektor pozwalajacy okreslic pozycje myszy
	Vector2i mouse_position;

	Sprite /*!sprite tla*/woodBackground,/*!sprite planszy*/ boardSprite,/*!sprite bialego piona*/ colorPawnPlayer1, /*!sprite czarnego piona*/colorPawnPlayer2, /*!sprite piona pokazujacego ture*/turnSprite;
	//! szerokosc okna
	int screen_width = 1100;
	//! wysokosc okna
	int screen_height = 800;
	//! zmienna opisujaca ilosc czarnych figur
	int amountOfBlack = 12;
	//! zmienna opisujaca ilosc bialych figur
	int amountOfWhite = 12;
	//! zmienna boolowska pokazujaca czy bialy moze bic
	bool whiteCanCapture = false;
	//!zmienna boolowska pokazujaca czy czarny moze bic
	bool blackCanCapture = false;
	//!zmienna boolowska pokazujaca czy bialy moze sie ruszac
	bool whiteCanMove = true;
	//! zmienna boolowska pokazujaca czy czarny moze sie ruszac
	bool blackCanMove = true;
	//! zmienna boolowska pokazujaca czy jest tura czarnego - True, czy tez bialego- False
	bool turn = false; // turn Black - TRUE, White - FALSE

	bool /*! zmienna okreslajaca czy gracz 1 ma imie*/playerHasName1 = false, /*! zmienna okreslajaca czy gracz 2 ma imie*/playerHasName2 = false;
	//! index pionka ktory ostatnio wykonal bicie
	int indexPawn = -1;
	//! zmienna opisujaca czy pionek jest w ruchu
	bool isMove = false;
	//! zmienna mowiaca czy jest koniec gry
	bool theEnd = false;
	float /*! roznica polozen myszy i pionka x*/ dx = 0, /*! roznica polozen myszy i pionka y*/ dy = 0;
	//! index aktualnie wybranego pionka
	int k = 0;
	//! liczba bialych pionkw ktore moga sie ruszyc
	int amountWhiteCanMove = 1;
	//! liczba czarnych pionkw ktore moga sie ruszyc
	int amountBlackCanMove = 1;
	//! centrum x sekcji menu podczas gry
	int centerOfMenuSectionX = 0;
	//! centrum y sekcji menu podczas gry
	int centerOfMenuSectionY = 0;

	//! tablica 24 obiektow pawn
	Pawn* pawns[24] = {};
	//! tablica liter planszy
	DrawableArray<Text, 8> letters;
	//! tablica cyfr planszy
	DrawableArray<Text, 8> numbers;
	//! tablica spriteow pionkow
	DrawableArray<Sprite, 24> pawnsSprites;

	//! tablica reprezentujaca polozenie pionkow na planszy, gdzie 0 - puste pole, 1 - bialy pionek, 2 - biala damka, -1 - czarny pionek, -2 czarna damka
	int tab[8][8] = { {0,1,0,1,0,1,0,1},
					{1,0,1,0,1,0,1,0},
					{0,1,0,1,0,1,0,1},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{-1,0,-1,0,-1,0,-1,0},
					{0,-1,0,-1,0,-1,0,-1},
					{-1,0,-1,0,-1,0,-1,0} };
public:
	

	//!  Metoda do zaladowania wszystich pionkow
	/*!
	  \brief Metoda laduje wszytkie elementy pionkow oraz ustawaia ich pozycje
	*/
	void loadPawns();

	//!  Metoda wczytujaca tekstury i czczionki
	/*!
	  \brief Metoda sluzaca do wczytania wszystkich potrzebnych tekstur i czcionek do uruchomienia gry
	*/
	void loadTexturesAndFont();

	//!  Metoda wczytujaca litery i cyfry planszy
	/*!
	  \brief Metoda sluzaca do wczytania liter i cyfr indeksujacych pola planszy
	*/
	void loadLettersAndNumbers();

	//!  Metoda wczytujaca wszystkie dane graczy
	/*!
	  \brief Metoda sluzaca do wczytania wszytkich danych graczy oraz odpowiednie rozmieszczenie ich w menu gry
	*/
	void loadPlayers();

	//!  Metoda zapisujaca gre
	/*!
	  \brief Metoda sluzaca do zapisywania aktualnego stanu gry
	*/
	void savegame();

	//!  Metoda wczytujaca plansze
	/*!
	  \brief Metoda sluzaca do wczytania planszy do gry
	*/
	void loadBoard();

	//!  Metoda wczytujaca tlo
	/*!
	  \brief Metoda sluzaca do wczytania tla gry
	*/
	void loadBackground();

	//!  Metoda pmocnicza do obslugi ruchu pionka
	/*!
	  \brief Metoda pomocnicza do obslugi ruchu pionka o indexie i
	  \param i index pionka ktury ma zostac poruszony
	*/
	void move(int i);

	//!  Metoda sprawdzajaca bicie
	/*!
	  \brief Metoda sprawdza czy dowolny pionek o kolorze ktorego jest w chwili obecnej tura ma bicie
	*/
	void checkCaptures();

	//!  Metoda sprawdzajaca ruchy
	/*!
	  \brief Metoda sprawdza czy dowolny pionek o kolorze ktorego jest w chwili obecnej moze sie poruszyc
	*/
	void checkMoves();

	//!  Metoda pomocnicza do wyswietlania obiektow
	/*!
	  \brief Metoda pomocnicza sluzaca do wyswietlania wsztkich elemntow do rysowania w oknie window
	  \param window
	*/
	void drawSprites(RenderWindow& window);

	//!  Metoda wczytujaca imiona graczy
	/*!
	  \brief Metoda wczytuje z pliku imiona graczy
	*/
	void loadPlayersNames();

	//! Konstruktor Gry.
	/*!
	  Konstruktor ktory wczytuje/tworzy wszytskie elementy gry.
	*/
	Game();

	//! Destruktor Gry.
	/*!
	  Destruktor gry.
	*/
	~Game();
		
	//! Metoda odpowiedzialna za przebieg gry.
	/*!
	  \brief Metoda w ktorej odbywa sie cala rozgrywka gry oraz sa wyswietlane wszytkie obiekty do rysowania w oknie window
	  \param window
	*/
	void run(RenderWindow& window);	
};