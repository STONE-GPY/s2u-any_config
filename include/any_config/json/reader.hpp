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

#ifndef _INCLUDE_ANY_CONFIG_JSON_READER_HPP_
#define _INCLUDE_ANY_CONFIG_JSON_READER_HPP_

#pragma once

#include "types.hpp"

#include <any_config/base/reader.hpp>

#include <tier0/utlbuffer.h>

namespace AnyConfig
{
	template<class T, class I>
	struct CLoadFromJSON_t : public CLoadTo_t<T>, 
	                         public CError_t, 
	                         public CInput_t<I>, 
	                         public CLoadRoot_t
	{
	public:
		CLoadFromJSON_t(const T &aInitContext, CUtlString *psInitMessage, I aInitInput, const char *pszInitRoot)
		 :  CLoadTo_t<T>{aInitContext}, 
		    CError_t{psInitMessage}, 
		    CInput_t<I>{aInitInput}, 
		    CLoadRoot_t{pszInitRoot}
		{
		}

		CLoadFromJSON_t(CUtlString *psInitMessage, I aInitInput, const char *pszInitRoot)
		 :  CLoadFromJSON_t({}, psInitMessage, aInitInput, pszInitRoot)
		{
		}

		CLoadFromJSON_t(const CLoadFromJSON_t &aInit)
		 :  CLoadFromJSON_t(aInit.m_aContext, aInit.m_psMessage, aInit.m_aData, aInit.m_pszName)
		{
		}
	}; // CLoadFromJSON_t<T, I>

	class ILoadFromJSON
	{
	public:
		virtual bool LoadFromJSON() = 0;
	}; // ILoadFromJSON

	template<class T>
	class CLoadFromJSONBase : public T, 
	                          public ILoadFromJSON
	{
	public:
		using Base_t = T;

		CLoadFromJSONBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CLoadFromJSONBase<T>

	using LoadFromJSONLegacy_t = CLoadFromJSONBase<CLoadFromJSON_t<KeyValues3 *, const char *>>;

	class LoadFromJSON_t : public LoadFromJSONLegacy_t
	{
	public:
		using Base_t = LoadFromJSONLegacy_t;

		LoadFromJSON_t(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoadFromJSON
		bool LoadFromJSON();
	}; // LoadFromJSON_t

	using LoadFromJSONLegacy_NoContext_t = CNoContextBase<CLoadFromJSON_t<KeyValues3 *, const char *>>;

	class LoadFromJSON_NoContext_t : public LoadFromJSONLegacy_NoContext_t
	{
	public:
		using Base_t = LoadFromJSONLegacy_NoContext_t;

		LoadFromJSON_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

		LoadFromJSON_NoContext_t(const Load_Generic_t &aInit);
	}; // LoadFromJSON_NoContext_t

	template<class T>
	struct CLoadFromJSONFile_t : public CLoadTo_t<T>, 
	                             public CError_t, 
	                             public CFileSystemPath_t
	{
	public:
		CLoadFromJSONFile_t(const T &aInitContext, CUtlString *psInitMessage, const char *pszInitFilename, const char *pszInitPathID)
		 :  CLoadTo_t<T>{aInitContext}, 
		    CError_t{psInitMessage}, 
		    CFileSystemPath_t{pszInitFilename, pszInitPathID}
		{
		}

		CLoadFromJSONFile_t(CUtlString *psInitMessage, const char *pszInitFilename, const char *pszInitPathID)
		 :  CLoadFromJSONFile_t(psInitMessage, pszInitFilename, pszInitPathID)
		{
		}
	}; // CLoadFromJSONFile_t<T>

	class ILoadFromJSONFile
	{
	public:
		virtual bool LoadFromJSONFile() = 0;
	}; // ILoadFromJSONFile

	template<class T>
	class CLoadFromJSONFileBase : public T, 
	                              public ILoadFromJSONFile
	{
	public:
		using Base_t = T;

		CLoadFromJSONFileBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CLoadFromJSONFileBase<T>

	using LoadFromJSONFileLegacy_t = CLoadFromJSONFileBase<CLoadFromJSONFile_t<KeyValues3 *>>;

	class LoadFromJSONFile_t : public LoadFromJSONFileLegacy_t
	{
	public:
		using Base_t = LoadFromJSONFileLegacy_t;

		LoadFromJSONFile_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoadFromJSONFile
		bool LoadFromJSONFile();
	}; // LoadFromJSONFile_t

	using LoadFromJSONFileLegacy_NoContext_t = CNoContextBase<CLoadFromJSONFile_t<CEmpty_t>>;

	class LoadFromJSONFile_NoContext_t : public LoadFromJSONFileLegacy_NoContext_t
	{
	public:
		using Base_t = LoadFromJSONFileLegacy_NoContext_t;

		LoadFromJSONFile_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public:
	}; // LoadFromJSONFile_NoContext_t

	class CJSONReader : public CReaderBase<CBase>
	{
	public: // IBaseReader<Load_Generic_t>
		bool Load(const Load_Generic_t &aParams);

	public: // IBaseReader<LoadFromFile_Generic_t>
		bool Load(const LoadFromFile_Generic_t &aParams);

	public:
		//
		// Load ones (members).
		//
		bool LoadFromJSON(const LoadFromJSON_NoContext_t &aParams);
		bool LoadFromJSONFile(const LoadFromJSONFile_NoContext_t &aParams);
	}; // CJSONReader
}; // AnyConfig

#endif //_INCLUDE_ANY_CONFIG_JSON_READER_HPP_
