#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

//!  Klasa Scaleable. 
/*!
  Klasa reprezentuj¹ca obiekt gry tj. pionek i plansza
*/

class Scaleable
{
protected:
	/* textura danego obiektu*/
	Texture texture;
	/* rozmiar danego obiektu*/
	Vector2f size;
	/* skala danego obiektu*/
	Vector2f scale;
	/* pozycja danego obiektu*/
	Vector2f position;
	/* rozmiar tekstury danego obiektu*/
	Vector2u textureSize;
	/* sprite danego obiektu*/
	Sprite sprite;
public:
	//!  Metoda sluzuca do pobrania textury
	/*!
	  \brief Metoda sluzuca do pobrania textury obiektu
	*/
	Texture getTexture();
	//!  Metoda sluzuca do pobrania rozmiaru
	/*!
	  \brief Metoda sluzuca do pobrania rozmaiaru obiektu
	*/
	Vector2f getSize();
	//!  Metoda sluzuca do pobrania skali
	/*!
	  \brief Metoda sluzuca do pobrania skali obiektu
	*/
	Vector2f getScale();
	//!  Metoda sluzuca do pobrania pozycji
	/*!
	  \brief Metoda sluzuca do pobrania pozycji obiektu
	*/
	Vector2f getPosition();

	//!  Metoda sluzuca do ustawnienia textury
	/*!
	  \brief Metoda sluzuca do ustawienia textury t  dla obiektu 
	  \param t textura obiektu
	*/
	void setTexture(Texture t);
	//!  Metoda sluzuca do rozmiaru obiektu
	/*!
	  \brief Metoda sluzuca do ustawienia rozmiaru s  dla obiektu
	  \param s rozmiar obiektu
	*/
	void setSize(Vector2f s);
	//!  Metoda sluzuca do ustawnienia sklai
	/*!
	  \brief Metoda sluzuca do ustawienia skali s  dla obiektu
	  \param s skala obiektu
	*/
	void setScale(Vector2f);
	//!  Metoda sluzuca do ustawnienia pozycji
	/*!
	  \brief Metoda sluzuca do ustawienia pozycji p  dla obiektu
	  \param p textura obiektu
	*/
	void setPosition(Vector2f p);

	//!  Metoda sluzuca do stworzenia sprite'a obiektu
	/*!
	  \brief Metoda sluzuca do stworzenia sprite'a obiektu
	*/
	Sprite createSprite();


	//!  Czysta metoda wirtualna sluzuca do oblicznia skali obiektu
	/*!
	  \brief Czysta metoda wirtualna sluzuca do oblicznia skali obiektu na podsatwie szerokosci s i wysokosci h
	  \param s szerokosc
	  \param h wysokosc
	*/
	virtual Vector2f calculateScale(float s, float h) = 0;
};