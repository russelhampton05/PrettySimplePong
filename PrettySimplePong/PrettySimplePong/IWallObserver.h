#pragma once
#include "Constants.h"
class IWallObserver
{
public:
	IWallObserver();
	~IWallObserver();

	void virtual onNotify(Constants::WallHit) = 0;
	int id;
};

