#pragma once

#include "../SunrinEngine.h"

class EmptyScene : public Object
{
public:
	EmptyScene();
	virtual ~EmptyScene();

	virtual void Update();
	virtual void Render();

public:
	// EMPTY!

};