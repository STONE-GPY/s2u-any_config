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
	}; // CEmpty_t

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
	struct CIO_t
	{
		T aData;
	}; // CIO_t<T>

	template<class T>
	struct CInput_t : public CIO_t<T>
	{
	}; // CInput_t<T>

	struct CFormat_t
	{
		const KV3ID_t &aFormat; // = g_KV3Format_Generic;
	}; // CFormat_t

	struct CFileSystemPath_t
	{
		const char *pszFilename;
		const char *pszPathID;
	}; // CFileSystemPath_t

	struct CEncode_t
	{
		const KV3ID_t &aEncoding; // = g_KV3Encoding_Text;
	}; // CEncode_t

	template<class T>
	struct CSaveFrom_t : CIO_t<const T>
	{
	}; // CSaveFrom_t<T>

	template<class T>
	struct COutput_t : public CIO_t<T>
	{
	}; // COutput_t<T>

	struct CSaveText_t
	{
		unsigned int uFlags; // KV3_SAVE_TEXT_NONE;
	}; // CSaveText_t

	template<class T>
	class INoContext
	{
	public:
		virtual ~INoContext() = 0;
	}; // INoContext<T>

	template<class T, typename... Args>
	class CNoContextBase : public T, 
	                       public INoContext<T>
	{
	public:
		using Base_t = T;
	}; // CNoContextBase<T>

	template<class T>
	class IGeneric
	{
	public:
		virtual T ToBase() const = 0;
	}; // IGeneric<T>

	template<class T>
	class CGenericBase : public T, 
	                     public IGeneric<T>
	{
	public:
		using Base_t = T;

		template<typename P>
		P To() const
		{
			return static_cast<P>(*this);
		}

		T ToBase() const
		{
			return To<T>(*this);
		}
	}; // CGenericBase<T>
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_BASE_TYPES_HPP_
