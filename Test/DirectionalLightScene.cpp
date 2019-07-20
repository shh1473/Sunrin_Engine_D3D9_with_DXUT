#include "DXUT.h"
#include "DirectionalLightScene.h"

DirectionalLightScene::DirectionalLightScene()
{
	camera = new Camera(800.0f, 600.0f);
	AddChild(camera);

	dirLight01 = new DirectionalLight();
	AddChild(dirLight01);

	dirLight02 = new DirectionalLight();
	AddChild(dirLight02);

	sprite = new Sprite(
		app.shaders[L"DirectionalLightSprite"],
		app.vertexDeclarations[L"Normal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_DIRECTIONAL_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite);

	app.materials[L"Fieldstone"]->specularIntensity = 1.0f;
	app.materials[L"Fieldstone"]->specularPower = 50.0f;

	app.camera = camera;
	camera->translation.z = -500.0f;

	dirLight01->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	dirLight01->rotation.x = -45.0f;
	dirLight01->rotation.y = -45.0f;
	dirLight02->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);

	sprite->directionalLightCount = 2;
	sprite->directionalLights[0] = dirLight01;
	sprite->directionalLights[1] = dirLight02;
}

DirectionalLightScene::~DirectionalLightScene()
{

}

void DirectionalLightScene::Update()
{
	Object::Update();

	if (app.IsPressing('D'))
	{
		dirLight01->rotation.y += 30.0f * app.deltaTime;
	}
	if (app.IsPressing('A'))
	{
		dirLight01->rotation.y -= 30.0f * app.deltaTime;
	}

	if (app.IsPressing('E'))
	{
		dirLight02->rotation.y += 30.0f * app.deltaTime;
	}
	if (app.IsPressing('Q'))
	{
		dirLight02->rotation.y -= 30.0f * app.deltaTime;
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

void DirectionalLightScene::Render()
{
	Object::Render();
}