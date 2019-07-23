#pragma once

#include "../SunrinEngine.h"

class BloomScene : public Object
{
public:
	BloomScene();
	virtual ~BloomScene();

	virtual void Update();
	virtual void Render();

public:
	EffectCamera *camera;

	SpotLight *sptLight;

	Sprite *sprite;

};