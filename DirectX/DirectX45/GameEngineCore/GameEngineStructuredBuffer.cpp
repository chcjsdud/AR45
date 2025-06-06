#include "PrecompileHeader.h"
#include "GameEngineStructuredBuffer.h"

std::map<std::string, std::map<int, std::shared_ptr < GameEngineStructuredBuffer>>> GameEngineStructuredBuffer::StructuredBufferRes;


GameEngineStructuredBuffer::GameEngineStructuredBuffer() 
{
}

GameEngineStructuredBuffer::~GameEngineStructuredBuffer() 
{
	Release();
}

void GameEngineStructuredBuffer::Release()
{
	if (nullptr != WriteBuffer)
	{
		WriteBuffer->Release();
		WriteBuffer = nullptr;
	}

	if (nullptr != ReadBuffer)
	{
		ReadBuffer->Release();
		ReadBuffer = nullptr;
	}

	if (nullptr != UnorderedAccessView)
	{
		UnorderedAccessView->Release();
		UnorderedAccessView = nullptr;
	}


	if (nullptr != ShaderResourceView)
	{
		ShaderResourceView->Release();
		ShaderResourceView = nullptr;
	}
}

void GameEngineStructuredBuffer::CreateResize(const D3D11_SHADER_BUFFER_DESC& _Desc, int Count, StructuredBufferType _Type, void* _StartData, bool _CPUAccess)
{
	if (false == IsInit)
	{
		ShaderDesc = _Desc;
		IsInit = true;
	}

	CreateResize(ShaderDesc.Size, Count, _Type, _StartData, _CPUAccess);
}

void GameEngineStructuredBuffer::CreateResize(size_t Count, StructuredBufferType _Type, void* _StartData /*= nullptr*/, bool _CPUAccess)
{
	CreateResize(DataSize, Count, _Type, _StartData, _CPUAccess);
}

void GameEngineStructuredBuffer::CreateResize(size_t _DataSize, size_t Count, StructuredBufferType _Type, void* _StartData/* = nullptr*/, bool _CPUAccess)
{
	if (0 == _DataSize)
	{
		MsgAssert("데이터 사이즈가 0인 구조화 버퍼를 만들수는 없습니다.");
	}

	DataSize = static_cast<int>(_DataSize);

	if (0 == Count)
	{
		return;
	}

	if (DataCount >= Count)
	{
		return;
	}

	Release();

	D3D11_BUFFER_DESC Desc;

	Desc.ByteWidth = DataSize * DataCount;
	DataCount = static_cast<int>(Count);

	BufferInfo.ByteWidth = DataSize * DataCount; // GPU 에 생성할 구조화 버퍼 메모리 크기(최소단위 ??)
	BufferInfo.StructureByteStride = DataSize; // 1개 크기도 넣어줘야 한다.

	CreateResize(BufferInfo, _Type, _StartData, _CPUAccess);
}

