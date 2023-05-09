#include "PrecompileHeader.h"
#include "GameEngineActor.h"
#include "GameEngineComponent.h"

GameEngineActor::GameEngineActor() 
{
}

GameEngineActor::~GameEngineActor() 
{
}

void GameEngineActor::ComponentInit(std::shared_ptr<class GameEngineComponent> _Component)
{
	_Component->Actor = this;
	_Component->GetTransform()->SetParent(GetTransform());
	_Component->Start();

	ComponentsList.push_back(_Component);
}


void GameEngineActor::Release()
{
	GameEngineObject::Release();

	//std::list<std::shared_ptr<class GameEngineComponent>>::iterator ComStartIter = ComponentsList.begin();
	//std::list<std::shared_ptr<class GameEngineComponent>>::iterator ComEndIter = ComponentsList.end();

	//for (; ComStartIter != ComEndIter; )
	//{
	//	std::shared_ptr<class GameEngineComponent>& ComPtr = *ComStartIter;

	//	if (false == ComPtr->IsDeath())
	//	{
	//		++ComStartIter;
	//		continue;
	//	}

	//	ComStartIter = ComponentsList.erase(ComStartIter);
	//}

}