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

#ifndef _INCLUDE_ANY_CONFIG_KEYVALUES_READER_HPP_
#define _INCLUDE_ANY_CONFIG_KEYVALUES_READER_HPP_

#pragma once

#include "types.hpp"

#include <any_config/base/reader.hpp>

namespace AnyConfig
{
	template<class T>
	struct CLoadFromKV1File_t : public CLoadTo_t<T>, 
	                            public CError_t, 
	                            public CFileSystemPath_t, 
	                            public CKV1TextEscape_t
	{
		CLoadFromKV1File_t(const T &aInitContext, CUtlString *psInitMessage, const char *pszInitFilename, const char *pszInitPathID, KV1TextEscapeBehavior_t eInitBehavior)
		 :  CLoadTo_t<T>{aInitContext}, 
		    CError_t{psInitMessage}, 
		    CFileSystemPath_t{pszInitFilename, pszInitPathID}, 
		    CKV1TextEscape_t{eInitBehavior}
		{
		}

		CLoadFromKV1File_t(CUtlString *psInitMessage, const char *pszInitFilename, const char *pszInitPathID, KV1TextEscapeBehavior_t eInitBehavior)
		 :  CLoadFromKV1File_t({}, psInitMessage, pszInitFilename, pszInitPathID, eInitBehavior)
		{
		}
	}; // CLoadFromKV1File_t<T>

