#pragma once

#include "../SunrinEngine.h"

class NormalMapSpriteScene : public Object
{
public:
	NormalMapSpriteScene();
	virtual ~NormalMapSpriteScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	SpotLight *sptLight;

	Sprite *sprite;

};