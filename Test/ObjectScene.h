#pragma once

#include "../SunrinEngine.h"

class ObjectScene : public Object
{
public:
	ObjectScene();
	virtual ~ObjectScene();

	virtual void Update();
	virtual void Render();

public:
	Object *object01;
	Object *object02;

};