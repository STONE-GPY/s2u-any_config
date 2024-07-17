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

#ifndef _INCLUDE_ANY_CONFIG_KEYVALUES_WRITER_HPP_
#define _INCLUDE_ANY_CONFIG_KEYVALUES_WRITER_HPP_

#pragma once

#include "types.hpp"

#include <any_config/base/writer.hpp>

namespace AnyConfig
{
	template<class T, class O>
	struct CSaveAsKV1Text_t : public CLoadTo_t<T>, 
	                          public CError_t, 
	                          public COutput_t<O>, 
	                          public CKV1TextEscape_t
	{
	}; // CSaveAsKV1Text_t<T, O>

	class ISaveAsKV1Text
	{
	public:
		virtual bool SaveAsKV1Text() = 0;
	}; // ISaveAsKV1Text

	class SaveAsKV1Text_t : public CSaveAsKV1Text_t<KeyValues3 *, CUtlBuffer *>, 
	                        public ISaveAsKV1Text
	{
	public: // ISaveAsKV1Text
		bool SaveAsKV1Text();
	}; // SaveAsKV1Text_t

	class SaveAsKV1Text_NoContext_t : public CNoContextBase<CSaveAsKV1Text_t<CEmpty_t, CUtlBuffer *>>
	{
	public:
		SaveAsKV1Text_NoContext_t(const Save_General_t::Base_t &aInit);
	}; // SaveAsKV1Text_NoContext_t

	template<class T, class O, class P>
	struct CSaveAsKV1Text_Translated_t : public CSaveAsKV1Text_t<T, O>, 
	                                     public CKV1Unk_t<bool>, 
	                                     public CKV1Proccessor_t<P>
	{
	}; // CSaveAsKV1Text_Translated_t<T, O, P>

	class ISaveAsKV1Text_Translated
	{
	public:
		virtual bool SaveAsKV1Text_Translated() = 0;
	}; // ISaveAsKV1Text_Translated

	class SaveAsKV1Text_Translated_t : public CSaveAsKV1Text_Translated_t<KeyValues3 *, CUtlBuffer *, KV3ToKV1Translation_t *>, 
	                                   public ISaveAsKV1Text_Translated
	{
	public:
		bool SaveAsKV1Text_Translated();
	}; // SaveAsKV1Text_Translated_t

	class SaveAsKV1Text_Translated_NoContext_t : public CNoContextBase<CSaveAsKV1Text_Translated_t<CEmpty_t, CUtlBuffer *, KV3ToKV1Translation_t *>>
	{
	public:
	}; // SaveAsKV1Text_Translated_NoContext_t

	class CKeyValuesWriter : public CWriterBase<CBase>
	{
	public: // IBaseWriter<Save_General_t>
		bool Save(const Save_General_t &aParams);

	public: // IBaseWriter<SaveToFile_General_t>
		bool Save(const SaveToFile_General_t &aParams);

	public:
		//
		// Save ones (members).
		//
		bool SaveAsKV1Text(const SaveAsKV1Text_NoContext_t &aParams);
		bool SaveAsKV1Text_Translated(const SaveAsKV1Text_Translated_NoContext_t &aParams);
	}; // CKeyValuesWriter
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_KEYVALUES_WRITER_HPP_
