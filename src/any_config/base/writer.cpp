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

#include <tier0/keyvalues3.h>

bool AnyConfig::CBaseWriter::_Save(const Save_t &aParams)
{
	return SaveKV3(aParams.aEncoding, 
	               aParams.aFormat, 
	               aParams.CSaveFrom_t<KeyValues3 *>::aData, 
	               aParams.psMessage, 
	               aParams.COutput_t<CUtlBuffer *>::aData, 
	               aParams.uFlags);
}

bool AnyConfig::CBaseWriter::_SaveToFile(const SaveToFile_t &aParams)
{
	return SaveKV3ToFile(aParams.aEncoding, 
	                     aParams.aFormat, 
	                     aParams.aData, 
	                     aParams.psMessage, 
	                     aParams.pszFilename,
	                     aParams.pszPathID, 
	                     aParams.uFlags);
}

bool AnyConfig::CBaseWriter::Save(const SaveNoContext_t &aParams) const
{
	return SaveKV3(aParams.aEncoding, 
	               aParams.aFormat, 
	               Get(), 
	               aParams.psMessage, 
	               aParams.COutput_t<CUtlBuffer *>::aData, 
	               aParams.uFlags);
}

bool AnyConfig::CBaseWriter::SaveToFile(const SaveToFileNoContext_t &aParams) const
{
	return SaveKV3ToFile(aParams.aEncoding, 
	                     aParams.aFormat, 
	                     Get(), 
	                     aParams.psMessage, 
	                     aParams.pszFilename, 
	                     aParams.pszPathID, 
	                     aParams.uFlags);
}
