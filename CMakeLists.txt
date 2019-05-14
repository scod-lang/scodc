#
#   Copyright (C) 2019 SCOD Organization <https://scod-lang.org>
#   All rights reserved.
#
#   Developed by: Philipp Paulweber
#                 Emmanuel Pescosta
#                 <https://github.com/scod-lang/scodc>
#
#   This file is part of scodc.
#
#   scodc is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   scodc is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with scodc. If not, see <http://www.gnu.org/licenses/>.
#

set( PROJECT scodc )

cmake_minimum_required( VERSION ${CMAKE_VERSION} )

project( ${PROJECT} LANGUAGES CXX )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_VERSION 3.2 )
set( CMAKE_MODULE_PATH ${${PROJECT}_SOURCE_DIR}/.cmake )
include( ${CMAKE_CONFIG_PATH}/LibPackage.cmake )

package_git( ${PROJECT} )
package_git_submodule( libstdhl   master REQUIRED obj   ../../lib/stdhl   ../stdhl   lib/stdhl   )
package_git_submodule( libpass    master REQUIRED obj   ../../lib/pass    ../pass    lib/pass    )
package_git_submodule( libscod    master REQUIRED obj   ../../lib/scod    ../scod    lib/scod    )
package_git_submodule( libgtest   master REQUIRED build ../../lib/gtest   ../gtest   lib/gtest   )
package_git_submodule( libhayai   master REQUIRED build ../../lib/hayai   ../hayai   lib/hayai   )
package_git_deps(
  libgtest>libstdhl
  libhayai>libstdhl
  libstdhl>libpass
  libpass>libscod
  )

find_package( Threads REQUIRED )

include( ECMGenerateHeaders )
include( FeatureSummary )
include( GenerateExportHeader )
include( CPack )

add_subdirectory( src )
add_subdirectory( etc
  EXCLUDE_FROM_ALL
  )

#
#
# executable
#

add_executable( ${PROJECT}
  $<TARGET_OBJECTS:${PROJECT}-cpp>
  )

if( CMAKE_BUILD_TYPE EQUAL "RELEASE" )
  set( PROJECT_EXE_FLAGS "-static" )
endif()

if( APPLE )
  set( PROJECT_EXE_FLAGS "" )
endif()

if( ${LIBSCOD_FOUND} )
  target_link_libraries( ${PROJECT} PUBLIC ${PROJECT_EXE_FLAGS}
    ${LIBSCOD_ARCHIVE}
    ${LIBPASS_ARCHIVE}
    ${LIBSTDHL_ARCHIVE}
    Threads::Threads
    )

  if( WIN32 )
    target_link_libraries( ${PROJECT} PUBLIC
      ws2_32
      gomp
      )
  endif()
endif()

set( ${PROJECT}_VERSION ${GIT_REVTAG} )
set_property( TARGET ${PROJECT} PROPERTY VERSION ${${PROJECT}_VERSION} )
set_property( TARGET ${PROJECT} PROPERTY PREFIX  "" )

#
#
# test
#

add_executable( ${PROJECT}-check
  EXCLUDE_FROM_ALL
  $<TARGET_OBJECTS:${PROJECT}-test>
  )

if( ${LIBSCOD_FOUND} )
  target_link_libraries( ${PROJECT}-check
    ${LIBPASS_ARCHIVE}
    ${LIBSTDHL_ARCHIVE}
    ${LIBGTEST_LIBRARY}
    ${LIBGTEST_MAIN}
    Threads::Threads
    )
endif()

#
#
# benchmark
#

add_executable( ${PROJECT}-run
  EXCLUDE_FROM_ALL
  $<TARGET_OBJECTS:${PROJECT}-benchmark>
  )

if( ${LIBSCOD_FOUND} )
  target_link_libraries( ${PROJECT}-run
    ${LIBPASS_ARCHIVE}
    ${LIBSTDHL_ARCHIVE}
    ${LIBHAYAI_LIBRARY}
    Threads::Threads
    )
endif()

#
#
# install
#

install(
  TARGETS  ${PROJECT}
  EXPORT   ${PROJECT}Targets
  LIBRARY  DESTINATION lib
  ARCHIVE  DESTINATION lib
  RUNTIME  DESTINATION bin
  INCLUDES DESTINATION include
  )

# #
# #
# # cmake
# #

# install(
#   FILES
#     .cmake/Find${PROJECT}.cmake
#   DESTINATION
#     "share/cmake/Module/${PROJECT}"
#   )

#
#
# build features and checks
#

include( LibCompile )
compile_flags( CXX )
compile_check()

feature_summary( WHAT
  PACKAGES_NOT_FOUND
  DISABLED_FEATURES
  )
