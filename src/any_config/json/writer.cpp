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
#include <tier0/utlstring.h>

AnyConfig::SaveJSON_NoContext_t::SaveJSON_NoContext_t(const Save_General_t::Base_t &aInit)
{
	m_psMessage = aInit.m_psMessage;
	COutput_t<CUtlBuffer *>::m_aData = aInit.COutput_t<CUtlBuffer *>::m_aData;
}

bool AnyConfig::CJSONWriter::_SaveJSON(const SaveJSON_t &aParams)
{
	return SaveKV3AsJSON(aParams.CSaveFrom_t<KeyValues3 *>::m_aData, 
	                     aParams.m_psMessage, 
	                     aParams.COutput_t<CUtlBuffer *>::m_aData);
}

bool AnyConfig::CJSONWriter::_SaveJSON(const SaveJSON2_t &aParams)
{
	return SaveKV3AsJSON(aParams.CSaveFrom_t<KeyValues3 *>::m_aData, 
	                     aParams.m_psMessage, 
	                     aParams.COutput_t<CUtlString *>::m_aData);
}

bool AnyConfig::CJSONWriter::Save(const Save_General_t &aParams)
{
	return SaveJSON(aParams.To<SaveJSON_NoContext_t>());
}

bool AnyConfig::CJSONWriter::Save(const SaveToFile_General_t &aParams)
{
	CUtlString sError;

	sError = "<";
	sError += "Save";
	sError += " JSON";
	sError += " to file";
	sError += ": ";
	sError += "not supported now";
	sError += ">";

	aParams.m_psMessage->Set(sError.Get());

	return false;
}

bool AnyConfig::CJSONWriter::SaveJSON(const SaveJSON_NoContext_t &aParams) const
{
	return SaveKV3AsJSON(Get(), 
	                     aParams.m_psMessage, 
	                     aParams.COutput_t<CUtlBuffer *>::m_aData);
}

bool AnyConfig::CJSONWriter::SaveJSON(const SaveJSON2_NoContext_t &aParams) const
{
	return SaveKV3AsJSON(Get(), 
	                     aParams.m_psMessage, 
	                     aParams.COutput_t<CUtlString *>::m_aData);
}
