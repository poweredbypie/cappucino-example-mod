#include "pch.h"

#include "hooks.h"
#include "extern/gd.h"
#include "MyLayer.h"

namespace hooks {
	namespace MenuLayer {
		/*make sure the return value, calling convention, and parameters are 
		* identical to this one!
		*/
		void __stdcall callback(cocos2d::CCObject* pSender) {
			using namespace cocos2d;

			//create function already initializes the new layer, so...
			auto scene = MyLayer::create();
		}

		int __fastcall init(cocos2d::CCLayer* MenuLayer) {
			using namespace cocos2d;
			using namespace GD;

			auto director = CCDirector::sharedDirector();
			auto winSize = director->getWinSize();

			//init menulayer first!
			int ret = gates::MenuLayer::init(MenuLayer);

			auto menu = CCMenu::create();

			auto button = ButtonSprite::create(
				CCSprite::createWithSpriteFrameName("controllerBtn_LThumb_001.png"),
				MenuLayer,
				callback
			);
			button->setPosition((-winSize.width / 2) + 25.0f, (-winSize.height / 2) + 90.0f);
			menu->addChild(button);

			MenuLayer->addChild(menu);

			return ret;
		}
	}
}
