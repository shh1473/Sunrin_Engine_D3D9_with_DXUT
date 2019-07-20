#pragma once

#include "../SunrinEngine.h"

class SoundScene : public Object
{
public:
	SoundScene();
	virtual ~SoundScene();

	virtual void Update();
	virtual void Render();

public:
	Sound *sound;

};