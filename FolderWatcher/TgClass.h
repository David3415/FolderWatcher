#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <string>

class TgClass
{
public:
	static bool TgVoid();
	const std::string botToken;
	const std::string chatId;
	CURL* curl;
	CURLcode res;
};

