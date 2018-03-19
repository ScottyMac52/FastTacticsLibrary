#include "stdafx.h"
#include "ErrorProcesser.h"

ErrorProcesser::ErrorProcesser()
{
}

ErrorProcesser::~ErrorProcesser()
{
}

std::wstring ErrorProcesser::GetLastErrorAsString(DWORD lastError)
{
	if (lastError == 0)
		return std::wstring(L"No error"); //No error message has been recorded

	LPWSTR messageBuffer = nullptr;
	size_t size = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, lastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&messageBuffer, 0, NULL);

	std::wstring message(messageBuffer, size);

	//Free the buffer.
	LocalFree(messageBuffer);

	return message;
}