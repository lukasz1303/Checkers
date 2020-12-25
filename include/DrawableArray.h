#pragma once
#include <SFML/Graphics.hpp>

//!  Klasa DrawableArray. 
/*!
  Klasa genryczna sluzaca do przechowywania elemntow ktore sa rysowane na ekranie
*/

template <typename T, int N>
class DrawableArray
{
	//! tablica do przechowywania elementow
	T tab[N];

public:
	//!Metoda do pobierania elementu z tablicy.
	/*!
	  \brief Metoda ktora pozwala na pobranie elementu z tabliy o indexie index
	  \param index index pobieranego elementu w tablicy.
	*/
	T& getElement(int index);

	//!Metoda do dodawania elementu do tablicy.
	/*!
	  \brief Metoda ktora pozwala na dodanie elementu element do tabliy o indexie index .
	  \param index index pobieranego elementu w tablicy.
	  \param element element dodawany do tablicy.
	*/
	void addElement(int index,T element);
};

template<typename T, int N>
T& DrawableArray<T, N>::getElement(int index)
{
	return (T&)(tab[index]);
}

template<typename T, int N>
inline void DrawableArray<T, N>::addElement(int index, T element)
{
	tab[index] = element;
}