	class ILoadFromKV1File
	{
	public:
		virtual bool LoadFromKV1File() = 0;
	}; // ILoadFromKV1File

	
	template<class T>
	class CLoadFromKV1FileBase : public T, 
	                             public ILoadFromKV1File
	{
	public:
		using Base_t = T;

		CLoadFromKV1FileBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CLoadFromKV1FileBase<T>

	using LoadFromKV1FileLegacy_t = CLoadFromKV1FileBase<CLoadFromKV1File_t<KeyValues3 *>>;

	class LoadFromKV1File_t : public LoadFromKV1FileLegacy_t
	{
	public:
		using Base_t = LoadFromKV1FileLegacy_t;

		LoadFromKV1File_t(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoadFromKV1File
		bool LoadFromKV1File();
	}; // LoadFromKV1File_t

	using LoadFromKV1FileLegacy_NoContext_t = CNoContextBase<CLoadFromKV1File_t<CEmpty_t>>;

	class LoadFromKV1File_NoContext_t : public LoadFromKV1FileLegacy_NoContext_t
	{
	public:
		using Base_t = LoadFromKV1FileLegacy_NoContext_t;

		LoadFromKV1File_NoContext_t(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public:
		LoadFromKV1File_NoContext_t(const LoadFromFile_Generic_t::Base_t &aInit);
	}; // LoadFromKV1File_NoContext_t

	template<class T, class I>
	struct CLoadFromKV1Text_t : public CLoadTo_t<T>, 
	                            public CError_t, 
	                            public CInput_t<I>, 
	                            public CKV1TextEscape_t, 
	                            public CLoadRoot_t, 
	                            public CKV1Unk_t<bool>
	{
	public:
		CLoadFromKV1Text_t(const T &aInitContext, CUtlString *psInitMessage, const I &aInitInput, KV1TextEscapeBehavior_t eInitBehavior, const char *pszInitRoot, bool bInitUnk)
		 :  CLoadTo_t<T>{aInitContext}, 
		    CError_t{psInitMessage}, 
		    CInput_t<I>{aInitInput}, 
		    CKV1TextEscape_t{eInitBehavior}, 
		    CLoadRoot_t{pszInitRoot}, 
		    CKV1Unk_t<bool>{bInitUnk}
		{
		}

		CLoadFromKV1Text_t(CUtlString *psInitMessage, const I &aInitInput, KV1TextEscapeBehavior_t eInitBehavior, const char *pszInitRoot, bool bInitUnk)
		 :  CLoadFromKV1Text_t({}, psInitMessage, aInitInput, eInitBehavior, pszInitRoot, bInitUnk)
		{
		}
	}; // CLoadFromKV1Text_t<T, I>

	class ILoadFromKV1Text
	{
	public:
		virtual bool LoadFromKV1Text() = 0;
	}; // ILoadFromKV1Text

	template<class T>
	class CLoadFromKV1TextBase : public T, 
	                             public ILoadFromKV1Text
	{
	public:
		using Base_t = T;

	public:
		CLoadFromKV1TextBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CLoadFromKV1TextBase<T>

	using LoadFromKV1TextLegacy_t = CLoadFromKV1TextBase<CLoadFromKV1Text_t<KeyValues3 *, const char *>>;

	class LoadFromKV1Text_t : public LoadFromKV1TextLegacy_t
	{
	public:
		using Base_t = LoadFromKV1TextLegacy_t;

		LoadFromKV1Text_t(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoadFromKV1Text
		bool LoadFromKV1Text();
	}; // LoadFromKV1Text_t

	using LoadFromKV1TextLegacy_NoContext_t = CNoContextBase<CLoadFromKV1Text_t<CEmpty_t, const char *>>;

	class LoadFromKV1Text_NoContext_t : public LoadFromKV1TextLegacy_NoContext_t
	{
	public:
		using Base_t = LoadFromKV1TextLegacy_NoContext_t;

		LoadFromKV1Text_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

		LoadFromKV1Text_NoContext_t(const Load_Generic_t::Base_t &aInit);
	}; // LoadFromKV1Text_NoContext_t

	template<class T, class I, class P>
	struct CLoadFromKV1Text_Translated_t : public CLoadTo_t<T>, 
	                                       public CError_t, 
	                                       public CInput_t<I>, 
	                                       public CKV1TextEscape_t, 
	                                       public CKV1Proccessor_t<P>, 
	                                       public CKV1Unk_t<int>, 
	                                       public CLoadRoot_t, 
	                                       public CKV1Unk_t<bool>
	{
		CLoadFromKV1Text_Translated_t(const T &aInitContext, CUtlString *psInitMessage, const I &aInitInput, const P &aInitProcessor, CKV1Unk_t<int> iInitUnk, const char *pszInitRoot, bool bInitUnk)
		 :  CLoadTo_t<T>{aInitContext}, 
		    CError_t{psInitMessage}, 
		    CInput_t<I>{aInitInput}, 
		    CKV1Proccessor_t<P>{aInitProcessor}, 
		    CKV1Unk_t<int>{iInitUnk}, 
		    CLoadRoot_t{pszInitRoot}, 
		    CKV1Unk_t<bool>{bInitUnk}
		{
		}

		CLoadFromKV1Text_Translated_t(CUtlString *psInitMessage, const I &aInitInput, const P &aInitProcessor, CKV1Unk_t<int> iInitUnk, const char *pszInitRoot, bool bInitUnk)
		 :  CLoadFromKV1Text_Translated_t({}, psInitMessage, aInitInput, aInitProcessor, iInitUnk, pszInitRoot, bInitUnk)
		{
		}
	}; // CLoadFromKV1Text_Translated_t<T, I, P>

	class ILoadFromKV1Text_Translated
	{
	public:
		virtual bool LoadFromKV1Text_Translated() = 0;
	}; // ILoadFromKV1Text_Translated

	template<class T>
	class CLoadFromKV1TextBase_Translated : public T, 
	                                        public ILoadFromKV1Text_Translated
	{
	public:
		using Base_t = T;

		CLoadFromKV1TextBase_Translated(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CLoadFromKV1TextBase_Translated<T>

	using LoadFromKV1TextLegacy_Translated_t = CLoadFromKV1TextBase_Translated<CLoadFromKV1Text_Translated_t<KeyValues3 *, const char *, KV1ToKV3Translation_t *>>;

	class LoadFromKV1Text_Translated_t : public LoadFromKV1TextLegacy_Translated_t
	{
	public:
		using Base_t = LoadFromKV1TextLegacy_Translated_t;

		LoadFromKV1Text_Translated_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoadFromKV1Text_Translated
		bool LoadFromKV1Text_Translated();
	}; // LoadFromKV1Text_Translated_t

	using LoadFromKV1TextLegacy_Translated_NoContext_t = CNoContextBase<CLoadFromKV1Text_Translated_t<CEmpty_t, const char *, KV1ToKV3Translation_t *>>;

	class LoadFromKV1Text_Translated_NoContext_t : public LoadFromKV1TextLegacy_Translated_NoContext_t
	{
	public:
		using Base_t = LoadFromKV1TextLegacy_Translated_NoContext_t;

		LoadFromKV1Text_Translated_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // LoadFromKV1Text_Translated_NoContext_t

	class CKeyValuesReader : public CReaderBase<CBase>
	{
	public: // IBaseReader<Load_Generic_t>
		bool Load(const Load_Generic_t &aParams);

	public: // IBaseReader<LoadFromFile_Generic_t>
		bool Load(const LoadFromFile_Generic_t &aParams);

	public:
		//
		// Load ones (members).
		//
		bool LoadFromKV1File(const LoadFromKV1File_NoContext_t &aParams);
		bool LoadFromKV1Text(const LoadFromKV1Text_NoContext_t &aParams);
		bool LoadFromKV1Text_Translated(const LoadFromKV1Text_Translated_NoContext_t &aParams);
	}; // CKeyValuesReader
}; // AnyConfig

#endif //_INCLUDE_ANY_CONFIG_KEYVALUES_READER_HPP_
