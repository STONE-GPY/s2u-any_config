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
	struct LoadFromJSON_t : public CLoadTo_t<KeyValues3 *>, 
	                        public CError_t, 
	                        public CInput_t<const char *>, 
	                        public CLoadRoot_t
	{
	}; // LoadFromJSON_t

	struct LoadFromJSONFile_t : public CLoadTo_t<KeyValues3 *>, 
	                            public CError_t, 
	                            public CFileSystemPath_t
	{
	}; // LoadFromJSONFile_t

	struct SaveJSON_t : public CSaveFrom_t<KeyValues3 *>, 
	                    public CError_t, 
	                    public COutput_t<CUtlBuffer *>
	{
	}; // SaveJSON_t

	struct SaveJSON2_t : public CSaveFrom_t<KeyValues3 *>, 
	                    public CError_t, 
	                    public COutput_t<CUtlString *>
	{
	}; // SaveJSON2_t
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_JSON_TYPES_HPP_
