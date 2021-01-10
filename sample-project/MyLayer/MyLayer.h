#pragma once
#include "pch.h"

using namespace cocos2d;
using namespace GD;

class MyLayer : public CCLayer
{
	MyLayer() = default;
	virtual ~MyLayer() = default;

	virtual bool init();
	virtual void keyBackClicked();

public:
	static MyLayer* create();

	void returnToMenuLayer(CCObject* pSender);
};

