#include "DXUT.h"
#include "SpotLightScene.h"

SpotLightScene::SpotLightScene()
{
	camera = new Camera(800.0f, 600.0f);
	AddChild(camera);

	sptLight01 = new SpotLight();
	AddChild(sptLight01);

	sptLight02 = new SpotLight();
	AddChild(sptLight02);

	sprite = new Sprite(
		app.shaders[L"SpotLightSprite"],
		app.vertexDeclarations[L"Normal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_SPOT_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite);

	app.materials[L"Fieldstone"]->specularIntensity = 1.0f;
	app.materials[L"Fieldstone"]->specularPower = 50.0f;

	app.camera = camera;
	camera->translation.z = -500.0f;

	sptLight01->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	sptLight01->translation = D3DXVECTOR3(-150.0f, 150.0f, -100.0f);
	sptLight01->rotation.y = 30.0f;
	sptLight01->innerAngle = 85.0f;
	sptLight01->outerAngle = 70.0f;
	sptLight01->radius = 1000.0f;

	sptLight02->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	sptLight02->translation = D3DXVECTOR3(150.0f, -150.0f, -100.0f);
	sptLight02->rotation.y = -30.0f;
	sptLight02->innerAngle = 85.0f;
	sptLight02->outerAngle = 70.0f;
	sptLight02->radius = 1000.0f;

	sprite->spotLightCount = 2;
	sprite->spotLights[0] = sptLight01;
	sprite->spotLights[1] = sptLight02;
}

SpotLightScene::~SpotLightScene()
{

}

void SpotLightScene::Update()
{
	Object::Update();

	if (app.IsPressing('D'))
	{
		sptLight01->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('A'))
	{
		sptLight01->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('S'))
	{
		sptLight01->rotation.y += 180.0f * app.deltaTime;
	}

	if (app.IsPressing('E'))
	{
		sptLight02->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('Q'))
	{
		sptLight02->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('W'))
	{
		sptLight02->rotation.y += 180.0f * app.deltaTime;
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

void SpotLightScene::Render()
{
	Object::Render();
}