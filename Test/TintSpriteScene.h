#pragma once

#include "../SunrinEngine.h"

class TintSpriteScene : public Object
{
public:
	TintSpriteScene();
	virtual ~TintSpriteScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	Sprite *sprite01;
	Sprite *sprite02;

};