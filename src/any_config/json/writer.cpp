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

#include <tier0/bufferstring.h>
#include <tier0/keyvalues3.h>
#include <tier0/utlstring.h>

AnyConfig::SaveJSON_NoContext_t::SaveJSON_NoContext_t(const Save_Generic_t::Base_t &aInit)
 :  SaveJSON_NoContext_t({aInit.m_psMessage, aInit.COutput_t<CUtlBuffer *>::m_aData})
{
}

bool AnyConfig::SaveJSON_t::SaveJSON()
{
	return SaveKV3AsJSON(CSaveFrom_t<KeyValues3 *>::m_aData, 
	                     m_psMessage, 
	                     COutput_t<CUtlBuffer *>::m_aData);
}

bool AnyConfig::SaveJSON2_t::SaveJSON2()
{
	return SaveKV3AsJSON(CSaveFrom_t<KeyValues3 *>::m_aData, 
	                     m_psMessage, 
	                     COutput_t<CUtlString *>::m_aData);
}

bool AnyConfig::CJSONWriter::Save(const Save_Generic_t &aParams)
{
	return SaveJSON(aParams.To<SaveJSON_NoContext_t>());
}

bool AnyConfig::CJSONWriter::Save(const SaveToFile_Generic_t &aParams)
{
	static const char *s_pszMessageConcat[] = {"<", "Save", "  JSON", " to file", ": ", "Not supported now", ">"};

	CBufferStringGrowable<256> sMessage;

	sMessage.AppendConcat(sizeof(s_pszMessageConcat) / sizeof(*s_pszMessageConcat), s_pszMessageConcat, NULL);
	*aParams.m_psMessage = sMessage;

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
