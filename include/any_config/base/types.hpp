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

	struct Load_t : public CLoadTo_t<CKeyValues3Context *>, 
	                public CError_t, 
	                public CInput_t<CUtlBuffer *>, 
	                public CFormat_t, 
	                public CLoadRoot_t
	{
	}; // Load_t

	struct Load2_t : public CLoadTo_t<KeyValues3 *>, 
	                 public CError_t, 
	                 public CInput_t<CUtlBuffer *>, 
	                 public CFormat_t,
	                 public CLoadRoot_t
	{
	}; // Load2_t

	struct Load3_t : public CLoadTo_t<KeyValues3 *>, 
	                 public CError_t, 
	                 public CInput_t<const char *>, 
	                 public CFormat_t,
	                 public CLoadRoot_t
	{
	}; // Load3_t

	struct CFileSystemPath_t
	{
		const char *pszFilename;
		const char *pszPathID;
	}; // CFileSystemPath_t

	struct LoadFromFile_t : public CLoadTo_t<CKeyValues3Context *>, 
	                        public CError_t, 
	                        public CFileSystemPath_t, 
	                        public CFormat_t
	{
	}; // LoadFromFile_t

	struct LoadFromFile2_t : public CLoadTo_t<KeyValues3 *>, 
	                         public CError_t, 
	                         public CFileSystemPath_t, 
	                         public CFormat_t
	{
	}; // LoadFromFile2_t

	struct LoadNoHeader_t : public CLoadTo_t<KeyValues3 *>, 
	                        public CError_t, 
	                        public CInput_t<const char *>, 
	                        public CFormat_t, 
	                        public CLoadRoot_t
	{
	}; // LoadNoHeader_t

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

	struct Save_t : public CEncode_t, 
	                public CFormat_t, 
	                public CSaveFrom_t<KeyValues3 *>, 
	                public CError_t, 
	                public COutput_t<CUtlBuffer *>, 
	                public CSaveText_t
	{
	}; // Save_t

	struct SaveToFile_t : public CEncode_t, 
	                      public CFormat_t, 
	                      public CSaveFrom_t<KeyValues3 *>, 
	                      public CError_t, 
	                      public CFileSystemPath_t, 
	                      public CSaveText_t
	{
	}; // SaveToFile_t
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_BASE_TYPES_HPP_
