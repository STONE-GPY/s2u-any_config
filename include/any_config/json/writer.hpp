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

#ifndef _INCLUDE_ANY_CONFIG_JSON_WRITER_HPP_
#define _INCLUDE_ANY_CONFIG_JSON_WRITER_HPP_

#pragma once

#include "types.hpp"

#include <any_config/base/writer.hpp>

namespace AnyConfig
{
	template<class T, class O>
	struct CSaveJSON_t : public CSaveFrom_t<T>, 
	                     public CError_t, 
	                     public COutput_t<O>
	{
		CSaveJSON_t(const T &aInitInput, CUtlString *psInitMessage, const O &aInitOutput)
		 :  CSaveFrom_t<T>{aInitInput}, 
		    CError_t{psInitMessage}, 
		    COutput_t<O>{aInitOutput}
		{
		}
	}; // CSaveJSON_t<T, O>

	class ISaveJSON
	{
	public:
		virtual bool SaveJSON() = 0;
	}; // ISaveJSON

	template<class T>
	class CSaveJSONBase : public T, 
	                      public ISaveJSON
	{
	public:
		using Base_t = T;

		CSaveJSONBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // CSaveJSONBase<T>

	using SaveJSONLegacy_t = CSaveJSONBase<CSaveJSON_t<KeyValues3 *, CUtlBuffer *>>;

	class SaveJSON_t : public SaveJSONLegacy_t
	{
	public:
		using Base_t = SaveJSONLegacy_t;

		SaveJSON_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ISaveJSON
		bool SaveJSON();
	}; // SaveJSON_t

	using SaveJSON2Legacy_t = CSaveJSONBase<CSaveJSON_t<KeyValues3 *, CUtlString *>>;

	class SaveJSON2_t : public SaveJSON2Legacy_t
	{
	public:
		using Base_t = SaveJSON2Legacy_t;

		SaveJSON2_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

	public: // ISaveJSON
		bool SaveJSON2();
	}; // SaveJSON2_t

	using SaveJSONLegacy_NoContext_t = CNoContextBase<CSaveJSON_t<CEmpty_t, CUtlBuffer *>>;

	class SaveJSON_NoContext_t : public SaveJSONLegacy_NoContext_t
	{
	public:
		using Base_t = SaveJSONLegacy_NoContext_t;

		SaveJSON_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

		SaveJSON_NoContext_t(const Save_Generic_t::Base_t &aInit);
	}; // SaveJSON_NoContext_t

	using SaveJSON2Legacy_NoContext_t = CNoContextBase<CSaveJSON_t<CEmpty_t, CUtlString *>>;

	class SaveJSON2_NoContext_t : public SaveJSON2Legacy_NoContext_t
	{
	public:
		using Base_t = SaveJSON2Legacy_NoContext_t;

		SaveJSON2_NoContext_t(const Base_t::Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
	}; // SaveJSON2_NoContext_t

	class CJSONWriter : public CWriterBase<CBase>
	{
	public: // IBaseWriter<Save_Generic_t>
		bool Save(const Save_Generic_t &aParams);

	public: // IBaseWriter<SaveToFile_Generic_t>
		bool Save(const SaveToFile_Generic_t &aParams);

	public:
		//
		// Save ones (members).
		//
		bool SaveJSON(const SaveJSON_NoContext_t &aParams) const;
		bool SaveJSON(const SaveJSON2_NoContext_t &aParams) const;
	}; // CJSONWriter
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_JSON_WRITER_HPP_
