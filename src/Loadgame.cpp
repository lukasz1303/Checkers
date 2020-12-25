#pragma once

#include "../include/Loadgame.h"

void Loadgame::load() {
	ifstream file;
	file.open("saved game/savepawns.dat");
	if (!file.is_open())
		throw LoadException();

	float value;
	amountOfBlack = 0;
	amountOfWhite = 0;
	file >> amountWhiteCanMove;
	file >> amountBlackCanMove;
	file >> centerOfMenuSectionX;
	file >> centerOfMenuSectionY;
	file >> k;
	int i = 0;
	int j = 0;
	file >> value;
	if (value == 1)
	{
		isMove = true;
	}
	else
	{
		isMove = false;
	}
	file >> value;
	if (value==1)
	{
		turn = true;
	}
	else
	{
		turn = false;
	}
	file >> value;
	if (value == 1)
	{
		whiteCanCapture = true;
	}
	else
	{
		whiteCanCapture = false;
	}
	file >> value;
	if (value == 1)
	{
		blackCanCapture = true;
	}
	else
	{
		blackCanCapture = false;
	}
	while (file >> value)
	{
		
		tab[i][j]=value;
		if (value == 1 || value == 2) {
			amountOfWhite++;
			ilosc++;
		}
		if (value == -1 || value == -2) {
			amountOfBlack++;
			ilosc++;
		}
		
		j++;
		if (j == 8) {
			i++;
			j = 0;
		}
	}	
	file.close();
}

Loadgame::Loadgame() {
	
	load();
	
	for (int i = 0; i < 12; i++)
	{
		pawns[i] = new Pawn();
		
		if (i > amountOfWhite-1) {
			pawns[i]->setCoordinates(100, 100);
			pawns[i]->setCaptured();
		}
	}
	for (int j = 12; j < 24; j++) {
		pawns[j] = new Pawn();
		
		if (j > (amountOfBlack + 12-1)) {
			pawns[j]->setCoordinates(100, 100);
			pawns[j]->setCaptured();
		}
	}

	loadTexturesAndFont();

	loadBoard();

	centerOfMenuSectionX = Checkerboard.getPosition().x + Checkerboard.getSize().x + (screen_width - Checkerboard.getPosition().x - Checkerboard.getSize().x) / 2;
	centerOfMenuSectionY = Checkerboard.getPosition().y + Checkerboard.getSize().y / 2;
	loadPawns();
	loadLettersAndNumbers();

	loadBackground();
	
	loadPlayers();

	checkCaptures();
	loadPlayersNames();
}

Loadgame::~Loadgame() {
}



