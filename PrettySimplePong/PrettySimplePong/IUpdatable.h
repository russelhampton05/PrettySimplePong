#pragma once
#include "Constants.h"
#include "SFML\Graphics.hpp"
class IUpdatable 
{

private:
	
public:
	IUpdatable();
	virtual ~IUpdatable();
	virtual void update() = 0;
	
};

