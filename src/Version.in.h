//
//  Copyright (C) 2019-2022 SCOD Organization <https://scod-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber et al.
//                <https://github.com/scod-lang/scodc/graphs/contributors>
//
//  This file is part of scodc.
//
//  scodc is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  scodc is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with scodc. If not, see <http://www.gnu.org/licenses/>.
//

#ifndef _SCOD_VERSION_H_
#define _SCOD_VERSION_H_

#include <string>

/**
   @brief    TODO

   TODO

   variables are automatically set by CMake
*/

namespace scodc
{
    const std::string DESCRIPTION = "SCOD Command Line Utility\n";
    constexpr const char* REVTAG = "@GIT_REVTAG@";
    constexpr const char* COMMIT = "@GIT_COMMIT@";
    constexpr const char* BRANCH = "@GIT_BRANCH@";
    constexpr const char* LICENSE = "@GIT_LICENSE@";
    constexpr const char* NOTICE = "@GIT_NOTICE@";
}

#endif  // _SCOD_VERSION_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
