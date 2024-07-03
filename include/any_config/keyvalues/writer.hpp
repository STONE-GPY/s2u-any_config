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

	struct SaveAsKV1Text_t : public CSaveAsKV1Text_t<KeyValues3 *, CUtlBuffer *>
	{
	}; // SaveAsKV1Text_t

	struct SaveAsKV1TextNoContext_t : public CSaveAsKV1Text_t<CEmpty_t, CUtlBuffer *>
	{
	}; // SaveAsKV1TextNoContext_t

	template<class T, class O, class P>
	struct CSaveAsKV1Text_Translated_t : public CSaveAsKV1Text_t<T, O>, 
	                                     public CKV1Unk_t<bool>, 
	                                     public CKV1Proccessor_t<P>
	{
	}; // CSaveAsKV1Text_Translated_t<T, O, P>

	struct SaveAsKV1Text_Translated_t : public CSaveAsKV1Text_Translated_t<KeyValues3 *, CUtlBuffer *, KV3ToKV1Translation_t *>
	{
	}; // SaveAsKV1Text_Translated_t

	struct SaveAsKV1Text_TranslatedNoContext_t : public CSaveAsKV1Text_Translated_t<CEmpty_t, CUtlBuffer *, KV3ToKV1Translation_t *>
	{
	}; // SaveAsKV1Text_TranslatedNoContext_t

	class CKeyValuesWriter : public CBaseWriter
	{
	public:
		//
		// Save ones (globals).
		//
		static bool _SaveAsKV1Text(const SaveAsKV1Text_t &aParams);
		static bool _SaveAsKV1Text_Translated(const SaveAsKV1Text_Translated_t &aParams);

	public:
		//
		// Save ones (members).
		//
		bool SaveAsKV1Text(const SaveAsKV1TextNoContext_t &aParams);
		bool SaveAsKV1Text_Translated(const SaveAsKV1Text_TranslatedNoContext_t &aParams);
	}; // CKeyValuesWriter
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_KEYVALUES_WRITER_HPP_
