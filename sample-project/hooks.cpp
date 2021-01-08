#include "pch.h"

#include "hooks.h"
#include "extern/gd.h"

namespace hooks {
	namespace MenuLayer {
		void __stdcall callback(void* pSender) {
			using namespace cocos2d;

			auto scene = CCScene::create();
			auto label = CCLabelBMFont::create("wat", "bigFont.fnt");
			label->setPosition(30.0f, 30.0f);
			scene->addChild(label);
			auto transition = CCTransitionCrossFade::create(0.5, scene);
			CCDirector::sharedDirector()->replaceScene(transition);
		}

		void __declspec(naked) init() {
			__asm {
				//"GJ_statsBtn_001.png"
				mov eax, GD::base
				add eax, 0x2B23F8
				push eax
				//cocos2d::CCSprite::createWithSpriteFrameName
				mov eax, GD::base
				add eax, 0x282284
				call [eax]
				mov esi, eax
				mov dword ptr [esp], 0x3F800000
				//this ptr
				mov ecx, esi
				//vtable
				mov edx, dword ptr [esi]
				call [edx + 0x50]
				//function callback
				push callback
				push ebx
				mov ecx, esi
				mov eax, GD::base
				add eax, 0x18EE0
				call eax
				mov ecx, dword ptr [esp + 0x20]
				add esp, 0x8
				mov edx, dword ptr [ecx]
				push eax
				call dword ptr [edx + 0xE0]
				//"GJ_statsBtn_001.png"
				mov eax, GD::base
				add eax, 0x2CD6D4
				push eax
				mov eax, GD::base
				add eax, 0x190BD5
				jmp eax
			}
		}
	}
}
