# Stefan Achatz 2016
#
# Tries to find liblua and sets following variables according to found capabilities:
#
# LUA_FOUND
# LUA_INCLUDE_DIR
# LUA_LIBRARY
#
# LUA_FIND_VERSION is mandatory and only exact match is supported.

IF(NOT LUA_FIND_VERSION OR NOT LUA_FIND_VERSION_EXACT)
  MESSAGE(FATAL_ERROR "Lua finder needs exact version!")
ENDIF()

# LUA_FIND_VERSION = 5.1
# _LUA_FIND_VERSION_MAYOR = 5
# _LUA_FIND_VERSION_MINOR = 1
STRING(REGEX REPLACE "([0-9]+)\\.([0-9]+)" "\\1" _LUA_FIND_VERSION_MAYOR ${LUA_FIND_VERSION})
STRING(REGEX REPLACE "([0-9]+)\\.([0-9]+)" "\\2" _LUA_FIND_VERSION_MINOR ${LUA_FIND_VERSION})
# _LUA_FIND_VERSION_NUM_SHORT = 51; used for postfix
SET(_LUA_FIND_VERSION_NUM_SHORT ${_LUA_FIND_VERSION_MAYOR}${_LUA_FIND_VERSION_MINOR})
# _LUA_FIND_VERSION_NUM = 501; used for version comparison
IF(${_LUA_FIND_VERSION_MINOR} LESS 10)
  SET(_LUA_FIND_VERSION_NUM ${_LUA_FIND_VERSION_MAYOR}0${_LUA_FIND_VERSION_MINOR})
ELSE()
  SET(_LUA_FIND_VERSION_NUM ${_LUA_FIND_VERSION_MAYOR}${_LUA_FIND_VERSION_MINOR})
ENDIF()

SET(_LUA_POSTFIXES ${_LUA_FIND_VERSION_NUM_SHORT} ${LUA_FIND_VERSION} -${LUA_FIND_VERSION})
SET(_LUA_NAMES luajit lua)

FIND_PACKAGE(PkgConfig)

FOREACH(_LUA_NAME ${_LUA_NAMES})

  STRING(REGEX REPLACE "([^;]+)" "${_LUA_NAME}\\1" _LUA_POSTFIXED_NAMES "${_LUA_POSTFIXES}")
  LIST(APPEND _LUA_POSTFIXED_NAMES ${_LUA_NAME})

  FOREACH(_LUA_POSTFIXED_NAME ${_LUA_POSTFIXED_NAMES})

    UNSET(PKG_LUA_FOUND CACHE)
    UNSET(PKG_LUA_INCLUDE_DIRS CACHE)
    UNSET(PKG_LUA_INCLUDEDIR CACHE)
    UNSET(PKG_LUA_LIBRARY_DIRS CACHE)
    PKG_CHECK_MODULES(PKG_LUA ${_LUA_POSTFIXED_NAME})

    IF(PKG_LUA_FOUND)

      UNSET(LUA_INCLUDE_DIR CACHE)
      FIND_PATH(LUA_INCLUDE_DIR lua.h
        HINTS
          ENV LUA_DIR
          ${PKG_LUA_INCLUDE_DIRS}
          ${PKG_LUA_INCLUDEDIR}
        PATH_SUFFIXES
          ${_LUA_POSTFIXED_NAMES}
          include
      )

      UNSET(LUA_LIBRARY CACHE)
      FIND_LIBRARY(LUA_LIBRARY
        NAMES
          ${_LUA_POSTFIXED_NAMES}
        HINTS
          ENV LUA_DIR
          ${PKG_LUA_LIBRARY_DIRS}
          ${PKG_LUA_LIBDIR}
      )

      IF(LUA_LIBRARY AND LUA_INCLUDE_DIR)

        # LUA_VERSION_NUM seems to be the only definition being constant over versions
        FILE(STRINGS "${LUA_INCLUDE_DIR}/lua.h" _LINE REGEX "^#define[ \t]+LUA_VERSION_NUM[ \t]+.+")
        IF(_LINE)
          STRING(REGEX REPLACE "^#define[ \t]+LUA_VERSION_NUM[ \t]+([^ \t]+)" "\\1" _LUA_VERSION_NUM "${_LINE}")
        ELSE()
          MESSAGE(FATAL_ERROR "Can't read ${LUA_INCLUDE_DIR}/lua.h")
        ENDIF()
        UNSET(_LINE)

        IF(_LUA_VERSION_NUM EQUAL _LUA_FIND_VERSION_NUM)
          SET(LUA_FOUND true)
          BREAK()
        ENDIF()
        
        MESSAGE("Version mismatch ${_LUA_POSTFIXED_NAME} ${_LUA_VERSION_NUM} != ${_LUA_FIND_VERSION_NUM}")
      ENDIF()

    ENDIF()
      
  ENDFOREACH()
  
  IF(LUA_FOUND)
    BREAK()
  ENDIF()
  
ENDFOREACH()

IF(NOT LUA_FOUND)
  UNSET(LUA_INCLUDE_DIR)
  UNSET(LUA_LIBRARY)
  UNSET(LUA_VERSION)
ENDIF()

UNSET(_LUA_VERSION_NUM)
UNSET(_LUA_FIND_VERSION_MAYOR)
UNSET(_LUA_FIND_VERSION_MINOR)
UNSET(_LUA_FIND_VERSION_NUM)
UNSET(_LUA_FIND_VERSION_NUM_SHORT)
UNSET(_LUA_POSTFIXES)
UNSET(_LUA_NAMES)

IF(LUA_FIND_REQUIRED AND NOT LUA_FOUND)
  MESSAGE(FATAL_ERROR "Could not find Lua")
ENDIF()
