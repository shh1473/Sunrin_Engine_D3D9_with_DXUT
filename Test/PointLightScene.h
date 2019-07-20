#pragma once

#include "../SunrinEngine.h"

class PointLightScene : public Object
{
public:
	PointLightScene();
	virtual ~PointLightScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	PointLight *pntLight01;
	PointLight *pntLight02;

	Sprite *sprite;

};