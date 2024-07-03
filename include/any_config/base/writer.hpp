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

#ifndef _INCLUDE_ANY_CONFIG_BASE_WRITER_HPP_
#define _INCLUDE_ANY_CONFIG_BASE_WRITER_HPP_

#pragma once

#include "base.hpp"
#include "types.hpp"

namespace AnyConfig
{
	template<class T, class O>
	struct CSave_t : public CEncode_t, 
	                 public CFormat_t, 
	                 public CSaveFrom_t<T>, 
	                 public CError_t, 
	                 public COutput_t<O>, 
	                 public CSaveText_t
	{
	}; // CSave_t<T, O>

	template<class T>
	struct CSaveToFile_t : public CEncode_t, 
	                       public CFormat_t, 
	                       public CSaveFrom_t<T>, 
	                       public CError_t, 
	                       public CFileSystemPath_t, 
	                       public CSaveText_t
	{
	}; // CSaveToFile_t

	struct Save_t : public CSave_t<KeyValues3 *, CUtlBuffer *>
	{
	}; // Save_t

	struct SaveNoContext_t : public CSave_t<CEmpty_t, CUtlBuffer *>
	{
	}; // SaveNoContext_t

	struct SaveToFile_t : public CSaveToFile_t<KeyValues3 *>
	{
	}; // SaveToFile_t

	struct SaveToFileNoContext_t : public CSaveToFile_t<CEmpty_t>
	{
	}; // SaveToFileNoContext_t

	class CBaseWriter : public CBase
	{
	public:
		//
		// Save ones (globals).
		//
		static bool _Save(const Save_t &aParams);
		static bool _SaveToFile(const SaveToFile_t &aParams);

	public:
		//
		// Save ones (members).
		//
		bool Save(const SaveNoContext_t &aParams) const;
		bool SaveToFile(const SaveToFileNoContext_t &aParams) const;
	}; // CBaseWriter
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_BASE_WRITER_HPP_
