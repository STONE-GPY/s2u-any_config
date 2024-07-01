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

#include <any_config/base/reader.hpp>

#include <tier0/keyvalues3.h>

bool AnyConfig::CBaseReader::_Load(const Load_t &aParams)
{
	return LoadKV3(aParams.aContext, 
	               aParams.psMessage, 
	               aParams.aData, 
	               aParams.aFormat, 
	               aParams.pszName);
}

bool AnyConfig::CBaseReader::_Load(const Load2_t &aParams)
{
	return LoadKV3(aParams.aContext, 
	               aParams.psMessage, 
	               aParams.aData, 
	               aParams.aFormat, 
	               aParams.pszName);
}

bool AnyConfig::CBaseReader::_Load(const Load3_t &aParams)
{
	return LoadKV3(aParams.aContext,
	               aParams.psMessage, 
	               aParams.aData, 
	               aParams.aFormat, 
	               aParams.pszName);
}

bool AnyConfig::CBaseReader::_LoadFromFile(const LoadFromFile_t &aParams)
{
	return LoadKV3FromFile(aParams.aContext, 
	                       aParams.psMessage, 
	                       aParams.pszFilename, 
	                       aParams.pszPathID, 
	                       aParams.aFormat);
}

bool AnyConfig::CBaseReader::_LoadFromFile(const LoadFromFile2_t &aParams)
{
	return LoadKV3FromFile(aParams.aContext, 
	                       aParams.psMessage, 
	                       aParams.pszFilename, 
	                       aParams.pszPathID, 
	                       aParams.aFormat);
}

bool AnyConfig::CBaseReader::_LoadNoHeader(const LoadNoHeader_t &aParams)
{
	return LoadKV3Text_NoHeader(aParams.aContext, 
	                            aParams.psMessage, 
	                            aParams.aData, 
	                            aParams.aFormat, 
	                            aParams.pszName);
}
