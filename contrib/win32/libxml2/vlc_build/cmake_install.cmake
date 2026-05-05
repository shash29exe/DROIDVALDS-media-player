# Install script for directory: /home/shash29/vlc/contrib/win32/libxml2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/shash29/vlc/contrib/x86_64-w64-mingw32")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/x86_64-w64-mingw32-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libxml2/libxml" TYPE FILE FILES
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/c14n.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/catalog.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/chvalid.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/debugXML.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/dict.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/encoding.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/entities.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/globals.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/hash.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/HTMLparser.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/HTMLtree.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/list.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/nanoftp.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/nanohttp.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/parser.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/parserInternals.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/pattern.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/relaxng.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/SAX.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/SAX2.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/schemasInternals.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/schematron.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/threads.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/tree.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/uri.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/valid.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xinclude.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xlink.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlIO.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlautomata.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlerror.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlexports.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlmemory.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlmodule.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlreader.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlregexp.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlsave.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlschemas.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlschemastypes.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlstring.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlunicode.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xmlwriter.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xpath.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xpathInternals.h"
    "/home/shash29/vlc/contrib/win32/libxml2/include/libxml/xpointer.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/libxml2.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libxml2" TYPE FILE FILES "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/libxml2-config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libxml2" TYPE FILE FILES "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/libxml2-config-version.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libxml2/libxml2-export.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libxml2/libxml2-export.cmake"
         "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/CMakeFiles/Export/e84b245f3ece1c96ac9ea1f0afd37f4b/libxml2-export.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libxml2/libxml2-export-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libxml2/libxml2-export.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libxml2" TYPE FILE FILES "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/CMakeFiles/Export/e84b245f3ece1c96ac9ea1f0afd37f4b/libxml2-export.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libxml2" TYPE FILE FILES "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/CMakeFiles/Export/e84b245f3ece1c96ac9ea1f0afd37f4b/libxml2-export-relwithdebinfo.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libxml2/libxml" TYPE FILE FILES "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/libxml/xmlversion.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/libxml-2.0.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/xml2-config")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/shash29/vlc/contrib/win32/libxml2/vlc_build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
