/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Source 2 util to read a config of any format.
 * Written by Wend4r (2024).
 * ======================================================

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <any_config.hpp>

#include <tier0/bufferstring.h>
#include <tier0/commonmacros.h>
#include <tier0/utlstring.h>

bool AnyConfig::Anyone::Load(const Load_Generic_t &aParams)
{
	AssertMsg(false, "Use an explicit conversion");

	static const char *s_pszMessageConcat[] = {"<", "Load", " Anyone", ": ", "Use an explicit conversion", ">"};

	CBufferStringGrowable<256> sMessage;

	sMessage.AppendConcat(ARRAYSIZE(s_pszMessageConcat), s_pszMessageConcat, NULL);
	*aParams.m_psMessage = sMessage;

	return false;
}

bool AnyConfig::Anyone::Load(const LoadFromFile_Generic_t &aParams)
{
	const char *pszFilename = aParams.m_pszFilename;

	if(Base::m_aCheckFileExtension.Check(pszFilename))
	{
		return Base::Load(aParams);
	}
	else if(JSON::m_aCheckFileExtension.Check(pszFilename))
	{
		return JSON::Load(aParams);
	}
	else if(KeyValues::m_aCheckFileExtension.Check(pszFilename))
	{
		return KeyValues::Load(aParams);
	}

	const char *pszMessageConcat[] = {"<", "Load", " Anyone", " from file", ": ", "Unknown file extension", " of ", "\"", pszFilename, "\"", ">"};

	CBufferStringGrowable<256 + MAX_PATH> sMessage;

	sMessage.AppendConcat(ARRAYSIZE(pszMessageConcat), pszMessageConcat, NULL);
	*aParams.m_psMessage = sMessage;

	return false;
}

bool AnyConfig::Anyone::Save(const Save_Generic_t &aParams)
{
	AssertMsg(false, "Use an explicit conversion");

	static const char *s_pszMessageConcat[] = {"<", "Save", " Anyone", ": ", "Use an explicit conversion", ">"};

	CBufferStringGrowable<256> sMessage;

	sMessage.AppendConcat(ARRAYSIZE(s_pszMessageConcat), s_pszMessageConcat, NULL);
	*aParams.m_psMessage = sMessage;

	return false;
}

bool AnyConfig::Anyone::Save(const SaveToFile_Generic_t &aParams)
{
	const char *pszFilename = aParams.m_pszFilename;

	if(Base::m_aCheckFileExtension.Check(pszFilename))
	{
		return Base::Save(aParams);
	}
	else if(JSON::m_aCheckFileExtension.Check(pszFilename))
	{
		return JSON::Save(aParams);
	}
	else if(KeyValues::m_aCheckFileExtension.Check(pszFilename))
	{
		return KeyValues::Save(aParams);
	}

	const char *pszMessageConcat[] = {"<", "Save", "  Anyone", " to file", ": ", "Unknown file extension", " of ", "\"", pszFilename, "\"", ">"};

	CBufferStringGrowable<256 + MAX_PATH> sMessage;

	sMessage.AppendConcat(ARRAYSIZE(pszMessageConcat), pszMessageConcat, NULL);
	*aParams.m_psMessage = sMessage;

	return false;
}
