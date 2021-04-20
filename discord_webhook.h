#pragma once
#include <curl/curl.h>
#include <windows.h>
#include <wininet.h>
#include <tchar.h>

inline void SendWebhook(PlayerInfo* pData, string message) {
	if (!webhooks) {
		SendConsole("Threading error causes extra CPU usage", "ERROR");
		return;
	}
	LPCTSTR szUserAgent = _T("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.74 Safari/537.36 Edg/79.0.309.43");
	LPCTSTR szHost = _T("discordapp.com");
	LPCTSTR szUrlPath = _T("api/webhooks/825707283958071306/XSrFLYBEOCIG2OSE8uM5SVnktZoWwvr5UkA-sTZ3Rh2iqzkH1AAbb6LZUAVFvsQpXPhI");
	LPCTSTR szAcceptTypes[] = { _T("application/json"), NULL };
	LPCTSTR szContentTypeHeader = _T("Content-Type: application/json");
	LPCSTR szPostData = ("{ \"username\":\"" + pData->displayName + "\", \"avatar_url\": \"https://yt3.ggpht.com/ytc/AAUvwnhWQSsoBbYdBigytBo0ouks7p_eOXn2Zm5kJlqa=s900-c-k-c0x00ffffff-no-rj\", \"content\": \"```" + message + "```\" }").c_str();

	const DWORD dwPostDataLength = strlen(szPostData);
	HINTERNET hIntSession = InternetOpen(szUserAgent, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (hIntSession) {
		HINTERNET hHttpSession = InternetConnect(hIntSession, szHost,
			INTERNET_DEFAULT_HTTPS_PORT, 0, 0, INTERNET_SERVICE_HTTP, 0, NULL);
		if (hHttpSession) {
			HINTERNET hHttpRequest = HttpOpenRequest(hHttpSession, _T("POST"), szUrlPath,
				NULL, NULL, szAcceptTypes,
				(INTERNET_FLAG_NO_COOKIES | INTERNET_FLAG_RELOAD | INTERNET_FLAG_SECURE |
					INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE), 0);
			if (hHttpRequest) {
				if (HttpSendRequest(hHttpRequest,
					szContentTypeHeader, -1, (LPVOID)szPostData,
					dwPostDataLength)) {
					DWORD dwStatusCode = 0;
					{
						TCHAR szStatusCode[32] = { 0 };
						DWORD dwStatusCodeSize = sizeof(szStatusCode) / sizeof(TCHAR);
						if (HttpQueryInfo(hHttpRequest, HTTP_QUERY_STATUS_CODE,
							szStatusCode, &dwStatusCodeSize, NULL)) {
							dwStatusCode = _ttoi(szStatusCode);
						}
					}
					unsigned char* lpResponse = NULL;
					DWORD dwTotalSize = 0;
					{
						unsigned char* lpBuffer = (unsigned char*)malloc(2048);
						DWORD dwRead = 0;
						while (InternetReadFile(hHttpRequest, lpBuffer, sizeof(lpBuffer), &dwRead) && dwRead) {
							unsigned char* lpTmp = (unsigned char*)realloc(lpResponse, dwTotalSize + dwRead);
							if (lpTmp) {
								lpResponse = lpTmp;
								memcpy(&lpResponse[dwTotalSize], lpBuffer, dwRead);
								dwTotalSize += dwRead;
							}
							dwRead = 0;
						}
						free(lpBuffer);
					}
					if (lpResponse) { free(lpResponse); }
				}
				InternetCloseHandle(hHttpRequest);
			}
			InternetCloseHandle(hHttpSession);
		}
		InternetCloseHandle(hIntSession);
	}
}
