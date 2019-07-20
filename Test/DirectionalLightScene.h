#pragma once

#include "../SunrinEngine.h"

class DirectionalLightScene : public Object
{
public:
	DirectionalLightScene();
	virtual ~DirectionalLightScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	DirectionalLight *dirLight01;
	DirectionalLight *dirLight02;

	Sprite *sprite;

};