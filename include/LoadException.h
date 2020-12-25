#pragma once

#include <iostream>
#include <windows.h>

//!  Klasa LoadException. 
/*!
  Struktura tworzaca wyjatek obslugujacy brak plikow zapisu
*/

struct LoadException : public std::exception
{
	const char* what() const throw ()
	{
		MessageBoxA(NULL, "Brak zapisu", "Error!", MB_OK);
		return "Brak zapisu";
	}
};