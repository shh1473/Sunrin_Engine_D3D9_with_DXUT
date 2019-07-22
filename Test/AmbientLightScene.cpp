#include "DXUT.h"
#include "AmbientLightScene.h"

AmbientLightScene::AmbientLightScene()
{
	camera = new Camera(app.surfaces[L"BackBuffer"]);
	AddChild(camera);

	ambLight = new AmbientLight();
	AddChild(ambLight);

	sprite = new Sprite(
		app.shaders[L"AmbientLightSprite"],
		app.vertexDeclarations[L"Normal"],
		app.materials[L"Fieldstone"],
		SPRITE_ENABLE_DIFFUSE_MAP |
		SPRITE_ENABLE_AMBIENT_LIGHT);
	AddChild(sprite);

	app.camera = camera;
	camera->translation.z = -100.0f;

	ambLight->colorIntensity = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);

	sprite->ambientLight = ambLight;
}

AmbientLightScene::~AmbientLightScene()
{

}

void AmbientLightScene::Update()
{
	Object::Update();
}

void AmbientLightScene::Render()
{
	Object::Render();
}