#include "PrecompileHeader.h"
#include "GameEngineNetObject.h"

std::atomic<int> GameEngineNetObject::AtomicObjectID;
std::mutex GameEngineNetObject::ObjectLock;
std::map<int, GameEngineNetObject*> GameEngineNetObject::AllNetObjects;

GameEngineNetObject::GameEngineNetObject() 
{
}

GameEngineNetObject::~GameEngineNetObject() 
{
}



// ������ ������ �ްڴٴ°�
void GameEngineNetObject::InitServerObject(GameEngineNet* _Net)
{
	ObjectID = ++AtomicObjectID;
	ObjectLock.lock();
	AllNetObjects.insert(std::pair<int, GameEngineNetObject*>(ObjectID, this));
	ObjectLock.unlock();

	Net = _Net;
}

void GameEngineNetObject::InitClientObject(int _ObjectID, GameEngineNet* _Net)
{
	ObjectID = _ObjectID;
	ObjectLock.lock();
	AllNetObjects.insert(std::pair<int, GameEngineNetObject*>(ObjectID, this));
	ObjectLock.unlock();

	Net = _Net;
}