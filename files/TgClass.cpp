#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <curl/curl.h>
#include "TgClass.h"
#include "TranslitClass.h"

extern std::wstring wstringForTg;

bool TgClass::TgVoid() {


	//std::string pathSlovar = "c:\\Users\\AlaniaDesign4\\Documents\\ansiSlovar.txt";
	std::string pathSlovar = "ansiSlovar.txt";
	const std::string botToken = "////////////////token";
	const std::string chatId = ""YOUR_CHAT_ID""; // Çàìåíèòå "YOUR_CHAT_ID" íà èäåíòèôèêàòîð ÷àòà 968221257

	CURL* curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);
	const wchar_t* temp = new wchar_t[250] {};
	std::string u8str;

	while (true) {
		if (wstringForTg != temp) {
			temp = wstringForTg.c_str();
			std::wcout << '\n' << "temp: " << wcslen(temp) << '\n';
			std::wcout << "wstringForTg: " << wstringForTg << '\n';
			size_t _size = (wcslen(temp) + 1) * sizeof(wchar_t);
			size_t convertedSize;
			size_t _count{};
			char* stringForTg = new char[_size];

			wcstombs_s(&convertedSize, stringForTg, _size, temp, _size);
			std::cout << "stringForTg: " << stringForTg << '\n';

			u8str = TranslitClass::TranslitVoid(stringForTg, pathSlovar);

			delete[]stringForTg;
			curl = curl_easy_init();
			if (curl) {
				std::string url = "https://api.telegram.org/bot" + botToken + "/sendMessage";
				std::string message = "New file: ";message.append(u8str);// .c_str();
				std::string postData = "chat_id=" + chatId + "&text=" + curl_easy_escape(curl, message.c_str(), message.length());

				curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
				curl_easy_setopt(curl, CURLOPT_HTTPHEADER, NULL);

				res = curl_easy_perform(curl);
				if (res != CURLE_OK) {
					std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
				}
				curl_easy_cleanup(curl);
			}

			curl_global_cleanup();
			wstringForTg = L"";
			temp = L"";
		}
		Sleep(8000);
	}
	delete[]temp;

	return true;

};
