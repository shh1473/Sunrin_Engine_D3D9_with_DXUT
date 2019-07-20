#include "DXUT.h"
#include "PointLightScene.h"

PointLightScene::PointLightScene()
{
	camera = new Camera(800.0f, 600.0f);
	AddChild(camera);

	pntLight01 = new PointLight();
	AddChild(pntLight01);

	pntLight02 = new PointLight();
	AddChild(pntLight02);

	sprite = new Sprite(
		app.shaders[L"PointLightSprite"],
		app.vertexDeclarations[L"Normal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_POINT_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite);

	app.materials[L"Fieldstone"]->specularIntensity = 1.0f;
	app.materials[L"Fieldstone"]->specularPower = 50.0f;

	app.camera = camera;
	camera->translation.z = -500.0f;

	pntLight01->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	pntLight01->translation.y = 150.0f;
	pntLight01->translation.z = -100.0f;
	pntLight01->radius = 300.0f;
	pntLight02->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	pntLight02->translation.y = -150.0f;
	pntLight02->translation.z = -100.0f;
	pntLight02->radius = 300.0f;

	sprite->pointLightCount = 2;
	sprite->pointLights[0] = pntLight01;
	sprite->pointLights[1] = pntLight02;
}

PointLightScene::~PointLightScene()
{

}

void PointLightScene::Update()
{
	Object::Update();

	if (app.IsPressing('D'))
	{
		pntLight01->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('A'))
	{
		pntLight01->translation.x -= 100.0f * app.deltaTime;
	}

	if (app.IsPressing('E'))
	{
		pntLight02->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('Q'))
	{
		pntLight02->translation.x -= 100.0f * app.deltaTime;
	}

	if (app.IsPressing('L'))
	{
		camera->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('J'))
	{
		camera->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('I'))
	{
		camera->translation.y += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('K'))
	{
		camera->translation.y -= 100.0f * app.deltaTime;
	}
}

void PointLightScene::Render()
{
	Object::Render();
}