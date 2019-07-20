#pragma once

#include "../SunrinEngine.h"

class DiffuseMapSpriteScene : public Object
{
public:
	DiffuseMapSpriteScene();
	virtual ~DiffuseMapSpriteScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	Sprite *sprite01;
	Sprite *sprite02;

};