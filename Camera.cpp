#include "DXUT.h"
#include "Camera.h"

Camera::Camera(float viewWidth, float viewHeight) :
	viewWidth(viewWidth),
	viewHeight(viewHeight),
	nearZ(0.1f),
	farZ(1000.0f),
	eye(0.0f, 0.0f, 0.0f),
	look(0.0f, 0.0f, 0.0f),
	up(0.0f, 1.0f, 0.0f)
{
	D3DXMatrixIdentity(&viewMatrix);
	D3DXMatrixIdentity(&projMatrix);
}

void Camera::Update()
{
	eye = translation;
	//look = translation;

	//look.z += 100.0f;

	D3DXMatrixLookAtLH(&viewMatrix, &eye, &look, &up);
	D3DXMatrixOrthoLH(&projMatrix, viewWidth, viewHeight, nearZ, farZ);
}