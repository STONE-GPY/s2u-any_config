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

#ifndef _INCLUDE_ANY_CONFIG_BASE_TYPES_HPP_
#define _INCLUDE_ANY_CONFIG_BASE_TYPES_HPP_

#pragma once

class CUtlBuffer;
class CUtlString;
struct KV3ID_t;
class CKeyValues3Context;
class KeyValues3;

namespace AnyConfig
{
	struct CEmpty_t
	{
	};

	template<class T>
	struct CLoadTo_t
	{
		T aContext;
	}; // CLoadTo_t<T>

	struct CError_t
	{
		CUtlString *psMessage;
	}; // CError_t

	struct CLoadRoot_t
	{
		const char *pszName;
	}; // CLoadRoot_t

	template<class T>
	struct CInput_t
	{
		T aData;
	}; // CInput_t<T>

	struct CFormat_t
	{
		const KV3ID_t &aFormat; // = g_KV3Format_Generic;
	}; // CFormat_t

	template<class T, typename I>
	struct CLoadBase_t : public CLoadTo_t<T>, 
	                     public CError_t, 
	                     public CInput_t<I>, 
	                     public CFormat_t, 
	                     public CLoadRoot_t
	{
	}; // CLoadBase_t<T, I>

	struct Load_t : public CLoadBase_t<CKeyValues3Context *, CUtlBuffer *>
	{
	}; // Load_t

	struct Load2_t : public CLoadBase_t<KeyValues3 *, CUtlBuffer *>
	{
	}; // Load2_t

	struct Load3_t : public CLoadBase_t<KeyValues3 *, const char *>
	{
	}; // Load3_t

	struct LoadNoContext_t : public CLoadBase_t<CEmpty_t, CUtlBuffer *>
	{
	}; // LoadNoContext_t

	struct Load2NoContext_t : public CLoadBase_t<CEmpty_t, CUtlBuffer *>
	{
	}; // Load2NoContext_t

	struct Load3NoContext_t : public CLoadBase_t<CEmpty_t, const char *>
	{
	}; // Load3NoContext_t

	struct CFileSystemPath_t
	{
		const char *pszFilename;
		const char *pszPathID;
	}; // CFileSystemPath_t

	template<class T = CKeyValues3Context *>
	struct CLoadFromFile_t : public CLoadTo_t<T>, 
	                         public CError_t, 
	                         public CFileSystemPath_t, 
	                         public CFormat_t
	{
	}; // CLoadFromFile_t<T>

	struct LoadFromFile_t : public CLoadFromFile_t<CKeyValues3Context *>
	{
	}; // LoadFromFile_t

	struct LoadFromFile2_t : public CLoadFromFile_t<KeyValues3 *>
	{
	}; // LoadFromFile2_t

	struct LoadFromFileNoContext_t : public CLoadFromFile_t<CEmpty_t>
	{
	}; // LoadFromFileNoContext_t

	struct LoadFromFile2NoContext_t : public CLoadFromFile_t<CEmpty_t>
	{
	}; // LoadFromFile2NoContext_t

	template<class T, class I>
	struct CLoadNoHeader_t : public CLoadTo_t<T>, 
	                         public CError_t, 
	                         public CInput_t<I>, 
	                         public CFormat_t, 
	                         public CLoadRoot_t
	{
	}; // CLoadNoHeader_t<T, I>

	struct LoadNoHeader_t : CLoadNoHeader_t<KeyValues3 *, const char *>
	{
	}; // LoadNoHeader_t

	struct LoadNoHeaderAndContext_t : CLoadNoHeader_t<CEmpty_t, const char *>
	{
	}; // LoadNoHeaderAndContext_t

	struct CEncode_t
	{
		const KV3ID_t &aEncoding; // = g_KV3Encoding_Text;
	}; // CEncode_t

	template<class T>
	struct CSaveFrom_t
	{
		const T aData;
	}; // CSaveFrom_t<T>

	template<class T>
	struct COutput_t
	{
		T aData;
	}; // COutput_t<T>

	struct CSaveText_t
	{
		unsigned int uFlags; // KV3_SAVE_TEXT_NONE;
	}; // CSaveText_t

	template<class T = KeyValues3 *, class O = CUtlBuffer *>
	struct CSave_t : public CEncode_t, 
	                 public CFormat_t, 
	                 public CSaveFrom_t<T>, 
	                 public CError_t, 
	                 public COutput_t<O>, 
	                 public CSaveText_t
	{
	}; // CSave_t<T, O>

	struct Save_t : public CSave_t<KeyValues3 *, CUtlBuffer *>
	{
	}; // Save_t

	struct SaveNoContext_t : public CSave_t<CEmpty_t, CUtlBuffer *>
	{
	}; // SaveNoContext_t

	template<class T>
	struct CSaveToFile_t : public CEncode_t, 
	                       public CFormat_t, 
	                       public CSaveFrom_t<T>, 
	                       public CError_t, 
	                       public CFileSystemPath_t, 
	                       public CSaveText_t
	{
	}; // CSaveToFile_t

	struct SaveToFile_t : public CSaveToFile_t<KeyValues3 *>
	{
	}; // SaveToFile_t

	struct SaveToFileNoContext_t : public CSaveToFile_t<CEmpty_t>
	{
	}; // SaveToFileNoContext_t
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_BASE_TYPES_HPP_
