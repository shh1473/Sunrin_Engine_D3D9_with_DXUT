#pragma once

#include "../SunrinEngine.h"

class SpotLightScene : public Object
{
public:
	SpotLightScene();
	virtual ~SpotLightScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	SpotLight *sptLight01;
	SpotLight *sptLight02;

	Sprite *sprite;

};