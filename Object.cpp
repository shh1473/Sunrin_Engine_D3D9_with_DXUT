#include "DXUT.h"
#include "Object.h"

Object::Object() :
	isDestroyed(false),
	isActivated(true),
	width(0.0f),
	height(0.0f),
	rect(),
	translation(0.0f, 0.0f, 0.0f),
	rotation(0.0f, 0.0f, 0.0f),
	scaling(1.0f, 1.0f, 1.0f),
	parent(nullptr)
{
	D3DXMatrixIdentity(&worldMatrix);
}

Object::~Object()
{
	for (auto iter : children)
	{
		SAFE_DELETE(iter);
	}
}

void Object::Update()
{
	// �ڽĵ� ���� ������Ʈ
	for (auto iter : children)
	{
		if (iter->isActivated)
		{
			iter->Update();
		}
	}

	// ������Ʈ���� �ı��� �ڽĵ� ����
	children.erase(remove_if(children.begin(), children.end(), [](Object *child)
	{
		if (child->isDestroyed) { SAFE_DELETE(child); return true; }
		else { return false; }
	}), children.end());

	// ���� ��Ʈ���� ������Ʈ
	UpdateMatrix();

	if (parent)
	{
		D3DXMatrixMultiply(&worldMatrix, &worldMatrix, &parent->worldMatrix);
	}

	// �簢 ���� ������Ʈ
	rect.left = translation.x - width * 0.5f;
	rect.top = translation.y + height * 0.5f;
	rect.right = translation.x + width * 0.5f;
	rect.bottom = translation.y - height * 0.5f;
}

void Object::Render()
{
	for (auto iter : children)
	{
		if (iter->isActivated)
		{
			iter->Render();
		}
	}
}

void Object::UpdateMatrix()
{
	static D3DXMATRIX translationMatrix;
	static D3DXMATRIX rotationMatrix;
	static D3DXMATRIX scalingMatrix;

	D3DXMatrixTranslation(&translationMatrix, translation.x, translation.y, translation.z);
	D3DXMatrixRotationYawPitchRoll(&rotationMatrix, D3DXToRadian(rotation.y), D3DXToRadian(rotation.x), D3DXToRadian(rotation.z));
	D3DXMatrixScaling(&scalingMatrix, scaling.x, scaling.y, scaling.z);

	D3DXMatrixMultiply(&worldMatrix, &scalingMatrix, &rotationMatrix);
	D3DXMatrixMultiply(&worldMatrix, &worldMatrix, &translationMatrix);
}

void Object::AddChild(Object *child)
{
	children.push_back(child);

	child->parent = this;
}