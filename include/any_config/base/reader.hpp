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

#ifndef _INCLUDE_ANY_CONFIG_BASE_READER_HPP_
#define _INCLUDE_ANY_CONFIG_BASE_READER_HPP_

#pragma once

#include "base.hpp"
#include "ireader.hpp"
#include "types.hpp"

namespace AnyConfig
{
	template<class T, typename I>
	struct CLoadBase_t : public CLoadTo_t<T>, 
	                     public CError_t, 
	                     public CInput_t<I>
	{
	}; // CLoadBase_t<T, I>

	template<class T, typename I>
	struct CLoad_t : public CLoadBase_t<T, I>, 
	                 public CFormat_t, 
	                 public CLoadRoot_t
	{
	}; // CLoadBase_t<T, I>

	class ILoad
	{
	public:
		virtual bool Load() = 0;
	}; // ILoad

	class Load_t : public CLoad_t<CKeyValues3Context *, CUtlBuffer *>, 
	               public ILoad
	{
	public: // ILoad
		bool Load();
	}; // Load_t

	class Load2_t : public CLoad_t<KeyValues3 *, CUtlBuffer *>, 
	                public ILoad
	{
	public: // ILoad
		bool Load();
	}; // Load2_t

	class Load3_t : public CLoad_t<KeyValues3 *, const char *>
	{
	public: // ILoad
		bool Load();
	}; // Load3_t

	class Load_NoContext_t : public CNoContextBase<CLoad_t<CEmpty_t, CUtlBuffer *>>
	{
	public:
	}; // Load_NoContext_t

	class Load2_NoContext_t : public CNoContextBase<CLoad_t<CEmpty_t, CUtlBuffer *>>
	{
	public:
	}; // Load2_NoContext_t

	class Load3_NoContext_t : public CNoContextBase<CLoad_t<CEmpty_t, const char *>>
	{
	public:
	}; // Load3_NoContext_t

	class Load_Generic_t : public CGenericBase<Load2_NoContext_t>
	{
	public:
	}; // Load_Generic_t

	template<class T>
	struct CLoadFromFileBase_t : public CLoadTo_t<T>, 
	                             public CError_t, 
	                             public CFileSystemPath_t
	{
	}; // CLoadFromFileBase_t<T>

	template<class T>
	struct CLoadFromFile_t : public CLoadFromFileBase_t<T>, 
	                         public CFormat_t
	{
	}; // CLoadFromFile_t<T>

	class LoadFromFileBase_t : public CLoadFromFileBase_t<KeyValues3 *>
	{
	public:
	}; // LoadFromFileBase_t

	class ILoadFromFile
	{
	public:
		virtual bool LoadFromFile() = 0;
	};

	class LoadFromFile_t : public CLoadFromFile_t<CKeyValues3Context *>, 
	                       public ILoadFromFile
	{
	public: // ILoadFromFile
		bool LoadFromFile();
	}; // LoadFromFile_t

	class LoadFromFile2_t : public CLoadFromFile_t<KeyValues3 *>, 
	                        public ILoadFromFile
	{
	public: // ILoadFromFile
		bool LoadFromFile();
	}; // LoadFromFile2_t

	class LoadFromFile_NoContext_t : public CNoContextBase<CLoadFromFile_t<CEmpty_t>>
	{
	public:
	}; // LoadFromFile_NoContext_t

	class LoadFromFile2_NoContext_t : public CNoContextBase<CLoadFromFile_t<CEmpty_t>>
	{
	public:
	}; // LoadFromFile2_NoContext_t

	class LoadFromFile_Generic_t : public CGenericBase<LoadFromFile2_NoContext_t>
	{
	public:
	}; // LoadFromFile_Generic_t

	template<class T, class I>
	struct CLoadNoHeader_t : public CLoadTo_t<T>, 
	                         public CError_t, 
	                         public CInput_t<I>, 
	                         public CFormat_t, 
	                         public CLoadRoot_t
	{
	}; // CLoadNoHeader_t<T, I>

	class ILoadNoHeader
	{
	public:
		virtual bool LoadNoHeader() = 0;
	}; // ILoadNoHeader

	class LoadNoHeader_t : public CLoadNoHeader_t<KeyValues3 *, const char *>, 
	                       public ILoadNoHeader
	{
	public: // ILoadNoHeader
		bool LoadNoHeader();
	}; // LoadNoHeader_t

	class LoadNoHeader_NoContext_t : public CNoContextBase<LoadNoHeader_t>
	{
	public:
	}; // LoadNoHeader_NoContext_t

	template<class T>
	class CReaderBase : public T, 
	                    public IBaseReader<Load_Generic_t>, 
	                    public IBaseReader<LoadFromFile_Generic_t>
	{
	}; // CReaderBase<T>

	class CBaseReader : public CReaderBase<CBase>
	{
	public: // IBaseReader<Load_Generic_t>
		bool Load(const Load_Generic_t &aParams);

	public: // IBaseReader<LoadFromFile_Generic_t>
		bool Load(const LoadFromFile_Generic_t &aParams);

	public:
		//
		// Load ones (members).
		//
		bool Load(const Load_NoContext_t &aParams);
		bool Load(const Load2_NoContext_t &aParams);
		bool Load(const Load3_NoContext_t &aParams);

		bool LoadFromFile(const LoadFromFile_NoContext_t &aParams);
		bool LoadFromFile(const LoadFromFile2_NoContext_t &aParams);

		bool LoadNoHeader(const LoadNoHeader_NoContext_t &aParams);
	}; // CBaseReader
}; // AnyConfig

#endif //_INCLUDE_ANY_CONFIG_BASE_READER_HPP_
