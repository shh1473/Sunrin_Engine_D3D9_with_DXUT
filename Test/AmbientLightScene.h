#pragma once

#include "../SunrinEngine.h"

class AmbientLightScene : public Object
{
public:
	AmbientLightScene();
	virtual ~AmbientLightScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	AmbientLight *ambLight;

	Sprite *sprite;

};