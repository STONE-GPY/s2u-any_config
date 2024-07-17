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

#include <any_config/json/reader.hpp>

#include <tier0/keyvalues3.h>
#include <tier0/utlbuffer.h>
#include <tier0/utlstring.h>

bool AnyConfig::LoadFromJSON_t::LoadFromJSON()
{
	return LoadKV3FromJSON(m_aContext, 
	                       m_psMessage, 
	                       m_aData, 
	                       m_pszName);
}

AnyConfig::LoadFromJSON_NoContext_t::LoadFromJSON_NoContext_t(const Load_Generic_t::Base_t &aInit)
{
	m_psMessage = aInit.m_psMessage;
	m_aData = (const char *)aInit.m_aData->Base();
	m_pszName = aInit.m_pszName;
}

bool AnyConfig::LoadFromJSONFile_t::LoadFromJSONFile()
{
	return LoadKV3FromJSONFile(m_aContext, 
	                           m_psMessage, 
	                           m_pszFilename, 
	                           m_pszPathID);
}

bool AnyConfig::CJSONReader::Load(const Load_Generic_t &aParams)
{
	return LoadFromJSON(aParams.To<LoadFromJSON_NoContext_t>());
}

bool AnyConfig::CJSONReader::Load(const LoadFromFile_Generic_t &aParams)
{
	CUtlString sError;

	sError = "<";
	sError += "Load";
	sError += " JSON";
	sError += " from file";
	sError += ": ";
	sError += "not supported now";
	sError += ">";

	*aParams.m_psMessage = sError;

	return false;
}

bool AnyConfig::CJSONReader::LoadFromJSON(const LoadFromJSON_NoContext_t &aParams)
{
	return LoadKV3FromJSON(Get(), 
	                       aParams.m_psMessage, 
	                       aParams.m_aData, 
	                       aParams.m_pszName);
}

bool AnyConfig::CJSONReader::LoadFromJSONFile(const LoadFromJSONFile_NoContext_t &aParams)
{
	return LoadKV3FromJSONFile(Get(), 
	                           aParams.m_psMessage, 
	                           aParams.m_pszFilename, 
	                           aParams.m_pszPathID);
}
