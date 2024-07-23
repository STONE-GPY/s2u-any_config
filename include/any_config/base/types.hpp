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
		CEmpty_t() {};
	}; // CEmpty_t

	template<typename T>
	struct CConstExpr_t
	{
	private:
		T m_aValue;

	public:
		constexpr CConstExpr_t(T aInit)
		 :  m_aValue(aInit)
		{
		}

		operator T() const
		{
			return m_aValue;
		}
	}; // CConstExpr_t<T>

	using CString_t = CConstExpr_t<const char *>;

	template<class T>
	struct CLoadTo_t
	{
		T m_aContext;
	}; // CLoadTo_t<T>

	struct CError_t
	{
		CUtlString *m_psMessage;
	}; // CError_t

	struct CLoadRoot_t
	{
		const char *m_pszName;
	}; // CLoadRoot_t

	template<class T>
	struct CIO_t
	{
		T m_aData;
	}; // CIO_t<T>

	template<class T>
	struct CInput_t : public CIO_t<T>
	{
		using Base_t = CIO_t<T>;

		CInput_t(const T &aInit)
		 :  Base_t{aInit}
		{
		}
	}; // CInput_t<T>

	struct CFormat_t
	{
		const KV3ID_t &m_aFormat; // = g_KV3Format_Generic;
	}; // CFormat_t

	struct CFileSystemPath_t
	{
		const char *m_pszFilename;
		const char *m_pszPathID;
	}; // CFileSystemPath_t

	struct CEncode_t
	{
		const KV3ID_t &m_aEncoding; // = g_KV3Encoding_Text;
	}; // CEncode_t

	template<class T>
	struct CSaveFrom_t : public CIO_t<const T>
	{
		using Base_t = CIO_t<const T>;

		CSaveFrom_t(const T &aInit)
		 :  Base_t{aInit}
		{
		}
	}; // CSaveFrom_t<T>

	template<class T>
	struct COutput_t : public CIO_t<T>
	{
		using Base_t = CIO_t<T>;

		COutput_t(const T &aInit)
		 :  Base_t{aInit}
		{
		}
	}; // COutput_t<T>

	struct CSaveText_t
	{
		unsigned int m_uFlags; // KV3_SAVE_TEXT_NONE;
	}; // CSaveText_t

	template<class T>
	class INoContext
	{
	public:
		virtual ~INoContext() = default;
	}; // INoContext<T>

	template<class T>
	class CNoContextBase : public T, 
	                       public INoContext<T>
	{
	public:
		using Base_t = T;

		CNoContextBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}
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

		CGenericBase(const Base_t &aInit)
		 :  Base_t(aInit)
		{
		}

		template<typename P>
		P To() const
		{
			return static_cast<P>(*this);
		}

		T ToBase() const
		{
			return To<T>();
		}
	}; // CGenericBase<T>
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_BASE_TYPES_HPP_
