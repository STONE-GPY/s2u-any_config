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

#include <any_config/base/writer.hpp>

#include <tier1/keyvalues3.h>

bool AnyConfig::Save_t::Save()
{
	return SaveKV3(m_aEncoding, 
	               m_aFormat, 
	               CSaveFrom_t<KeyValues3 *>::m_aData, 
	               m_psMessage, 
	               COutput_t<CUtlBuffer *>::m_aData, 
	               m_uFlags);
}

bool AnyConfig::SaveToFile_t::SaveToFile()
{
	return SaveKV3ToFile(m_aEncoding, 
	                     m_aFormat, 
	                     m_aData, 
	                     m_psMessage, 
	                     m_pszFilename,
	                     m_pszPathID, 
	                     m_uFlags);
}

AnyConfig::CBaseWriter::CBaseWriter()
 :  CBase()
{
}


AnyConfig::CBaseWriter::CBaseWriter(KeyValues3 *pRoot)
 :  CBase(pRoot)
{
}

bool AnyConfig::CBaseWriter::Save(const Save_Generic_t &aParams)
{
	return const_cast<const CBaseWriter *>(this)->Save(aParams.ToBase());
}

bool AnyConfig::CBaseWriter::Save(const SaveToFile_Generic_t &aParams)
{
	return SaveToFile(aParams.ToBase());
}

bool AnyConfig::CBaseWriter::Save(const Save_NoContext_t &aParams) const
{
	return SaveKV3(aParams.m_aEncoding, 
	               aParams.m_aFormat, 
	               Get(), 
	               aParams.m_psMessage, 
	               aParams.COutput_t<CUtlBuffer *>::m_aData, 
	               aParams.m_uFlags);
}

bool AnyConfig::CBaseWriter::SaveToFile(const SaveToFile_NoContext_t &aParams) const
{
	return SaveKV3ToFile(aParams.m_aEncoding, 
	                     aParams.m_aFormat, 
	                     Get(), 
	                     aParams.m_psMessage, 
	                     aParams.m_pszFilename, 
	                     aParams.m_pszPathID, 
	                     aParams.m_uFlags);
}
