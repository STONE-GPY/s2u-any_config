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

#ifndef _INCLUDE_ANY_CONFIG_FILE_EXTENSION_CHECK_HPP_
#define _INCLUDE_ANY_CONFIG_FILE_EXTENSION_CHECK_HPP_

#pragma once

#include <array>
#include <cassert>
#include <cstring>

namespace AnyConfig
{
	namespace FileExtension
	{
		class ICheck
		{
		public:
			virtual bool Check(const char *pszFilename) = 0;
		}; // ICheck

		template<const char *...t_pszExtensions>
		class CCheck : public ICheck
		{
			static constexpr std::array<const char *, sizeof...(t_pszExtensions)> sm_aExtensions = {t_pszExtensions...};

		public: // ICheck
			bool Check(const char *pszFilename)
			{
				assert(pszFilename);

				for(const char *pszExtension : sm_aExtensions)
				{
					std::size_t nFilenameLength = std::strlen(pszFilename);

					std::size_t nExtensionLength = std::strlen(pszExtension);

					if(nFilenameLength < nExtensionLength)
					{
						continue;
					}

					if(!std::strcmp(pszFilename + nFilenameLength - nExtensionLength, pszExtension))
					{
						return true;
					}
				}

				return false;
			}
		}; // CCheck<t_pszExtensions>
	}; // FileExtension
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_FILE_EXTENSION_CHECK_HPP_
