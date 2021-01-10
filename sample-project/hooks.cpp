#include "pch.h"

#include "hooks.h"
#include "extern/gd.h"
#include "MyLayer/MyLayer.h"

namespace hooks {
	namespace MenuLayer {
		//hacky but IDC because it IS a hack :/
		class wrapper {
		public:
			void callback(cocos2d::CCObject* pSender) {
				auto scene = CCScene::create();
				auto myLayer = MyLayer::create();
				scene->addChild(myLayer);

				auto transition = CCTransitionFade::create(0.5f, scene);
				CCDirector::sharedDirector()->pushScene(transition);
			}
		};

		int __fastcall init(cocos2d::CCLayer* MenuLayer) {
			using namespace cocos2d;
			using namespace GD;

			auto director = CCDirector::sharedDirector();
			auto winSize = director->getWinSize();

			//init menulayer first!
			int ret = gates::MenuLayer::init(MenuLayer);

			auto bottomMenu = reinterpret_cast<CCMenu*>(MenuLayer->getChildren()->objectAtIndex(3));
			auto dailyButton = reinterpret_cast<CCMenuItemSpriteExtra*>(bottomMenu->getChildren()->objectAtIndex(4));
			auto myButton = CCMenuItemSpriteExtra::create(
				CCSprite::createWithSpriteFrameName("GJ_backBtn_001.png"),
				CCSprite::createWithSpriteFrameName("GJ_backBtn_001.png"),
				MenuLayer,
				menu_selector(wrapper::callback)
			);

			//move the daily button out of the bottom menu so we can center it easily without using too much hard-to-read assembly
			bottomMenu->removeChild(dailyButton, false);
			
			bottomMenu->addChild(myButton);
			bottomMenu->alignItemsHorizontallyWithPadding(5.0f);

			//then add it back again LOL
			bottomMenu->addChild(dailyButton);

			return ret;
		}
	}
}
