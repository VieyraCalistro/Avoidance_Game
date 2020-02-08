#pragma once
#include"Console.h"

using namespace System;

class Base
{
public:
	Base();
	~Base();

	void virtual Update();

	void virtual Render();

	int GetXPos();
	void SetXPos(int aX);

	int GetYPos();
	void SetYPos(int aY);

	char GetImage();
	void SetImage(char aimage);

private:

	int _x = 0;

	int _y = 0;

	char _image;
};

