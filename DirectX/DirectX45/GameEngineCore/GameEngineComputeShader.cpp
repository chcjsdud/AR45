#include "PrecompileHeader.h"
#include "GameEngineComputeShader.h"

GameEngineComputeShader::GameEngineComputeShader() 
: m_iGroupX(0)
, m_iGroupY(0)
, m_iGroupZ(0)
, m_iGroupPerThreadX(0)
, m_iGroupPerThreadY(0)
, m_iGroupPerThreadZ(0)
{
	Type = ShaderType::Compute;
}

GameEngineComputeShader::~GameEngineComputeShader() 
{
	if (nullptr != ShaderPtr)
	{
		ShaderPtr->Release();
	}
}


void GameEngineComputeShader::ShaderLoad(const std::string_view& _Path, const std::string_view& _EntryPoint, UINT _VersionHigh /*= 5*/, UINT _VersionLow /*= 0*/)
{
	CreateVersion("cs", _VersionHigh, _VersionLow);
	SetEntryPoint(_EntryPoint);

	unsigned int Flag = 0;

#ifdef _DEBUG
	Flag = D3D10_SHADER_DEBUG;
#endif

	// ������� �Ҷ� �̿ɼ��� ������ �ֽ��ϴ�.
	Flag |= D3DCOMPILE_PACK_MATRIX_ROW_MAJOR;

	ID3DBlob* Error;

	std::wstring UniCodePath = GameEngineString::AnsiToUniCode(_Path);

	if (S_OK != D3DCompileFromFile
	(
		UniCodePath.c_str(),
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE,
		EntryPoint.c_str(),
		Version.c_str(),
		Flag,
		0,
		&BinaryCode,
		&Error
	)
		)
	{

		// ������ �ؽ�Ʈ�� �˷��ݴϴ�.
		std::string ErrorString = reinterpret_cast<char*>(Error->GetBufferPointer());
		MsgAssert(ErrorString);
		return;
	}

	if (S_OK != GameEngineDevice::GetDevice()->CreateComputeShader
	(
		BinaryCode->GetBufferPointer(),
		BinaryCode->GetBufferSize(),
		nullptr,
		&ShaderPtr
	)
		)
	{
		MsgAssert("������Ʈ�� ���̴� �ڵ� ������ �����߽��ϴ�");
	}

	ShaderResCheck();
}