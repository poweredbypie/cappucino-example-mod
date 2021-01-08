#pragma once
#include "pch.h"

namespace GD {
	//making it a char pointer because usually offsets are in bytes
	const inline char* base = reinterpret_cast<char*>(GetModuleHandle(0));

	namespace MenuLayer {
		//this isnt the beginning of the function its like the middle lol
		const inline int(__thiscall* init)(cocos2d::CCLayer*) = reinterpret_cast<decltype(init)>(base + 0x1907B0);
	}

	inline bool init() {
		//make sure base is valid, if it is then everything else should be fine
		return base;
	}
}