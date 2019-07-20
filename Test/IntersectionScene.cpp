#include "DXUT.h"
#include "IntersectionScene.h"

IntersectionScene::IntersectionScene()
{
	// 생성
	camera = new Camera(800.0f, 600.0f);
	AddChild(camera);

	sound = app.sounds[L"TestSound"];

	sptLight = new SpotLight();
	AddChild(sptLight);

	sprite01 = new Sprite(
		app.shaders[L"NormalMapSprite"],
		app.vertexDeclarations[L"TangentBinormal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_SPECULAR_MAP |
		SPRITE_ENABLE_NORMAL_MAP |
		SPRITE_ENABLE_SPOT_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite01);

	sprite02 = new Sprite(
		app.shaders[L"NormalMapSprite"],
		app.vertexDeclarations[L"TangentBinormal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_SPECULAR_MAP |
		SPRITE_ENABLE_NORMAL_MAP |
		SPRITE_ENABLE_SPOT_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite02);

	// 설정
	app.materials[L"Fieldstone"]->specularIntensity = 10.0f;
	app.materials[L"Fieldstone"]->specularPower = 20.0f;

	app.camera = camera;
	camera->translation.z = -500.0f;

	sptLight->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	sptLight->translation = D3DXVECTOR3(0.0f, 0.0f, -100.0f);
	sptLight->innerAngle = 85.0f;
	sptLight->outerAngle = 70.0f;
	sptLight->radius = 1000.0f;

	sprite01->translation = D3DXVECTOR3(-400.0f, -400.0f, 0.0f);
	sprite01->width = sprite02->material->width;
	sprite01->height = sprite02->material->height;
	sprite01->color = D3DXVECTOR4(1.0f, 0.3f, 0.3f, 1.0f);
	sprite01->spotLightCount = 1;
	sprite01->spotLights[0] = sptLight;

	sprite02->translation = D3DXVECTOR3(400.0f, 400.0f, 0.0f);
	sprite02->width = sprite02->material->width;
	sprite02->height = sprite02->material->height;
	sprite02->color = D3DXVECTOR4(0.3f, 0.3f, 1.0f, 1.0f);
	sprite02->spotLightCount = 1;
	sprite02->spotLights[0] = sptLight;
}

IntersectionScene::~IntersectionScene()
{

}

void IntersectionScene::Update()
{
	Object::Update();

	if (sprite01->rect.IsIntersect(sprite02->rect))
	{
		std::cout << "INTERSECTION!" << std::endl;
	}

	if (app.IsPressing('D'))
	{
		sprite01->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('A'))
	{
		sprite01->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('W'))
	{
		sprite01->translation.y	+= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('S'))
	{
		sprite01->translation.y -= 100.0f * app.deltaTime;
	}

	if (app.IsPressing('L'))
	{
		sprite02->translation.x += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('J'))
	{
		sprite02->translation.x -= 100.0f * app.deltaTime;
	}
	if (app.IsPressing('I'))
	{
		sprite02->translation.y += 100.0f * app.deltaTime;
	}
	if (app.IsPressing('K'))
	{
		sprite02->translation.y -= 100.0f * app.deltaTime;
	}
}

void IntersectionScene::Render()
{
	Object::Render();
}