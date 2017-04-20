cmake_minimum_required(VERSION 3.6)
project(kinect_wrapper_try)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}
        /usr/local/opencv-3.2.0/share/OpenCV)

find_package (OpenCV 3.2.0 EXACT REQUIRED)

set(SOURCE_FILES  test.cpp)
add_executable(kinect_wrapper_try ${SOURCE_FILES})

target_include_directories (kinect_wrapper_try SYSTEM PUBLIC
        ${OpenCV_INCLUDE_DIRS})

install(FILES libfreenect.hpp
        DESTINATION .)
find_package (Threads)
    set(THREADS_USE_PTHREADS_WIN32 true)
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
    find_package(libfreenect REQUIRED)
    include_directories(. ${THREADS_PTHREADS_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})

    add_executable(freenect-cppview cppview.cpp)
    add_executable(freenect-cpp_pcview cpp_pc_view.cpp)

    target_link_libraries(freenect-cppview freenect ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${MATH_LIB} ${CMAKE_THREAD_LIBS_INIT}  ${FREENECT_LIBRARIES})
    target_link_libraries(freenect-cpp_pcview freenect ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${MATH_LIB} ${CMAKE_THREAD_LIBS_INIT}  ${FREENECT_LIBRARIES})

    install(TARGETS freenect-cppview freenect-cpp_pcview
            DESTINATION bin)
target_link_libraries (kinect_wrapper_try ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT}  ${FREENECT_LIBRARIES})