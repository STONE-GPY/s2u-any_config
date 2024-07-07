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

bool AnyConfig::CJSONReader::_LoadFromJSON(const LoadFromJSON_t &aParams)
{
	return LoadKV3FromJSON(aParams.m_aContext, 
	                       aParams.m_psMessage, 
	                       aParams.m_aData, 
	                       aParams.m_pszName);
}

bool AnyConfig::CJSONReader::_LoadFromJSONFile(const LoadFromJSONFile_t &aParams)
{
	return LoadKV3FromJSONFile(aParams.m_aContext, 
	                           aParams.m_psMessage, 
	                           aParams.m_pszFilename, 
	                           aParams.m_pszPathID);
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
