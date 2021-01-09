#pragma once
#include "pch.h"

using namespace cocos2d;
using namespace GD;

class MyLayer : public CCScene
{
	MyLayer() = default;
	~MyLayer() = default;

	bool init();

public:
	static MyLayer* create();

	static void __stdcall returnToMenuLayer(CCObject* pSender);
};

