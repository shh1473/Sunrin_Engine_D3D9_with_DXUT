#pragma once

#include "../SunrinEngine.h"

class UIScene : public Object
{
public:
	UIScene();
	virtual ~UIScene();

	virtual void Update();
	virtual void Render();

public:
	EffectCamera *camera;

	SpotLight *sptLight;

	Sprite *sprite;
	Text *UIText;

};