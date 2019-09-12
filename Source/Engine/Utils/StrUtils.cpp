#include "StrUtils.h"

#include <algorithm> 
#include <cctype>
#include <locale>
#include<regex>
#include <sstream>

#ifndef WIN32
extern "C" {
    #include <strings.h>
}
#endif

int StrUtils::unicodeStrLen(std::string str)
{
	int len = 0;

	for (auto it = str.begin(); it != str.end(); it++)
	{
		len += (*it & 0xc0) != 0x80;
	}

	return len;
}

std::string StrUtils::ltrim(std::string str, std::string toRemove, bool ignoreCase)
{
	while(StrUtils::startsWith(str, toRemove, ignoreCase))
	{
		str = str.substr(toRemove.size());
	}

	return str;
}

std::string StrUtils::rtrim(std::string str, std::string toRemove, bool ignoreCase)
{
	while (StrUtils::endsWith(str, toRemove, ignoreCase))
	{
		str = str.substr(0, str.size() - toRemove.size());
	}

	return str;
}

std::string StrUtils::trim(std::string str, std::string toRemove, bool ignoreCase)
{
	str = StrUtils::ltrim(str, toRemove, ignoreCase);
	str = StrUtils::rtrim(str, toRemove, ignoreCase);

	return str;
}

std::string StrUtils::toStringZeroPad(int value, int zeroCount)
{
	std::string result = std::to_string(value);

	while (result.length() < zeroCount)
	{
		result = "0" + result;
	}

	return result;
}

std::string StrUtils::quote(std::string value)
{
	return "\"" + value + "\"";
}

std::vector<std::string> StrUtils::tokenize(std::string str, std::string delimiters)
{
	std::vector<std::string> tokens = std::vector<std::string>();

	// Skip delimiters at beginning
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);

	// Find first non-delimiter
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	// Insert leading delimiter token
	if (pos != std::string::npos && lastPos != std::string::npos && lastPos > 0)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
	}

	while (pos != std::string::npos || pos != lastPos)
	{
		// Found a standard token, add it to the vector
		tokens.push_back(str.substr(lastPos, pos - lastPos));

		// Skip delimiters
		lastPos = str.find_first_not_of(delimiters, pos);

		// Insert delimiter token
		if (lastPos != std::string::npos && pos != std::string::npos)
		{
			tokens.push_back(str.substr(pos, lastPos - pos));
		}

		// Find next non-delimiter
		pos = str.find_first_of(delimiters, lastPos);
	}

	// Insert trailing delimter token
	pos = str.find_last_of(delimiters);

	if (pos != std::string::npos && str.find_first_not_of(delimiters, pos) == std::string::npos)
	{
		// Adjust start position to start of trailing delimiter span
		pos = str.find_last_not_of(delimiters, pos);

		if (pos == std::string::npos)
		{
			pos = 0;
		}
		else
		{
			pos += 1;
		}

		tokens.push_back(str.substr(pos, str.size() - pos));
	}

	return tokens;
}

std::vector<std::string> StrUtils::splitOn(std::string str, std::string delimiters, bool keepDelimiters)
{
	std::vector<std::string> tokens = std::vector<std::string>();

	size_t start = 0U;
	size_t end = str.find_first_of(delimiters);

	while (end != std::string::npos)
	{
		int length = end - start;

		if (length > 0)
		{
			std::string next = str.substr(start, end - start);
			tokens.push_back(next);
		}

		if (keepDelimiters)
		{
			std::string delim = str.substr(end, 1);
			tokens.push_back(delim);
		}

		start = end + 1;
		end = str.find_first_of(delimiters, start);
	}

	std::string next = str.substr(start, end);

	if (next != "")
	{
		tokens.push_back(next);
	}

	return tokens;
}

bool StrUtils::isInteger(std::string  str)
{
	if (StrUtils::startsWith(str, "-", false))
	{
		str = str.substr(1, str.size() - 1);
	}

	return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

bool StrUtils::isFloat(std::string str)
{
	std::istringstream iss(str);
	float f;

	iss >> std::noskipws >> f;

	return iss.eof() && !iss.fail();
}

bool StrUtils::isHexNumber(std::string str)
{
	if (StrUtils::startsWith(str, "0x", false))
	{
		str = str.substr(2, str.size() - 2);
		return !str.empty() && str.find_first_not_of("0123456789abcdefABCDEF") == std::string::npos;
	}

	return false;
}

int StrUtils::HexToInt(std::string str)
{
	if (StrUtils::startsWith(str, "0x", false))
	{
		str = str.substr(2, str.size() - 2);
	}

    int result;
    std::stringstream stream;

	stream << str;

    stream >> std::hex >> result;
    
	return result;
}

bool StrUtils::startsWith(std::string str, std::string prefix, bool ignoreCase)
{
	if (str.size() >= prefix.size())
	{
		std::string stringStart = str.substr(0, prefix.size());

		if (ignoreCase)
		{
			#ifdef _WIN32
				if (stricmp(stringStart.c_str(), prefix.c_str()) == 0)
				{
					return true;
				}
			#else
				if (strcasecmp(stringStart.c_str(), prefix.c_str()) == 0)
				{
					return true;
				}
			#endif
		}

		if (stringStart == prefix)
		{
			return true;
		}
	}

	return false;
}

bool StrUtils::endsWith(std::string str, std::string suffix, bool ignoreCase)
{
	if (str.size() >= suffix.size())
	{
		std::string stringEnd = str.substr(str.size() - suffix.size(), suffix.size());

		if (ignoreCase)
		{
			#ifdef _WIN32
				if (stricmp(stringEnd.c_str(), suffix.c_str()) == 0)
				{
					return true;
				}
			#else
				if (strcasecmp(stringEnd.c_str(), suffix.c_str()) == 0)
				{
					return true;
				}
			#endif
		}

		if (stringEnd == suffix)
		{
			return true;
		}
	}

	return false;
}

bool StrUtils::contains(const std::string& str, const std::string & toFind, bool ignoreCase)
{
	auto it = std::search(str.begin(), str.end(), toFind.begin(), toFind.end(),
		[=](char ch1, char ch2)
		{
			return ignoreCase ? (std::toupper(ch1) == std::toupper(ch2)) : (ch1 == ch2);
		}
	);

	return (it != str.end());
}

bool StrUtils::isRegexMatch(const std::string str, const std::string regex)
{
	std::regex re = std::regex(regex);
	std::smatch match;

	if (std::regex_match(str, match, re))
	{
		return true;
	}

	return false;
}

bool StrUtils::isRegexSubMatch(const std::string str, const std::string regex)
{
	std::regex re = std::regex(regex);
	std::smatch match;

	if (std::regex_search(str, match, re))
	{
		return true;
	}

	return false;
}

std::string StrUtils::replaceAll(std::string str, const std::string& from, const std::string& to)
{
	size_t start_pos = 0;

	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}

	return str;
}

std::basic_string<char> StrUtils::replaceFirstOccurence(std::basic_string<char> str, const std::basic_string<char>& from, const std::basic_string<char>& to)
{
	size_t start_pos = 0;

	if ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}

	return str;
}
