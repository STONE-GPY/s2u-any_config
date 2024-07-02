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

#include <any_config/keyvalues/reader.hpp>

#include <tier0/keyvalues3.h>

bool AnyConfig::CKeyValuesReader::_LoadFromKV1File(const LoadFromKV1File_t &aParams)
{
	return LoadKV3FromKV1File(aParams.aContext, 
	                          aParams.psMessage, 
	                          aParams.pszFilename, 
	                          aParams.pszPathID, 
	                          aParams.eBehavior);
}

bool AnyConfig::CKeyValuesReader::_LoadFromKV1Text(const LoadFromKV1Text_t &aParams)
{
	return LoadKV3FromKV1Text(aParams.aContext, 
	                          aParams.psMessage, 
	                          aParams.aData, 
	                          aParams.eBehavior, 
	                          aParams.pszName, 
	                          aParams.aValue);
}

bool AnyConfig::CKeyValuesReader::_LoadFromKV1Text_Translated(const LoadFromKV1Text_Translated_t &aParams)
{
	return LoadKV3FromKV1Text_Translated(aParams.aContext, 
	                                     aParams.psMessage, 
	                                     aParams.CInput_t<const char *>::aData, 
	                                     aParams.eBehavior, 
	                                     aParams.CKV1Proccessor_t<KV1ToKV3Translation_t *>::aData, 
	                                     aParams.CKV1Unk_t<int>::aValue, 
	                                     aParams.pszName, 
	                                     aParams.CKV1Unk_t<bool>::aValue);
}

bool AnyConfig::CKeyValuesReader::LoadFromKV1File(const LoadFromKV1FileNoContext_t &aParams)
{
	return LoadKV3FromKV1File(Get(), 
	                          aParams.psMessage, 
	                          aParams.pszFilename, 
	                          aParams.pszPathID, 
	                          aParams.eBehavior);
}

bool AnyConfig::CKeyValuesReader::LoadFromKV1Text(const LoadFromKV1TextNoContext_t &aParams)
{
	return LoadKV3FromKV1Text(Get(), 
	                          aParams.psMessage, 
	                          aParams.aData, 
	                          aParams.eBehavior, 
	                          aParams.pszName, 
	                          aParams.aValue);
}

bool AnyConfig::CKeyValuesReader::LoadFromKV1Text_Translated(const LoadFromKV1Text_TranslatedNoContext_t &aParams)
{
	return LoadKV3FromKV1Text_Translated(Get(), 
	                                     aParams.psMessage, 
	                                     aParams.CInput_t<const char *>::aData, 
	                                     aParams.eBehavior, 
	                                     aParams.CKV1Proccessor_t<KV1ToKV3Translation_t *>::aData, 
	                                     aParams.CKV1Unk_t<int>::aValue, 
	                                     aParams.pszName, 
	                                     aParams.CKV1Unk_t<bool>::aValue);
}
