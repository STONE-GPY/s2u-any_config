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
	public:
		CLoadBase_t(const T &aInitContext, CUtlString *psInitMessage, const I &aInitInput)
		 :  CLoadTo_t<T>{aInitContext}, 
		    CError_t{psInitMessage}, 
		    CInput_t<I>{aInitInput}
		{
		}

		CLoadBase_t(CUtlString *psInitMessage, const I &aInitInput)
		 :  CLoadBase_t({}, psInitMessage, aInitInput)
		{
		}
	}; // CLoadBase_t<T, I>

	template<class T, typename I>
	struct CLoad_t : public CLoadBase_t<T, I>, 
	                 public CFormat_t, 
	                 public CLoadRoot_t
	{
	public:
		using Base_t = CLoadBase_t<T, I>;

		CLoad_t(const Base_t &aInitBase, const KV3ID_t &aInitFormat, const char *pszInitRoot)
		 :  CLoadBase_t<T, I>{aInitBase}, 
		    CFormat_t{aInitFormat}, 
		    CLoadRoot_t{pszInitRoot}
		{
		}

		CLoad_t(const CLoad_t &aInit)
		 :  CLoad_t({aInit.m_aContext, aInit.m_psMessage, aInit.m_aData}, aInit.m_aFormat, aInit.m_pszName)
		{
		}
	}; // CLoad_t<T, I>

	class ILoad
	{
	public:
		virtual bool Load() = 0;
	}; // ILoad

	template<class T>
	class CLoadBase : public T, 
	                  public ILoad
	{
	public:
		using Base_t = T;

		CLoadBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	};

	using LoadBase_t = CLoadBase<CLoad_t<CKeyValues3Context *, CUtlBuffer *>>;

	class Load_t : public LoadBase_t
	{
	public:
		using Base_t = LoadBase_t;

		Load_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoad
		bool Load();
	}; // Load_t

	using Load2Base_t = CLoadBase<CLoad_t<KeyValues3 *, CUtlBuffer *>>;

	class Load2_t : public Load2Base_t
	{
	public:
		using Base_t = Load2Base_t;

		Load2_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoad
		bool Load();
	}; // Load2_t

	using Load3Base_t = CLoadBase<CLoad_t<KeyValues3 *, const char *>>;

	class Load3_t : public Load3Base_t
	{
	public:
		using Base_t = Load3Base_t;

		Load3_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoad
		bool Load();
	}; // Load3_t

	using LoadBase_NoContext_t = CNoContextBase<CLoad_t<CEmpty_t, CUtlBuffer *>>;

	class Load_NoContext_t : public LoadBase_NoContext_t
	{
	public:
		using Base_t = LoadBase_NoContext_t;

		Load_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // Load_NoContext_t

	using Load2Base_NoContext_t = CNoContextBase<CLoad_t<CEmpty_t, CUtlBuffer *>>;

	class Load2_NoContext_t : public Load2Base_NoContext_t
	{
	public:
		using Base_t = Load2Base_NoContext_t;

		Load2_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // Load2_NoContext_t

	using Load3Base_NoContext_t = CNoContextBase<CLoad_t<CEmpty_t, const char *>>;

	class Load3_NoContext_t : public Load3Base_NoContext_t
	{
	public:
		using Base_t = Load3Base_NoContext_t;

		Load3_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // Load3_NoContext_t

	using LoadBase_Generic_t = CGenericBase<Load2_NoContext_t>;

	class Load_Generic_t : public LoadBase_Generic_t
	{
	public:
		using Base_t = LoadBase_Generic_t;
		using GenericBase_t = Base_t::Base_t;
		using NoContextBase_t = GenericBase_t::Base_t::Base_t;

		Load_Generic_t(const GenericBase_t &aInit)
		 :  Base_t(aInit)
		{
		}

		Load_Generic_t(const NoContextBase_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // Load_Generic_t

	template<class T>
	struct CLoadFromFileBase_t : public CLoadTo_t<T>, 
	                             public CError_t, 
	                             public CFileSystemPath_t
	{
	public:
		using Base_t = LoadBase_Generic_t;

	public:
		CLoadFromFileBase_t(const T &aInitContext, CUtlString *psInitMessage, const char *pszFilename, const char *pszPathID)
		 :  CLoadTo_t<T>{aInitContext}, 
		    CError_t{psInitMessage}, 
		    CFileSystemPath_t{pszFilename, pszPathID}
		{
		}

		CLoadFromFileBase_t(CUtlString *psInitMessage, const char *pszFilename, const char *pszPathID)
		 :  CLoadFromFileBase_t({}, psInitMessage, pszFilename, pszPathID)
		{
		}

		CLoadFromFileBase_t(const CLoadFromFileBase_t &aInit)
		 :  CLoadFromFileBase_t{aInit.m_aContext, aInit.m_psMessage, aInit.m_pszFilename, aInit.m_pszPathID}
		{
		}
	}; // CLoadFromFileBase_t<T>

	template<class T>
	struct CLoadFromFile_t : public CLoadFromFileBase_t<T>, 
	                         public CFormat_t
	{
	public:
		using Base_t = CLoadFromFileBase_t<T>;

		CLoadFromFile_t(const Base_t &aInitBase, const KV3ID_t &aFormat)
		 :  Base_t{aInitBase}, 
		    CFormat_t{aFormat}
		{
		}

		CLoadFromFile_t(const CLoadFromFile_t &aInit)
		 :  CLoadFromFile_t{{aInit.m_aContext, aInit.m_psMessage, aInit.m_pszFilename, aInit.m_pszPathID}, aInit.m_aFormat}
		{
		}
	}; // CLoadFromFile_t<T>

	template<class T>
	class LoadFromFileBase_t : public CLoadFromFile_t<T>
	{
	public:
		using Base_t = CLoadFromFile_t<T>;

		LoadFromFileBase_t(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // LoadFromFileBase_t

	class ILoadFromFile
	{
	public:
		virtual bool LoadFromFile() = 0;
	}; // ILoadFromFile

	template<class T>
	class CLoadFromFileBase : public T, 
	                          public ILoadFromFile
	{
	public:
		using Base_t = T;

		CLoadFromFileBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CLoadFromFileBase<T>

	class LoadFromFile_t : public CLoadFromFileBase<LoadFromFileBase_t<CKeyValues3Context *>>
	{
	public:
		using Base_t = CLoadFromFileBase<LoadFromFileBase_t<CKeyValues3Context *>>;

		LoadFromFile_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoadFromFile
		bool LoadFromFile() override;
	}; // LoadFromFile_t

	using LoadFromFile2Base_t = CLoadFromFileBase<LoadFromFileBase_t<KeyValues3 *>>;

	class LoadFromFile2_t : public LoadFromFile2Base_t
	{
	public:
		using Base_t = LoadFromFile2Base_t;

		LoadFromFile2_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoadFromFile
		bool LoadFromFile() override;
	}; // LoadFromFile2_t

	using LoadFromFileBase_NoContext_t = CLoadFromFileBase<CLoadFromFile_t<KeyValues3 *>>;

	class LoadFromFile_NoContext_t : public LoadFromFileBase_NoContext_t
	{
	public:
		using Base_t = LoadFromFileBase_NoContext_t;

		LoadFromFile_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // LoadFromFile_NoContext_t

	using LoadFromFile2Base_NoContext_t = CNoContextBase<CLoadFromFile_t<CEmpty_t>>;

	class LoadFromFile2_NoContext_t : public LoadFromFile2Base_NoContext_t
	{
	public:
		using Base_t = LoadFromFile2Base_NoContext_t;

		LoadFromFile2_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // LoadFromFile2_NoContext_t

	using LoadFromFileBase_Generic_t = CGenericBase<LoadFromFile2_NoContext_t>;

	class LoadFromFile_Generic_t : public LoadFromFileBase_Generic_t
	{
	public:
		using Base_t = LoadFromFileBase_Generic_t;
		using GenericBase_t = Base_t::Base_t;
		using NoContextBase_t = GenericBase_t::Base_t::Base_t;

		LoadFromFile_Generic_t(const GenericBase_t &aInit)
		 :  Base_t(aInit)
		{
		}

		LoadFromFile_Generic_t(const NoContextBase_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // LoadFromFile_Generic_t

	template<class T, class I>
	struct CLoadNoHeader_t : public CLoadTo_t<T>, 
	                         public CError_t, 
	                         public CInput_t<I>, 
	                         public CFormat_t, 
	                         public CLoadRoot_t
	{
		CLoadNoHeader_t(const T &aInitContext, CUtlString *psInitMessage, I aInitData, const KV3ID_t &aInitFormat, const char *pszInitRoot)
		 :  CLoadTo_t<T>{aInitContext}, 
		    CError_t{psInitMessage}, 
		    CInput_t<I>{aInitData}, 
		    CFormat_t{aInitFormat}, 
		    CLoadRoot_t{pszInitRoot}
		{
		}

		CLoadNoHeader_t(CUtlString *psInitMessage, I aInitData, const KV3ID_t &aInitFormat, const char *pszInitRoot)
		 :  CLoadNoHeader_t({}, psInitMessage, aInitData, aInitFormat, pszInitRoot)
		{
		}
	}; // CLoadNoHeader_t<T, I>

	class ILoadNoHeader
	{
	public:
		virtual bool LoadNoHeader() = 0;
	}; // ILoadNoHeader

	template<class T>
	class CLoadNoHeaderBase : public T, 
	                          public ILoadNoHeader
	{
	public:
		using Base_t = T;
	
		CLoadNoHeaderBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CLoadNoHeaderBase<T>

	using LoadNoHeaderBase_t = CLoadNoHeaderBase<CLoadNoHeader_t<KeyValues3 *, const char *>>;

	class LoadNoHeader_t : public LoadNoHeaderBase_t
	{
	public:
		using Base_t = LoadNoHeaderBase_t;

		LoadNoHeader_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ILoadNoHeader
		bool LoadNoHeader() override;
	}; // LoadNoHeader_t

	using LoadNoHeaderBase_NoContext_t = CNoContextBase<LoadNoHeader_t>;

	class LoadNoHeader_NoContext_t : public LoadNoHeaderBase_NoContext_t
	{
	public:
		using Base_t = LoadNoHeaderBase_NoContext_t;

		LoadNoHeader_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // LoadNoHeader_NoContext_t

	template<class T>
	class CReaderBase : virtual public T, 
	                    public IBaseReader<Load_Generic_t>, 
	                    public IBaseReader<LoadFromFile_Generic_t>
	{
	public:
		virtual ~CReaderBase() = default;
	}; // CReaderBase<T>

	class CBaseReader : public CReaderBase<CBase>
	{
	public:
		CBaseReader();

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
