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

#include <tier0/keyvalues3.h>

bool AnyConfig::CKeyValuesWriter::_SaveAsKV1Text(const SaveAsKV1Text_t &aParams)
{
	return SaveKV3AsKV1Text(aParams.aContext, 
	                        aParams.psMessage, 
	                        aParams.aData, 
	                        aParams.eBehavior);
}

bool AnyConfig::CKeyValuesWriter::_SaveAsKV1Text_Translated(const SaveAsKV1Text_Translated_t &aParams)
{
	return SaveKV3AsKV1Text_Translated(aParams.aContext, 
	                                   aParams.psMessage, 
	                                   aParams.COutput_t<CUtlBuffer *>::aData, 
	                                   aParams.eBehavior, 
	                                   aParams.CKV1Proccessor_t<KV3ToKV1Translation_t *>::aData, 
	                                   aParams.aValue);
}

bool AnyConfig::CKeyValuesWriter::SaveAsKV1Text(const SaveAsKV1Text_NoContext_t &aParams)
{
	return SaveKV3AsKV1Text(Get(), 
	                        aParams.psMessage, 
	                        aParams.aData, 
	                        aParams.eBehavior);
}

bool AnyConfig::CKeyValuesWriter::SaveAsKV1Text_Translated(const SaveAsKV1Text_Translated_NoContext_t &aParams)
{
	return SaveKV3AsKV1Text_Translated(Get(), 
	                                   aParams.psMessage, 
	                                   aParams.COutput_t<CUtlBuffer *>::aData, 
	                                   aParams.eBehavior, 
	                                   aParams.CKV1Proccessor_t<KV3ToKV1Translation_t *>::aData, 
	                                   aParams.aValue);
}