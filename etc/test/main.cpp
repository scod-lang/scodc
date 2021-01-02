//
//  Copyright (C) 2019-2021 SCOD Organization <https://scod-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                Emmanuel Pescosta
//                <https://github.com/scod-lang/scodc>
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

#include "main.h"

#include <scodc/Version>

void scodc_main_dummy( void )
{
    const auto source = libstdhl::Memory::make< libstdhl::Log::Source >( "scodc", "SCODC" );
    libstdhl::Log::defaultSource( source );
}

TEST( scodc_main, empty )
{
    std::cout << scodc::REVTAG << "\n";
    std::cout << scodc::COMMIT << "\n";
    std::cout << scodc::BRANCH << "\n";
    std::cout << scodc::LICENSE << "\n";
    std::cout << scodc::NOTICE << "\n";
}

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
