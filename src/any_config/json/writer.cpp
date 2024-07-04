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

#include <any_config/json/writer.hpp>

#include <tier0/keyvalues3.h>

bool AnyConfig::CJSONWriter::_SaveJSON(const SaveJSON_t &aParams)
{
	return SaveKV3AsJSON(aParams.CSaveFrom_t<KeyValues3 *>::aData, 
	                     aParams.psMessage, 
	                     aParams.COutput_t<CUtlBuffer *>::aData);
}

bool AnyConfig::CJSONWriter::_SaveJSON(const SaveJSON2_t &aParams)
{
	return SaveKV3AsJSON(aParams.CSaveFrom_t<KeyValues3 *>::aData, 
	                     aParams.psMessage, 
	                     aParams.COutput_t<CUtlString *>::aData);
}

bool AnyConfig::CJSONWriter::SaveJSON(const SaveJSON_NoContext_t &aParams) const
{
	return SaveKV3AsJSON(Get(), 
	                     aParams.psMessage, 
	                     aParams.COutput_t<CUtlBuffer *>::aData);
}

bool AnyConfig::CJSONWriter::SaveJSON(const SaveJSON2_NoContext_t &aParams) const
{
	return SaveKV3AsJSON(Get(), 
	                     aParams.psMessage, 
	                     aParams.COutput_t<CUtlString *>::aData);
}
