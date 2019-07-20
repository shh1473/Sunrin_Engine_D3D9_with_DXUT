#include "DXUT.h"
#include "ObjectScene.h"

ObjectScene::ObjectScene()
{
	object01 = new Object();
	AddChild(object01);

	object02 = new Object();
	//AddChild(object02);
	object01->AddChild(object02);
}

ObjectScene::~ObjectScene()
{

}

void ObjectScene::Update()
{
	Object::Update();
}

void ObjectScene::Render()
{
	Object::Render();
}