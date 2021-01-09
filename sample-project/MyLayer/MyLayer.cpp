#include "pch.h"

#include "MyLayer.h"

bool MyLayer::init() {
	//set up scene here!
	auto director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	auto label = CCLabelBMFont::create("hello from my scene!", "bigFont.fnt");
	label->setPosition(winSize / 2);

	auto menu = CCMenu::create();

	auto button = ButtonSprite::create(
		CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
		this,
		&returnToMenuLayer
	);
	button->setPosition((-winSize.width / 2) + 25.0f, (winSize.height / 2) - 25.0f);
	menu->addChild(button);

	addChild(menu);
	addChild(label);

	auto transition = CCTransitionFade::create(0.5f, this);
	return director->replaceScene(transition);
}

void __stdcall MyLayer::returnToMenuLayer(CCObject* pSender) {
	auto director = CCDirector::sharedDirector();

	auto scene = CCScene::create();
	auto MenuLayer = CCLayer::create();
	MenuLayer::init(MenuLayer);
	scene->addChild(MenuLayer);

	auto transition = CCTransitionFade::create(0.5f, scene);
	director->replaceScene(transition);
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