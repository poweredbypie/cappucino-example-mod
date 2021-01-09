#pragma once
#include "pch.h"

namespace GD {
	//making it a char pointer because usually offsets are in bytes
	const inline char* base = reinterpret_cast<char*>(GetModuleHandle(0));

	namespace MenuLayer {
		inline int(__thiscall const* init)(cocos2d::CCLayer* MenuLayer) = 
			reinterpret_cast<decltype(init)>(base + 0x1907B0);
	}

	namespace ButtonSprite {
		inline cocos2d::CCMenuItemSprite* create
		(cocos2d::CCSprite* sprite, cocos2d::CCObject* target, void* callback) {
			//the actual function here lol
			auto _create = reinterpret_cast<cocos2d::CCMenuItemSprite*(__thiscall*)
				(cocos2d::CCSprite*, cocos2d::CCObject*, void*)>(base + 0x18EE0);

			cocos2d::CCMenuItemSprite* pRet = _create(sprite, target, callback);
			//fix stack
			__asm {
				add esp, 0x8
			}
			return pRet;
		}
	}

	inline bool init() {
		//make sure base is valid, if it is then everything else should be fine
		return base;
	}
}