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

bool AnyConfig::Load_t::Load()
{
	return LoadKV3(m_aContext, 
	               m_psMessage, 
	               m_aData, 
	               m_aFormat, 
	               m_pszName);
}

bool AnyConfig::Load2_t::Load()
{
	return LoadKV3(m_aContext, 
	               m_psMessage, 
	               m_aData, 
	               m_aFormat, 
	               m_pszName);
}

bool AnyConfig::Load3_t::Load()
{
	return LoadKV3(m_aContext, 
	               m_psMessage, 
	               m_aData, 
	               m_aFormat, 
	               m_pszName);
}

bool AnyConfig::LoadFromFile_t::LoadFromFile()
{
	return LoadKV3FromFile(m_aContext, 
	                       m_psMessage, 
	                       m_pszFilename, 
	                       m_pszPathID, 
	                       m_aFormat);
}

bool AnyConfig::LoadFromFile2_t::LoadFromFile()
{
	return LoadKV3FromFile(m_aContext, 
	                       m_psMessage, 
	                       m_pszFilename, 
	                       m_pszPathID, 
	                       m_aFormat);
}

bool AnyConfig::LoadNoHeader_t::LoadNoHeader()
{
	return LoadKV3Text_NoHeader(m_aContext, 
	                            m_psMessage, 
	                            m_aData, 
	                            m_aFormat, 
	                            m_pszName);
}

AnyConfig::CBaseReader::CBaseReader()
 :  CBase()
{
}

bool AnyConfig::CBaseReader::Load(const Load_Generic_t &aParams)
{
	return Load(aParams.ToBase());
}

bool AnyConfig::CBaseReader::Load(const LoadFromFile_Generic_t &aParams)
{
	return LoadFromFile(aParams.ToBase());
}

bool AnyConfig::CBaseReader::Load(const Load_NoContext_t &aParams)
{
	return LoadKV3(Get(), 
	               aParams.m_psMessage, 
	               aParams.m_aData, 
	               aParams.m_aFormat, 
	               aParams.m_pszName);
}

bool AnyConfig::CBaseReader::Load(const Load2_NoContext_t &aParams)
{
	return LoadKV3(Get(), 
	               aParams.m_psMessage, 
	               aParams.m_aData, 
	               aParams.m_aFormat, 
	               aParams.m_pszName);
}

bool AnyConfig::CBaseReader::Load(const Load3_NoContext_t &aParams)
{
	return LoadKV3(Get(), 
	               aParams.m_psMessage, 
	               aParams.m_aData, 
	               aParams.m_aFormat, 
	               aParams.m_pszName);
}

bool AnyConfig::CBaseReader::LoadFromFile(const LoadFromFile_NoContext_t &aParams)
{
	return LoadKV3FromFile(Get(), 
	                       aParams.m_psMessage, 
	                       aParams.m_pszFilename, 
	                       aParams.m_pszPathID, 
	                       aParams.m_aFormat);
}

bool AnyConfig::CBaseReader::LoadFromFile(const LoadFromFile2_NoContext_t &aParams)
{
	return LoadKV3FromFile(Get(), 
	                       aParams.m_psMessage, 
	                       aParams.m_pszFilename, 
	                       aParams.m_pszPathID, 
	                       aParams.m_aFormat);
}

bool AnyConfig::CBaseReader::LoadNoHeader(const LoadNoHeader_NoContext_t &aParams)
{
	return LoadKV3Text_NoHeader(Get(), 
	                            aParams.m_psMessage, 
	                            aParams.m_aData, 
	                            aParams.m_aFormat, 
	                            aParams.m_pszName);
}
