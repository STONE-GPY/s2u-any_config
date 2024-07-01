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

#ifndef _INCLUDE_ANY_CONFIG_JSON_TYPES_HPP_
#define _INCLUDE_ANY_CONFIG_JSON_TYPES_HPP_

#pragma once

#include <any_config/base/types.hpp>

namespace AnyConfig
{
	template<class T, class I>
	struct CLoadFromJSON_t : public CLoadTo_t<KeyValues3 *>, 
	                         public CError_t, 
	                         public CInput_t<const char *>, 
	                         public CLoadRoot_t
	{
	}; // CLoadFromJSON_t<T, I>

	struct LoadFromJSON_t : public CLoadFromJSON_t<KeyValues3 *, const char *>
	{
	}; // LoadFromJSON_t

	struct LoadFromJSONNoContext_t : public CLoadFromJSON_t<CEmpty_t, const char *>
	{
	}; // LoadFromJSONNoContext_t

	template<class T>
	struct CLoadFromJSONFile_t : public CLoadTo_t<T>, 
	                             public CError_t, 
	                             public CFileSystemPath_t
	{
	}; // CLoadFromJSONFile_t<T>

	struct LoadFromJSONFile_t : public CLoadFromJSONFile_t<KeyValues3 *>
	{
	}; // LoadFromJSONFile_t

	struct LoadFromJSONFileNoContext_t : public CLoadFromJSONFile_t<CEmpty_t>
	{
	}; // LoadFromJSONFileNoContext_t

	template<class T, class O>
	struct CSaveJSON_t : public CSaveFrom_t<T>, 
	                     public CError_t, 
	                     public COutput_t<O>
	{
	}; // CSaveJSON_t<T, O>

	struct SaveJSON_t : public CSaveJSON_t<KeyValues3 *, CUtlBuffer *>
	{
	}; // SaveJSON_t

	struct SaveJSON2_t : public CSaveJSON_t<KeyValues3 *, CUtlString *>
	{
	}; // SaveJSON2_t

	struct SaveJSONNoContext_t : public CSaveJSON_t<KeyValues3 *, CUtlBuffer *>
	{
	}; // SaveJSONNoContext_t

	struct SaveJSON2NoContext_t : public CSaveJSON_t<KeyValues3 *, CUtlString *>
	{
	}; // SaveJSON2NoContext_t
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_JSON_TYPES_HPP_
