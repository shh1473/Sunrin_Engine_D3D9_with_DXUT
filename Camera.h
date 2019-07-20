#pragma once

#include "Object.h"

class Camera : public Object
{
public:
	Camera(float viewWidth, float viewHeight);

	virtual void Update();

public:
	float viewWidth;
	float viewHeight;
	float nearZ;
	float farZ;
	D3DXVECTOR3 eye;
	D3DXVECTOR3 look;
	D3DXVECTOR3 up;
	D3DXMATRIX viewMatrix;
	D3DXMATRIX projMatrix;

};