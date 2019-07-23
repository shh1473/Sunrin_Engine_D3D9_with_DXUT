#pragma once

#include "../SunrinEngine.h"

class FilterScene : public Object
{
public:
	FilterScene();
	virtual ~FilterScene();

	virtual void Update();
	virtual void Render();

public:
	EffectCamera *camera;

	SpotLight *sptLight;

	Sprite *sprite;

};