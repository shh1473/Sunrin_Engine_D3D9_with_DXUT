#include "DXUT.h"
#include "SpecularMapSpriteScene.h"

SpecularMapSpriteScene::SpecularMapSpriteScene()
{
	// ����
	camera = new Camera(app.surfaces[L"BackBuffer"]);
	AddChild(camera);

	sptLight = new SpotLight();
	AddChild(sptLight);

	sprite = new Sprite(
		app.shaders[L"SpecularMapSprite"],
		app.vertexDeclarations[L"Normal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_SPECULAR_MAP |
		SPRITE_ENABLE_SPOT_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite);

	// ����
	app.materials[L"Fieldstone"]->specularIntensity = 100.0f;
	app.materials[L"Fieldstone"]->specularPower = 50.0f;

	app.camera = camera;
	camera->translation.z = -500.0f;

	sptLight->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	sptLight->translation = D3DXVECTOR3(0.0f, 0.0f, -100.0f);
	sptLight->rotation.y = 30.0f;
	sptLight->innerAngle = 85.0f;
	sptLight->outerAngle = 70.0f;
	sptLight->radius = 1000.0f;

	sprite->spotLightCount = 1;
	sprite->spotLights[0] = sptLight;
}

SpecularMapSpriteScene::~SpecularMapSpriteScene()
{

}

void SpecularMapSpriteScene::Update()
{
	Object::Update();

	if (app.IsPressing('D'))
	{
		sptLight->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('A'))
	{
		sptLight->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('W'))
	{
		sptLight->translation.y += 180.0f * app.deltaTime;
	}
	if (app.IsPressing('S'))
	{
		sptLight->translation.y -= 180.0f * app.deltaTime;
	}
	if (app.IsPressing('E'))
	{
		sptLight->rotation.y += 90.0f * app.deltaTime;
	}
	if (app.IsPressing('Q'))
	{
		sptLight->rotation.y -= 90.0f * app.deltaTime;
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

void SpecularMapSpriteScene::Render()
{
	Object::Render();
}