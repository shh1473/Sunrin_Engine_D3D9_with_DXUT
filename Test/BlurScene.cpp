#include "DXUT.h"
#include "BlurScene.h"

BlurScene::BlurScene()
{
	// 생성
	camera = new EffectCamera(
		app.shaders[L"CameraBlur"],
		app.vertexDeclarations[L"TexCoord"],
		app.surfaces[L"SourceMap4"],
		CAMERA_BLUR);
	AddChild(camera);

	sptLight = new SpotLight();
	AddChild(sptLight);

	sprite = new Sprite(
		app.shaders[L"NormalMapSprite"],
		app.vertexDeclarations[L"TangentBinormal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_SPECULAR_MAP |
		SPRITE_ENABLE_NORMAL_MAP |
		SPRITE_ENABLE_SPOT_LIGHT |
		SPRITE_ENABLE_SPECULAR);
	AddChild(sprite);

	// 설정
	app.materials[L"Fieldstone"]->specularIntensity = 10.0f;
	app.materials[L"Fieldstone"]->specularPower = 20.0f;

	app.camera = camera;
	camera->sourceMaps[0] = app.surfaces[L"Scene"];
	camera->sourceMaps[1] = app.surfaces[L"SourceMap1"];
	camera->sourceMaps[2] = app.surfaces[L"SourceMap2"];
	camera->sourceMaps[3] = app.surfaces[L"SourceMap3"];
	camera->thresholdIntensityViewportInv.z = 1.0f / static_cast<float>(camera->sourceMaps[0]->desc.Width);
	camera->thresholdIntensityViewportInv.w = 1.0f / static_cast<float>(camera->sourceMaps[0]->desc.Height);
	camera->translation.z = -500.0f;

	sptLight->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 2.0f);
	sptLight->translation = D3DXVECTOR3(0.0f, 0.0f, -100.0f);
	sptLight->rotation.y = 30.0f;
	sptLight->innerAngle = 85.0f;
	sptLight->outerAngle = 70.0f;
	sptLight->radius = 1000.0f;

	sprite->spotLightCount = 1;
	sprite->spotLights[0] = sptLight;
}

BlurScene::~BlurScene()
{

}

void BlurScene::Update()
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
}

void BlurScene::Render()
{
	camera->Ready();

	Object::Render();

	camera->Effect();
}