#include "PrecompileHeader.h"
#include "ServerWindow.h"
#include "ConnectIDPacket.h"
#include "ObjectUpdatePacket.h"
#include "Player.h"
#include "ConnectIDPacket.h"

GameEngineNet* ServerWindow::NetInst = nullptr;

ServerWindow::ServerWindow() 
{
	IP.resize(1024);
	TestSendBuffer.resize(1024);
}

ServerWindow::~ServerWindow() 
{
}

void ServerWindow::Start()
{

}

void ServerWindow::OnGUI(std::shared_ptr<GameEngineLevel> Level, float _DeltaTime)
{
	// IP.resize(128);
	// ImGui::PushID(1312321);
	std::string Text = "������ �������Դϴ�.";

	if (true == IsServer)
	{
		ImGui::Text(GameEngineString::AnsiToUTF8(Text).c_str());
		
		// ó���ϸ� ��������.
		ImGui::PushID(321312321);
		ImGui::InputText(Text.c_str(), &TestSendBuffer[0], TestSendBuffer.size());
		ImGui::PopID();

		ImGui::PushID(33333121);
		Text = "SendTest";
		if (ImGui::Button(GameEngineString::AnsiToUTF8(Text).c_str()))
		{
			size_t StrLen = strlen(TestSendBuffer.c_str());
			NetInst->Send(&TestSendBuffer[0], static_cast<unsigned int>(StrLen));
		}
		ImGui::PopID();


		return;
	}

	Text = "Ŭ��� �������Դϴ�.";
	if (true == IsClient)
	{
		ImGui::Text(GameEngineString::AnsiToUTF8(Text).c_str());
		Text = "SendTest";

		// ó���ϸ� ��������.
		ImGui::PushID(321312321);
		ImGui::InputText(Text.c_str(), &TestSendBuffer[0], TestSendBuffer.size());
		ImGui::PopID();

		ImGui::PushID(33333121);
		Text = "SendTest";
		if (ImGui::Button(GameEngineString::AnsiToUTF8(Text).c_str()))
		{
			size_t StrLen = strlen(TestSendBuffer.c_str());

			// TestSendBuffer = Arr;
			NetInst->Send(&TestSendBuffer[0], static_cast<unsigned int>(StrLen));
		}
		ImGui::PopID();

		return;
	}



	Text = "Port : ";
	ImGui::InputInt(Text.c_str(), &Port);
	Text = "ȣ��Ʈ �ϱ�";
	if (ImGui::Button(GameEngineString::AnsiToUTF8(Text).c_str()))
	{
		SetThreadDescription(GetCurrentThread(), L"Server Main Thread");

		ServerPacketInit(&Server);
		Server.ServerOpen(static_cast<unsigned short>(Port));
		ServerInit(Level);
		Player::MainPlayer->InitNetObject(GameEngineNetObject::CreateServerID(), &Server);


		IsServer = true;


		NetInst = &Server;

	}

	Text = "IP : ";
	// IP.resize(128);
	// ImGui::PushID(1312321);
	ImGui::InputText(Text.c_str(), &IP[0], IP.size());
	// ImGui::PopID();

	Text = "Ŭ���̾�Ʈ�� �����ϱ�";
	if (ImGui::Button(GameEngineString::AnsiToUTF8(Text).c_str()))
	{
		SetThreadDescription(GetCurrentThread(), L"Client Main Thread");
		ClientPacketInit(&Client);
		IsClient = Client.Connect(IP, static_cast<unsigned short>(Port));
		NetInst = &Client;
	}

}

void ServerWindow::ServerInit(std::shared_ptr<GameEngineLevel> Level)
{
	Server.SetAcceptCallBack(
		[=](SOCKET _Socket, GameEngineNetServer* _Server)
		{
			// ������ ������Ը� ������ �Ѵ�.
			std::shared_ptr<ConnectIDPacket> Packet = std::make_shared<ConnectIDPacket>();

			int ID = GameEngineNetObject::CreateServerID();
			Packet->SetObjectID(ID);

			GameEngineSerializer Ser;
			Packet->SerializePacket(Ser);

			_Server->AddUser(ID, _Socket);

			// �����ϰ� �ѹ� �� ���� ������ �Ἥ �������Ҷ�.
			GameEngineNet::Send(_Socket, Ser.GetConstCharPtr(), Ser.GetWriteOffSet());
		}
	);

}

void ServerWindow::ServerPacketInit(GameEngineNetServer* _Net)
{
	_Net->Dispatcher.AddHandler<ObjectUpdatePacket>(
		[=](std::shared_ptr<ObjectUpdatePacket> _Packet)
		{
			if (false == GameEngineNetObject::IsNetObject(_Packet->GetObjectID()))
			{
				GameEngineLevel* LevelPtr = GetLevel();

				std::shared_ptr<Player> NewPlayer = GetLevel()->CreateActor<Player>();
				NewPlayer->InitNetObject(_Packet->GetObjectID(), _Net);
			}

			GameEngineNetObject::PushNetObjectPacket(_Packet);

			_Net->SendPacket(_Packet, _Packet->GetObjectID());
		}
	);

}

void ServerWindow::ClientPacketInit(GameEngineNetClient* _Net)
{
	_Net->Dispatcher.AddHandler<ConnectIDPacket>(
		[=](std::shared_ptr<ConnectIDPacket> _Packet)
		{
			// �̼��� �����÷��̾ ����� ����
			// ������ �����÷��̾ ������ �̴ϼȶ����� ��Ű��.
			Player::MainPlayer->InitNetObject(_Packet->GetObjectID(), ServerWindow::NetInst);
		}
	);

	_Net->Dispatcher.AddHandler<ObjectUpdatePacket>(
		[=](std::shared_ptr<ObjectUpdatePacket> _Packet)
		{
			if (false == GameEngineNetObject::IsNetObject(_Packet->GetObjectID()))
			{
				GameEngineLevel* LevelPtr = GetLevel(); 

				std::shared_ptr<Player> NewPlayer = GetLevel()->CreateActor<Player>();
				NewPlayer->InitNetObject(_Packet->GetObjectID(), _Net);
			}

			GameEngineNetObject::PushNetObjectPacket(_Packet);
		}
	);

}