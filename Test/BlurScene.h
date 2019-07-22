#pragma once

#include "../SunrinEngine.h"

class BlurScene : public Object
{
public:
	BlurScene();
	virtual ~BlurScene();

	virtual void Update();
	virtual void Render();

public:
	EffectCamera * camera;

	SpotLight * sptLight;

	Sprite * sprite;

};