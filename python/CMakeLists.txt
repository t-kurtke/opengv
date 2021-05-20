

add_subdirectory(pybind11)
find_package(Python COMPONENTS Interpreter Development REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})


pybind11_add_module(pyopengv pyopengv.cpp)
target_link_libraries(pyopengv PRIVATE opengv)

# Find where to install python libs.
#message(WARNING "python site " ${PYTHON_SITE_PACKAGES})
execute_process(COMMAND
    ${Python_EXECUTABLE} -c "import distutils.sysconfig; print('/'.join(distutils.sysconfig.get_python_lib().split('/')[-3:]))"
    OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)

set(PYTHON_INSTALL_DIR
    "${Python_SITELIB}"
    CACHE PATH "Path where to install pyopengv")
install(TARGETS pyopengv DESTINATION "${PYTHON_INSTALL_DIR}")

