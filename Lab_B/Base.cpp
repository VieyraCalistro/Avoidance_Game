#include "pch.h"
#include "Base.h"
#include "Console.h"
#include "stdafx.h"
#include "Player.h"
#include "Obstacle.h"
using namespace std;


Base::Base()
{
}


Base::~Base()
{
}

void Base::Update()
{
	// Meant to be overridden.

}
void Base::Render()
{
	// Meant to be overridden.
}

int Base::GetXPos()
{
	return _x;
}

void Base::SetXPos(int aX)
{
	_x = aX;
}

int Base::GetYPos()
{
	return _y;
}

void Base::SetYPos(int aY)
{
	_y = aY;
}

char Base::GetImage()
{
	return _image;
}

void Base::SetImage(char aImage)
{
	_image = aImage;
}

//int Base::GetProjectileXPos()
//{
//	return projectileXPos;
//}
//
//void Base::SetProjectileXPos(int aXPos)
//{
//	projectileXPos = aXPos;
//}
//
//int Base::GetProjectileYPos()
//{
//	return projectileYPos;
//}
//
//void Base::SetProjectileYPos(int aYPos)
//{
//	projectileYPos = aYPos;
//}

