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

#ifndef _INCLUDE_ANY_CONFIG_KEYVALUES_TYPES_HPP_
#define _INCLUDE_ANY_CONFIG_KEYVALUES_TYPES_HPP_

#pragma once

#include <any_config/base/types.hpp>

#include <tier0/keyvalues3.h>

namespace AnyConfig
{
	struct CKV1TextEscape_t
	{
		KV1TextEscapeBehavior_t eBehavior;
	}; // CKV1TextEscape_t

	template<typename T>
	struct CKV1Unk_t
	{
		T aValue;
	}; // CKV1Unk_t<T>

	template<class T>
	struct CKV1Proccessor_t : public CIO_t<const T>
	{
	}; // CKV1Proccessor_t<T>

	template<class T>
	struct CLoadFromKV1File_t : public CLoadTo_t<T>, 
	                            public CError_t, 
	                            public CFileSystemPath_t, 
	                            public CKV1TextEscape_t
	{
	}; // CLoadFromKV1File_t<T>

	struct LoadFromKV1File_t : public CLoadFromKV1File_t<KeyValues3 *>
	{
	}; // LoadFromKV1File_t

	struct LoadFromKV1FileNoContext_t : public CLoadFromKV1File_t<CEmpty_t>
	{
	}; // LoadFromKV1FileNoContext_t

	template<class T, class I>
	struct CLoadFromKV1Text_t : public CLoadTo_t<T>, 
	                            public CError_t, 
	                            public CInput_t<I>, 
	                            public CKV1TextEscape_t, 
	                            public CLoadRoot_t, 
	                            public CKV1Unk_t<bool>
	{
	}; // CLoadFromKV1Text_t<T>

	struct LoadFromKV1Text_t : public CLoadFromKV1Text_t<KeyValues3 *, const char *>
	{
	}; // LoadFromKV1Text_t

	struct LoadFromKV1TextNoContext_t : public CLoadFromKV1Text_t<CEmpty_t, const char *>
	{
	}; // LoadFromKV1TextNoContext_t

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
	}; // CLoadFromKV1Text_Translated_t<T, I, P>

	struct LoadFromKV1Text_Translated_t : public CLoadFromKV1Text_Translated_t<KeyValues3 *, const char *, KV1ToKV3Translation_t *>
	{
	}; // LoadFromKV1Text_Translated_t

	struct LoadFromKV1Text_TranslatedNoContext_t : public CLoadFromKV1Text_Translated_t<CEmpty_t, const char *, KV1ToKV3Translation_t *>
	{
	}; // LoadFromKV1Text_TranslatedNoContext_t

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

}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_KEYVALUES_TYPES_HPP_
