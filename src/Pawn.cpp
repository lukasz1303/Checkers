#pragma once
#include "../include/Pawn.h"

Pawn::Pawn()
{
}

Pawn::Pawn(Texture t)
{
	texture = t;
	textureSize = t.getSize();
}

void Pawn::setCoordinates(int x, int y)
{
	coordinateX = x;
	coordinateY = y;
}

void Pawn::setKingLastTurn(bool k)
{
	kingLastTurn = k;
}

void Pawn::setBlack()
{
	black = true;
}

void Pawn::setKing()
{
	king = true;
}

void Pawn::setCaptured()
{
	captured = true;
}

void Pawn::loadKingTexture()
{
	texture = kingTexture;
}

void Pawn::hasCapture(int tab[8][8])
{
	canCapture = false;
	moves.clear();
	if (king && !kingLastTurn) {
		for (int i = 1; i < 8; i++) {
			if ((coordinateY + i + 1) <= 7 && (coordinateX + i + 1) <= 7 && ((tab[coordinateY + i][coordinateX + i] > 0 && black) || (tab[coordinateY + i][coordinateX + i] < 0 && !black)) && tab[coordinateY + i + 1][coordinateX + i + 1] == 0) {
				canCapture = true;
				for (int j = i; j < 8; j++) {
					if (coordinateY + j + 1 > 7 || coordinateX + j + 1 > 7 || tab[coordinateY + j + 1][coordinateX + j + 1] != 0) {
						break;
					}
					moves.insert(make_pair(coordinateY + j + 1, coordinateX + j + 1));
				}
			}
			else if (canCapture || ((tab[coordinateY + i][coordinateX + i] != 0) && (tab[coordinateY + i+1][coordinateX + i+1] != 0))) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {

			if ((coordinateY + i + 1) <= 7 && (coordinateX - i - 1) >= 0 && ((tab[coordinateY + i][coordinateX - i] > 0 && black) || (tab[coordinateY + i][coordinateX - i] < 0 && !black)) && tab[coordinateY + i + 1][coordinateX - i - 1] == 0) {
				canCapture = true;
				for (int j = i; j < 8; j++) {
					if (coordinateY + j + 1 > 7 || coordinateX - j - 1 < 0 || tab[coordinateY + j + 1][coordinateX - j - 1] != 0) {
						break;
					}
					moves.insert(make_pair(coordinateY + j + 1, coordinateX - j - 1));
				}
			}
			else if (canCapture || ((tab[coordinateY + i][coordinateX - i] != 0) && (tab[coordinateY + i + 1][coordinateX - i - 1] != 0))) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {

			if ((coordinateY - i - 1) >= 0 && (coordinateX + i + 1) <= 7 && ((tab[coordinateY - i][coordinateX + i] > 0 && black) || (tab[coordinateY - i][coordinateX + i] < 0 && !black)) && tab[coordinateY - i - 1][coordinateX + i + 1] == 0) {
				canCapture = true;
				for (int j = i; j < 8; j++) {
					if (coordinateY - j - 1 < 0 || coordinateX + j + 1 > 7 || tab[coordinateY - j - 1][coordinateX + j + 1] != 0) {
						break;
					}
					moves.insert(make_pair(coordinateY - j - 1, coordinateX + j + 1));
				}
			}
			else if (canCapture || ((tab[coordinateY - i][coordinateX + i] != 0) && (tab[coordinateY - i - 1][coordinateX + i + 1] != 0))) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {

			if ((coordinateY - i - 1) >= 0 && (coordinateX - i - 1) >= 0 && ((tab[coordinateY - i][coordinateX - i] > 0 && black) || (tab[coordinateY - i][coordinateX - i] < 0 && !black)) && tab[coordinateY - i - 1][coordinateX - i - 1] == 0) {
				canCapture = true;
				for (int j = i; j < 8; j++) {
					if (coordinateY - j - 1 < 0 || coordinateX - j - 1 < 0  || tab[coordinateY - j - 1][coordinateX - j - 1] != 0) {
						break;
					}
					moves.insert(make_pair(coordinateY - j - 1, coordinateX - j - 1));
				}
			}
			else if (canCapture || ((tab[coordinateY - i][coordinateX - i] != 0) && (tab[coordinateY - i - 1][coordinateX - i - 1] != 0))) {
				break;
			}
		}
		if (!canCapture) {
			for (int i = 1; i < 8; i++) {
				if (!canCapture) {
					if ((coordinateY + i) > 7 || (coordinateX + i) > 7 || tab[coordinateY + i][coordinateX + i] != 0) {
						break;
					}
					else if (tab[coordinateY + i][coordinateX + i] == 0) {
						this->moves.insert(make_pair(coordinateY + i, coordinateX + i));
					}
				}
			}
			for (int i = 1; i < 8; i++) {
				if (!canCapture) {
					if ((coordinateY + i) > 7 || (coordinateX - i) < 0 || tab[coordinateY + i][coordinateX - i] != 0) {
						break;
					}
					else if (tab[coordinateY + i][coordinateX - i] == 0) {
						this->moves.insert(make_pair(coordinateY + i, coordinateX - i));
					}
				}
			}
			for (int i = 1; i < 8; i++) {
				if (!canCapture) {
					if ((coordinateY - i) < 0 || (coordinateX + i) > 7 || tab[coordinateY - i][coordinateX + i] != 0) {
						break;
					}
					else if (tab[coordinateY - i][coordinateX + i] == 0) {
						this->moves.insert(make_pair(coordinateY - i, coordinateX + i));
					}
				}
			}
			for (int i = 1; i < 8; i++) {
				if (!canCapture) {
					if ((coordinateY - i) < 0 || (coordinateX - i) < 0 || tab[coordinateY - i][coordinateX - i] != 0) {
						break;
					}
					else if (tab[coordinateY - i][coordinateX - i] == 0) {
						this->moves.insert(make_pair(coordinateY - i, coordinateX - i));
					}
				}
			}
		}
	}
	else {
		if ((tab[coordinateY + 2][coordinateX + 2] == 0 && (tab[coordinateY + 1][coordinateX + 1] > 0 && black || tab[coordinateY + 1][coordinateX + 1] < 0 && !black) && (coordinateY + 2) <= 7 && (coordinateX + 2) <= 7)) {
			canCapture = true;
			moves.insert(make_pair(coordinateY + 2, coordinateX + 2));
		}
		if ((tab[coordinateY + 2][coordinateX - 2] == 0 && (tab[coordinateY + 1][coordinateX - 1] > 0 && black || tab[coordinateY + 1][coordinateX - 1] < 0 && !black) && (coordinateY + 2) <= 7 && (coordinateX - 2) >= 0)) {
			canCapture = true;
			moves.insert(make_pair(coordinateY + 2, coordinateX - 2));
		}
		if ((tab[coordinateY - 2][coordinateX + 2] == 0 && (tab[coordinateY - 1][coordinateX + 1] > 0 && black || tab[coordinateY - 1][coordinateX + 1] < 0 && !black) && (coordinateY - 2) >= 0 && (coordinateX + 2) <= 7)) {
			canCapture = true;
			moves.insert(make_pair(coordinateY - 2, coordinateX + 2));
		}
		if ((tab[coordinateY - 2][coordinateX - 2] == 0 && (tab[coordinateY - 1][coordinateX - 1] > 0 && black || tab[coordinateY - 1][coordinateX - 1] < 0 && !black) && (coordinateY - 2) >= 0 && (coordinateX - 2) >= 0)) {
			canCapture = true;
			moves.insert(make_pair(coordinateY - 2, coordinateX - 2));
		}
	}
}

void Pawn::setKingTexture(Texture t)
{
	kingTexture = t;
}

bool Pawn::getCanCapture()
{
	return canCapture;
}

bool Pawn::getKingLastTurn()
{
	return kingLastTurn;
}

bool Pawn::isBlack()
{
	return black;
}

bool Pawn::isKing()
{
	return king;
}

bool Pawn::isCaptured()
{
	return captured;
}

bool Pawn::canMove(int tab[8][8])
{	

	this->hasCapture(tab);
	if (canCapture) {
		return true;
	}
	else if (king && ! kingLastTurn) {
		if ((coordinateY - 1 >= 0 && (tab[coordinateY - 1][coordinateX - 1] != 0 && coordinateX - 1 >= 0) && (tab[coordinateY - 1][coordinateX + 1] != 0 && coordinateX + 1 <= 7)) &&
			(coordinateY + 1 <= 7 && (tab[coordinateY + 1][coordinateX - 1] != 0 && coordinateX - 1 >= 0) && (tab[coordinateY + 1][coordinateX + 1] != 0 && coordinateX + 1 <= 7))) {
			return false;
		}
		else {
			return true;
		}
	}
	else if (black) {
			if ((coordinateY - 1 < 0 || (coordinateY - 1 >= 0 && tab[coordinateY - 1][coordinateX - 1] != 0 && coordinateX - 1 >= 0) || coordinateX - 1 < 0) && 
			(coordinateY - 1 <0 || (coordinateY - 1 >= 0 && tab[coordinateY - 1][coordinateX + 1] != 0 && coordinateX + 1 >= 0) || coordinateX + 1 > 7)) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
//		cout << "tablica" << endl;
//for (int i = 0; i < 8; i++) {
//	cout << "[";
//	for (int j = 0; j < 8; j++) {
//		cout << tab[i][j] << " ";
//	}
//
//}
//cout << "]" << endl;
//cout << (coordinateY + 1 <= 7 && (tab[coordinateY + 1][coordinateX - 1] != 0)) << endl;
//cout << (tab[coordinateY + 1][coordinateX + 1] != 0 && coordinateX + 1 <= 7) << endl;
		if ((coordinateY + 1 > 7 || (coordinateY + 1 <= 7 && tab[coordinateY + 1][coordinateX - 1] != 0 && coordinateX - 1 >= 0) || coordinateX - 1 < 0) && 
			(coordinateY + 1 > 7 || (coordinateY + 1 <= 7 && tab[coordinateY + 1][coordinateX + 1] != 0 && coordinateX + 1 >= 0) || coordinateX + 1 > 7)) {
			return false;
		}
		else {
			return true;
		}
	}
}


Vector2u Pawn::getCoordinates()
{
	return Vector2u(coordinateX, coordinateY);
}

Vector2f Pawn::calculateScale(float boardWidth, float boardHeight)
{
	return Vector2f((float)textureSize.x * boardWidth/600000, (float)textureSize.y * boardHeight/600000);
}

Vector2f Pawn::calculatePosition(Vector2f boardPosition, Vector2f boardSize, Vector2f newPosition, int tab[8][8])
{
	int newX = (int)round((newPosition.x - boardPosition.x) / (boardSize.x / 8));
	int newY = (int)round((newPosition.y - boardPosition.y) / (boardSize.y / 8));
	int oldy = coordinateY;
	int oldx = coordinateX;

	if (newX > 7 || newX < 0 || newY >7 || newY < 0) {
		newX = coordinateX;
		newY = coordinateY;
	}
	else {
		if (canCapture) {
			if (moves.count(make_pair(newY, newX))) {
				int temp = tab[coordinateY][coordinateX];
				int t1 = ((newY - coordinateY) > 0) ? 1 : -1;
				int t2 = ((newX - coordinateX) > 0) ? 1 : -1;
				if (king) {
					for (int i = 1; i< 8; i++)
					{
						if (tab[newY - t1][newX - t2] == 0) {
							t1 += ((newY - coordinateY) > 0) ? 1 : -1;
							t2 += ((newX - coordinateX) > 0) ? 1 : -1;
						}
						else {
							break;
						}
					}
				}
				tab[newY - t1][newX - t2] = 0;
				tab[coordinateY][coordinateX] = 0;
				tab[newY][newX] = temp;
				coordinateX = newX;
				coordinateY = newY;
			}
			else {
				newX = coordinateX;
				newY = coordinateY;
			}
			if (!king && ((newY == 7 && !black) || (newY == 0 && black))) {
				this->hasCapture(tab);
				if (!canCapture) {
					king = true;
					kingLastTurn = true;
					texture = kingTexture;
					tab[newY][newX] = tab[newY][newX] * 2;
				}
			}
		}
		else if (king) {
			if (abs(newY - coordinateY) == abs(newX - coordinateX) && moves.count(make_pair(newY, newX))) {
				int t = tab[coordinateY][coordinateX];
				tab[coordinateY][coordinateX] = 0;
				tab[newY][newX] = t;
				coordinateX = newX;
				coordinateY = newY;
			}
			else {
				newX = coordinateX;
				newY = coordinateY;
			}
		}
		else if (black) {
			if ((newY + 1) == coordinateY && ((newX - 1) == coordinateX || (newX + 1) == coordinateX) && tab[newY][newX] == 0) {
				tab[coordinateY][coordinateX] = 0;
				tab[newY][newX] = -1;
				coordinateX = newX;
				coordinateY = newY;
			}
			else {
				newX = coordinateX;
				newY = coordinateY;
			}
			if (newY == 0 && !king) {
				this->hasCapture(tab);
				if (!canCapture) {
					king = true;
					kingLastTurn = true;
					texture = kingTexture;
					tab[newY][newX] = -2;
				}
			}
		}
		else {
			if ((newY - 1) == coordinateY && ((newX - 1) == coordinateX || (newX + 1) == coordinateX) && tab[newY][newX] == 0) {
				tab[coordinateY][coordinateX] = 0;
				tab[newY][newX] = 1;
				coordinateX = newX;
				coordinateY = newY;

			}
			else {
				newX = coordinateX;
				newY = coordinateY;
			}
			if (newY == 7 && !king) {
				this->hasCapture(tab);
				if (!canCapture || (newX == oldx+1 || newX == oldx - 1)) {
					king = true;
					kingLastTurn = true;
					texture = kingTexture;
					tab[newY][newX] = 2;
				}
			}
		}
	}
	return (boardPosition + Vector2f(boardSize.x / 16.f * (2 * newX + 1) - size.x / 2.f, boardSize.y / 16.f * (2 * newY + 1) - size.y / 2.f));
}