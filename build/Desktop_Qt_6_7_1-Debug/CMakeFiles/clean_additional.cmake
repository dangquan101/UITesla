# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appTestlaInfortament_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appTestlaInfortament_autogen.dir/ParseCache.txt"
  "appTestlaInfortament_autogen"
  )
endif()
