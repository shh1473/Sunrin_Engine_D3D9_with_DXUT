#pragma once

#include "../SunrinEngine.h"

class IntersectionScene : public Object
{
public:
	IntersectionScene();
	virtual ~IntersectionScene();

	virtual void Update();
	virtual void Render();

public:
	Camera *camera;

	Sound *sound;

	SpotLight *sptLight;

	Sprite *sprite01;
	Sprite *sprite02;

};