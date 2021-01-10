#include "pch.h"

#include "MyLayer.h"

bool MyLayer::init() {
	//set up scene here!
	auto director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	auto label = CCLabelBMFont::create("hello from my scene!", "bigFont.fnt");
	label->setPosition(winSize / 2);

	auto menu = CCMenu::create();

	auto button = CCMenuItemSpriteExtra::create(
		CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
		CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
		this,
		menu_selector(MyLayer::returnToMenuLayer)
	);
	button->setPosition((-winSize.width / 2) + 25.0f, (winSize.height / 2) - 25.0f);
	menu->addChild(button);

	addChild(menu);
	addChild(label);

	setKeypadEnabled(true);
	return true;
}

void MyLayer::keyBackClicked() {
	returnToMenuLayer(nullptr);
}

void MyLayer::returnToMenuLayer(CCObject* pSender) {
	CCDirector::sharedDirector()->popSceneWithTransition(0.5f, FadeTransition);
}

MyLayer* MyLayer::create() {
	MyLayer* pRet = new MyLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}