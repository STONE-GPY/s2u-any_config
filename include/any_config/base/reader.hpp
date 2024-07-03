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
#include "types.hpp"

namespace AnyConfig
{
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

	template<class T>
	struct CLoadFromFileBase_t : public CLoadTo_t<T>, 
	                             public CError_t, 
	                             public CFileSystemPath_t
	{
	}; // CLoadFromFileBase_t<T>

	template<class T>
	struct CLoadFromFile_t : public CLoadFromFileBase_t<T>, 
	                         public CFormat_t
	{
	}; // CLoadFromFile_t<T>

	template<class T, class I>
	struct CLoadNoHeader_t : public CLoadTo_t<T>, 
	                         public CError_t, 
	                         public CInput_t<I>, 
	                         public CFormat_t, 
	                         public CLoadRoot_t
	{
	}; // CLoadNoHeader_t<T, I>

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

	struct LoadNoHeader_t : CLoadNoHeader_t<KeyValues3 *, const char *>
	{
	}; // LoadNoHeader_t

	struct LoadNoHeaderAndContext_t : CLoadNoHeader_t<CEmpty_t, const char *>
	{
	}; // LoadNoHeaderAndContext_t

	class CBaseReader : public CBase
	{
	public:
		//
		// Load ones (globals).
		//
		static bool _Load(const Load_t &aParams);
		static bool _Load(const Load2_t &aParams);
		static bool _Load(const Load3_t &aParams);

		static bool _LoadFromFile(const LoadFromFile_t &aParams);
		static bool _LoadFromFile(const LoadFromFile2_t &aParams);

		static bool _LoadNoHeader(const LoadNoHeader_t &aParams);

	public:
		//
		// Load ones (members).
		//
		bool Load(const LoadNoContext_t &aParams);
		bool Load(const Load2NoContext_t &aParams);
		bool Load(const Load3NoContext_t &aParams);

		bool LoadFromFile(const LoadFromFileNoContext_t &aParams);
		bool LoadFromFile(const LoadFromFile2NoContext_t &aParams);

		bool LoadNoHeader(const LoadNoHeaderAndContext_t &aParams);
	}; // CBaseReader
}; // AnyConfig

#endif //_INCLUDE_ANY_CONFIG_BASE_READER_HPP_