void GameEngineStructuredBuffer::CreateResize(const D3D11_BUFFER_DESC& _Data, StructuredBufferType _Type, void* _StartData, bool _CPUAccess)
{
	BufferInfo = _Data;

	BufferInfo.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
	BufferInfo.Usage = D3D11_USAGE_DEFAULT;

	DataType = _Type;

	switch (_Type)
	{
	case StructuredBufferType::SRV_ONLY:
		BufferInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		BufferInfo.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		BufferInfo.Usage = D3D11_USAGE_DYNAMIC;
		break;
	case StructuredBufferType::UAV_INC:
		// 컴퓨트 쉐이더에 들어가는 용도가 되면 CPU 쓰기 옵션이 불가능해진다.
		BufferInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS;
		BufferInfo.CPUAccessFlags = 0;
		BufferInfo.Usage = D3D11_USAGE_DEFAULT;
		break;
	default:
		break;
	}

	D3D11_SUBRESOURCE_DATA* StartDataPtr = nullptr;
	D3D11_SUBRESOURCE_DATA StartData = { 0 };
	if (nullptr != _StartData)
	{
		StartData.SysMemPitch = 0;
		StartData.SysMemSlicePitch = 0;
		StartData.pSysMem = _StartData;
		StartDataPtr = &StartData;
	}

	// 여기까지 하고 
	if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&BufferInfo, StartDataPtr, &Buffer))
	{
		MsgAssert("스트럭처드 버퍼 생성에 실패했습니다.");
	}

	// Shader Resource View
	// 쉐이더 리소스를 만드는데 버퍼기반 
	// D3D11_SRV_DIMENSION_BUFFEREX 버퍼기반 쉐이더 리소스 뷰라는것을 알려주기 위한 용도
	D3D11_SHADER_RESOURCE_VIEW_DESC tSRVDesc = {};
	tSRVDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFEREX;
	tSRVDesc.Format = DXGI_FORMAT_UNKNOWN;
	tSRVDesc.BufferEx.FirstElement = 0;
	tSRVDesc.BufferEx.Flags = 0;
	tSRVDesc.BufferEx.NumElements = DataCount; // 10개로 우리어진 m_pSRV를 넣어달라.

	if (S_OK != GameEngineDevice::GetDevice()->CreateShaderResourceView(Buffer, &tSRVDesc, &ShaderResourceView))
	{
		MsgAssert("FAIL (S_OK != GameEngineDevice::GetDevice()->CreateShaderResourceView(GetBuffer(), &tSRVDesc, &m_pSRV))");
	}

	if (_Type == StructuredBufferType::UAV_INC)
	{
		D3D11_UNORDERED_ACCESS_VIEW_DESC UAVDesc = {};
		UAVDesc.Buffer.NumElements = DataCount;
		UAVDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;

		if (S_OK != GameEngineDevice::GetDevice()->CreateUnorderedAccessView(Buffer, &UAVDesc, &UnorderedAccessView))
		{
			// 컴퓨트 쉐이더용 view
			MsgAssert("if (S_OK != GameEngineDevice::GetDevice()->CreateUnorderedAccessView(Buffer, &UAVDesc, &UnorderedAccessView))");
		}
	}

	if (_CPUAccess)
	{
		BufferInfo.ByteWidth = DataSize * DataCount;	// 버퍼 전체 크기
		BufferInfo.StructureByteStride = DataSize;		// 버퍼 요소 크기			
		BufferInfo.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED; // 구조화 버퍼 추가 플래그 설정
		BufferInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE;	// Texture Register Binding	

		BufferInfo.Usage = D3D11_USAGE_DYNAMIC;
		BufferInfo.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;


		if (GameEngineDevice::GetDevice()->CreateBuffer(&BufferInfo, nullptr, &WriteBuffer))
		{
			MsgAssert("if (GameEngineDevice::GetDevice()->CreateBuffer(&BufferInfo, nullptr, &WriteBuffer))");
		}


		BufferInfo.Usage = D3D11_USAGE_DEFAULT;
		BufferInfo.CPUAccessFlags = D3D11_CPU_ACCESS_READ;

		if (GameEngineDevice::GetDevice()->CreateBuffer(&BufferInfo, nullptr, &ReadBuffer))
		{
			MsgAssert("if (GameEngineDevice::GetDevice()->CreateBuffer(&BufferInfo, nullptr, &ReadBuffer))");
		}
	}
}


void GameEngineStructuredBuffer::ChangeData(const void* _Data, size_t _Size)
{
	// 512 라이트 데이터를 세팅해줄수 있는 버퍼를 만들었다고 하더라도
// 진짜 512개의 라이트를 세팅하는것은 아닐수가 있으므로
// 기존에 만든 세팅들이 사이드 이펙트가 생기지는 않겠지만
// 위험하니까 고려는 해둬야 할겁니다.

// 여기에서 실제 데이터를 세팅해주게 되는데.
#ifdef _DEBUG
	//if (m_BufferInfo.ByteWidth != _Size)
	//{
	//	GameEngineDebug::AssertMsg("if (m_BufferInfo.ByteWidth != _Size)");
	//}
	SettingResources.pData = nullptr;
#endif

	GameEngineDevice::GetContext()->Map(Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &SettingResources);

#ifdef _DEBUG
	if (nullptr == SettingResources.pData)
	{
		MsgAssert("if (nullptr == m_Res.pData)");
	}
#endif 

	const float4x4* Ptr = reinterpret_cast<const float4x4*>(_Data);

	float4x4 Test = *Ptr;

	memcpy_s(SettingResources.pData, BufferInfo.ByteWidth, _Data, _Size);

	GameEngineDevice::GetContext()->Unmap(Buffer, 0);
}


