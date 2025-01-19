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

#include <any_config/keyvalues/writer.hpp>

#include <tier0/bufferstring.h>
#include <tier0/keyvalues3.h>
#include <tier0/utlstring.h>

bool AnyConfig::SaveAsKV1Text_t::SaveAsKV1Text()
{
	return SaveKV3AsKV1Text(m_aContext, 
	                        m_psMessage, 
	                        m_aData, 
	                        m_eBehavior);
}

AnyConfig::SaveAsKV1Text_NoContext_t::SaveAsKV1Text_NoContext_t(const Save_Generic_t::Base_t &aInit)
 :  SaveAsKV1Text_NoContext_t({aInit.m_psMessage, aInit.COutput_t<CUtlBuffer *>::m_aData, KV1TEXT_ESC_BEHAVIOR_UNK1})
{
}

bool AnyConfig::SaveAsKV1Text_Translated_t::SaveAsKV1Text_Translated()
{
	return SaveKV3AsKV1Text_Translated(m_aContext, 
	                                   m_psMessage, 
	                                   COutput_t<CUtlBuffer *>::m_aData, 
	                                   m_eBehavior, 
	                                   CKV1Proccessor_t<KV3ToKV1Translation_t *>::m_aData, 
	                                   m_aValue);
}

bool AnyConfig::CKeyValuesWriter::Save(const Save_Generic_t &aParams)
{
	return SaveAsKV1Text(aParams.To<SaveAsKV1Text_NoContext_t>());
}

bool AnyConfig::CKeyValuesWriter::Save(const SaveToFile_Generic_t &aParams)
{
	static const char *s_pszMessageConcat[] = {"<", "Save", " KeyValues", " to file", ": ", "Not supported now", ">"};

	CBufferStringN<256> sMessage;

	sMessage.AppendConcat(sizeof(s_pszMessageConcat) / sizeof(*s_pszMessageConcat), s_pszMessageConcat, NULL);
	*aParams.m_psMessage = sMessage;

	return false;
}

bool AnyConfig::CKeyValuesWriter::SaveAsKV1Text(const SaveAsKV1Text_NoContext_t &aParams) const
{
	return SaveKV3AsKV1Text(Get(), 
	                        aParams.m_psMessage, 
	                        aParams.m_aData, 
	                        aParams.m_eBehavior);
}

bool AnyConfig::CKeyValuesWriter::SaveAsKV1Text_Translated(const SaveAsKV1Text_Translated_NoContext_t &aParams) const
{
	return SaveKV3AsKV1Text_Translated(Get(), 
	                                   aParams.m_psMessage, 
	                                   aParams.COutput_t<CUtlBuffer *>::m_aData, 
	                                   aParams.m_eBehavior, 
	                                   aParams.CKV1Proccessor_t<KV3ToKV1Translation_t *>::m_aData, 
	                                   aParams.m_aValue);
}