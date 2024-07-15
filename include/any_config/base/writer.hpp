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
#include "iwriter.hpp"
#include "types.hpp"

namespace AnyConfig
{
	template<class T, class O>
	struct CSaveBase_t : public CSaveFrom_t<T>, 
	                     public CError_t, 
	                     public COutput_t<O>
	{
	}; // CSaveBase_t<T, O>

	template<class T, class O>
	struct CSave_t : public CEncode_t, 
	                 public CFormat_t, 
	                 public CSaveBase_t<T, O>, 
	                 public CSaveText_t
	{
	}; // CSave_t<T, O>

	class ISave
	{
	public:
		virtual bool Save() = 0;
	}; // ISave

	class Save_t : public CSave_t<KeyValues3 *, CUtlBuffer *>, 
	               public ISave
	{
	public: // ISave
		bool Save();
	}; // Save_t

	class Save_NoContext_t : public CNoContextBase<CSave_t<CEmpty_t, CUtlBuffer *>>
	{
	public:
	}; // Save_NoContext_t

	class Save_General_t : public CGenericBase<Save_NoContext_t>
	{
	public:
	}; // Save_General_t

	template<class T>
	struct CSaveToFile_t : public CEncode_t, 
	                       public CFormat_t, 
	                       public CSaveFrom_t<T>, 
	                       public CError_t, 
	                       public CFileSystemPath_t, 
	                       public CSaveText_t
	{
	}; // CSaveToFile_t<T>

	class ISaveToFile
	{
	public:
		virtual bool SaveToFile() = 0;
	};

	class SaveToFile_t : public CSaveToFile_t<KeyValues3 *>, 
	                     public ISaveToFile
	{
	public: // ISaveToFile
		bool SaveToFile();
	}; // SaveToFile_t

	class SaveToFile_NoContext_t : public CNoContextBase<CSaveToFile_t<CEmpty_t>>
	{
	}; // SaveToFile_NoContext_t

	class SaveToFile_General_t : public CGenericBase<SaveToFile_NoContext_t>
	{
	}; // SaveToFile_General_t

	class CBaseWriter : public CBase, 
	                    public IBaseWriter<Save_General_t>, 
	                    public IBaseWriter<SaveToFile_General_t>
	{
	public: // IBaseWriter<Save_General_t>
		bool Save(const Save_General_t &aParams);

	public: // IBaseWriter<SaveToFile_General_t>
		bool Save(const SaveToFile_General_t &aParams);

	public:
		//
		// Save ones (members).
		//
		bool Save(const Save_NoContext_t &aParams) const;
		bool SaveToFile(const SaveToFile_NoContext_t &aParams) const;
	}; // CBaseWriter
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_BASE_WRITER_HPP_