void GameEngineStructuredBuffer::VSReset(int _BindPoint)
{
	ID3D11ShaderResourceView* Nullptr = nullptr;

	GameEngineDevice::GetContext()->VSSetShaderResources(_BindPoint, 1, &Nullptr);
}
void GameEngineStructuredBuffer::PSReset(int _BindPoint)
{
	ID3D11ShaderResourceView* Nullptr = nullptr;

	GameEngineDevice::GetContext()->PSSetShaderResources(_BindPoint, 1, &Nullptr);
}

void GameEngineStructuredBuffer::GSReset(int _BindPoint)
{
	ID3D11ShaderResourceView* Nullptr = nullptr;
	GameEngineDevice::GetContext()->GSSetShaderResources(_BindPoint, 1, &Nullptr);
}

void GameEngineStructuredBuffer::CSReset(int _BindPoint)
{
	UINT i = -1;
	ID3D11UnorderedAccessView* Nullptr = nullptr;
	GameEngineDevice::GetContext()->CSSetUnorderedAccessViews(_BindPoint, 1, &Nullptr, &i);
}

void GameEngineStructuredBuffer::VSSetting(int _BindPoint)
{
	if (nullptr == ShaderResourceView)
	{
		MsgAssert("존재하지 않는 스트럭처드 버퍼를 사용할 수 없습니다.");
	}

	GameEngineDevice::GetContext()->VSSetShaderResources(_BindPoint, 1, &ShaderResourceView);
}

void GameEngineStructuredBuffer::CSRWSetting(int _BindPoint)
{
	if (nullptr == UnorderedAccessView)
	{
		MsgAssert("존재하지 않는 언 오더드 액세스 뷰를 를 사용할 수 없습니다.");
	}

	UINT i = -1;
	GameEngineDevice::GetContext()->CSSetUnorderedAccessViews(_BindPoint, 1, &UnorderedAccessView, &i);
}

void GameEngineStructuredBuffer::PSSetting(int _BindPoint)
{
	if (nullptr == ShaderResourceView)
	{
		MsgAssert("존재하지 않는 구조화 버퍼를 사용할 수 없습니다.");
	}

	GameEngineDevice::GetContext()->PSSetShaderResources(_BindPoint, 1, &ShaderResourceView);
}

void GameEngineStructuredBuffer::CSSetting(int _BindPoint)
{
	if (nullptr == ShaderResourceView)
	{
		MsgAssert("존재하지 않는 구조화 버퍼를 사용할 수 없습니다.");
	}

	GameEngineDevice::GetContext()->CSSetShaderResources(_BindPoint, 1, &ShaderResourceView);
}

void GameEngineStructuredBuffer::GSSetting(int _BindPoint)
{
	if (nullptr == ShaderResourceView)
	{
		MsgAssert("존재하지 않는 구조화 버퍼를 사용할 수 없습니다.");
	}

	GameEngineDevice::GetContext()->GSSetShaderResources(_BindPoint, 1, &ShaderResourceView);
}


void GameEngineStructuredBuffer::SetData(void* _pSrc, UINT _DataCount)
{
	// 공간이 모자라면 추가할당하면서 초기화한다.
	if (DataCount < _DataCount)
	{
		CreateResize(DataSize, _DataCount, DataType, _pSrc);
	}

	// 공간이 충분하다면, 데이터 전송
	else
	{
		D3D11_MAPPED_SUBRESOURCE tMapSub = {};

		GameEngineDevice::GetContext()->Map(WriteBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &tMapSub);
		memcpy(tMapSub.pData, _pSrc, DataSize * DataCount);
		GameEngineDevice::GetContext()->Unmap(WriteBuffer, 0);

		// 쓰기버퍼 -> 메인버퍼
		GameEngineDevice::GetContext()->CopyResource(Buffer, WriteBuffer);
	}
}