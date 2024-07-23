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
	public:
		CSaveBase_t(const T &aInitInput, CUtlString *psInitMessage, const O &aInitOutput)
		 :  CSaveFrom_t<T>{aInitInput}, 
		    CError_t{psInitMessage}, 
		    COutput_t<O>{aInitOutput}
		{
		}

		CSaveBase_t(CUtlString *psInitMessage, const O &aInitOutput)
		 :  CSaveBase_t({}, psInitMessage, aInitOutput)
		{
		}
	}; // CSaveBase_t<T, O>

	template<class T, class O>
	struct CSave_t : public CEncode_t, 
	                 public CFormat_t, 
	                 public CSaveBase_t<T, O>, 
	                 public CSaveText_t
	{
	public:
		using Base_t = CSaveBase_t<T, O>;

		CSave_t(const KV3ID_t &aInitEncode, const KV3ID_t &aInitFormat, const Base_t &aInitBase, unsigned int uFlags)
		 :  CEncode_t{aInitEncode}, 
		    CFormat_t{aInitFormat}, 
		    Base_t{aInitBase}, 
		    CSaveText_t{uFlags}
		{
		}
	}; // CSave_t<T, O>

	class ISave
	{
	public:
		virtual bool Save() = 0;
	}; // ISave

	template<class T>
	class CSaveBase : public T, 
	                  public ISave
	{
	public:
		using Base_t = T;

		CSaveBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CSaveBase<T>

	using SaveLegacy_t = CSaveBase<CSave_t<KeyValues3 *, CUtlBuffer *>>;

	class Save_t : public SaveLegacy_t
	{
	public:
		using Base_t = SaveLegacy_t;

		Save_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ISave
		bool Save();
	}; // Save_t

	using SaveLegacy_NoContext_t = CNoContextBase<CSave_t<CEmpty_t, CUtlBuffer *>>;

	class Save_NoContext_t : public SaveLegacy_NoContext_t
	{
	public:
		using Base_t = SaveLegacy_NoContext_t;

		Save_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // Save_NoContext_t

	using SaveLegacy_Generic_t = CGenericBase<Save_NoContext_t>;

	class Save_Generic_t : public SaveLegacy_Generic_t
	{
	public:
		using Base_t = SaveLegacy_Generic_t;
		using GenericBase_t = Base_t::Base_t;
		using NoContextBase_t = GenericBase_t::Base_t::Base_t;

		Save_Generic_t(const GenericBase_t &aInit)
		 :  Base_t(aInit)
		{
		}

		Save_Generic_t(const NoContextBase_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // Save_Generic_t

	template<class T>
	struct CSaveToFile_t : public CEncode_t, 
	                       public CFormat_t, 
	                       public CSaveFrom_t<T>, 
	                       public CError_t, 
	                       public CFileSystemPath_t, 
	                       public CSaveText_t
	{
	public:
		CSaveToFile_t(const KV3ID_t &aInitEncode, const KV3ID_t &aInitFormat, const T &aInitInput, CUtlString *psInitMessage, const char *pszInitFilename, const char *pszInitPathID, unsigned int uFlags)
		 :  CEncode_t{aInitEncode}, 
		    CFormat_t{aInitFormat}, 
		    CSaveFrom_t<T>{aInitInput}, 
		    CError_t{psInitMessage}, 
		    CFileSystemPath_t{pszInitFilename, pszInitPathID}, 
		    CSaveText_t{uFlags}
		{
		}

		CSaveToFile_t(const KV3ID_t &aInitEncode, const KV3ID_t &aInitFormat, CUtlString *psInitMessage, const char *pszInitFilename, const char *pszInitPathID, unsigned int uFlags)
		 :  CSaveToFile_t(aInitEncode, aInitFormat, {}, psInitMessage, pszInitFilename, pszInitPathID, uFlags)
		{
		}
	}; // CSaveToFile_t<T>

	class ISaveToFile
	{
	public:
		virtual bool SaveToFile() = 0;
	}; // ISaveToFile

	template<class T>
	class CSaveToFileBase : public T, 
	                        public ISaveToFile
	{
	public:
		using Base_t = T;

		CSaveToFileBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CSaveToFileBase<T>

	using SaveToFileLegacy_t = CSaveToFileBase<CSaveToFile_t<KeyValues3 *>>;

	class SaveToFile_t : public SaveToFileLegacy_t
	{
	public:
		using Base_t = SaveToFileLegacy_t;

		SaveToFile_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ISaveToFile
		bool SaveToFile();
	}; // SaveToFile_t

	using SaveToFileLegacy_NoContext_t = CNoContextBase<CSaveToFile_t<CEmpty_t>>;

	class SaveToFile_NoContext_t : public SaveToFileLegacy_NoContext_t
	{
	public:
		using Base_t = SaveToFileLegacy_NoContext_t;

		SaveToFile_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // SaveToFile_NoContext_t

	using SaveToFileLegacy_Generic_t = CGenericBase<SaveToFile_NoContext_t>;

	class SaveToFile_Generic_t : public SaveToFileLegacy_Generic_t
	{
	public:
		using Base_t = SaveToFileLegacy_Generic_t;
		using GenericBase_t = Base_t::Base_t;
		using NoContextBase_t = GenericBase_t::Base_t::Base_t;

		SaveToFile_Generic_t(const GenericBase_t &aInit)
		 :  Base_t(aInit)
		{
		}

		SaveToFile_Generic_t(const NoContextBase_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // SaveToFile_Generic_t

	template<class T>
	class CWriterBase : virtual public T, 
	                    public IBaseWriter<Save_Generic_t>, 
	                    public IBaseWriter<SaveToFile_Generic_t>
	{
	public:
		virtual ~CWriterBase() = default;
	}; // CWriterBase<T>

	class CBaseWriter : public CWriterBase<CBase>
	{
	public: // IBaseWriter<Save_Generic_t>
		bool Save(const Save_Generic_t &aParams);

	public: // IBaseWriter<SaveToFile_Generic_t>
		bool Save(const SaveToFile_Generic_t &aParams);

	public:
		//
		// Save ones (members).
		//
		bool Save(const Save_NoContext_t &aParams) const;
		bool SaveToFile(const SaveToFile_NoContext_t &aParams) const;
	}; // CBaseWriter
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_BASE_WRITER_HPP_
