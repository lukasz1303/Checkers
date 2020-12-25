#pragma once
#include <iostream>
#include <windows.h>

//!  Klasa TextureException. 
/*!
  Struktura tworzaca wyjatek obslugujacy braj tekstur lub czcionek potrzebnych do funkcjonowania gry.
*/

struct TextureException : public std::exception
{
	const char* what() const throw ()
	{
		MessageBoxA(NULL, "Brak tekstur lub czcionek", "Error!", MB_OKCANCEL);
		exit(0);
		return "Brak tekstur";
	}
};