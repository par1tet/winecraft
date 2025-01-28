# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/par1tet/reps/winecraft/_deps/soil-src"
  "/home/par1tet/reps/winecraft/_deps/soil-build"
  "/home/par1tet/reps/winecraft/_deps/soil-subbuild/soil-populate-prefix"
  "/home/par1tet/reps/winecraft/_deps/soil-subbuild/soil-populate-prefix/tmp"
  "/home/par1tet/reps/winecraft/_deps/soil-subbuild/soil-populate-prefix/src/soil-populate-stamp"
  "/home/par1tet/reps/winecraft/_deps/soil-subbuild/soil-populate-prefix/src"
  "/home/par1tet/reps/winecraft/_deps/soil-subbuild/soil-populate-prefix/src/soil-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/par1tet/reps/winecraft/_deps/soil-subbuild/soil-populate-prefix/src/soil-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/par1tet/reps/winecraft/_deps/soil-subbuild/soil-populate-prefix/src/soil-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
