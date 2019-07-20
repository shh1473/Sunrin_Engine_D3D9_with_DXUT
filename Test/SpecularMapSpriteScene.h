#pragma once

#include "../SunrinEngine.h"

class SpecularMapSpriteScene : public Object
{
public:
	SpecularMapSpriteScene();
	virtual ~SpecularMapSpriteScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	SpotLight *sptLight;

	Sprite *sprite;

};