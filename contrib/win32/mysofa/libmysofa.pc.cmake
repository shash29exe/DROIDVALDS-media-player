Name: @PROJECT_NAME@
Description: @CPACK_PACKAGE_DESCRIPTION@
Version: @PROJECT_VERSION@
includedir=@CMAKE_INSTALL_FULL_INCLUDEDIR@
libdir=@CMAKE_INSTALL_FULL_LIBDIR@

#Requires.private:
Libs:  -L${libdir} -lmysofa  @PKG_CONFIG_PRIVATELIBS@
Cflags:  -I${includedir} 
Requires:  @PKG_CONFIG_REQUIRES@ 
