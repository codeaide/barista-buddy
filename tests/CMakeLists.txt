# global include directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stubs)

# Barista Buddy controller library
add_library(arduino-stubs OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/stubs/ArduinoStub.cpp)

# Barista Buddy controller library
add_library(babu-controller OBJECT ${CMAKE_SOURCE_DIR}/src/controller/controllerImpl.cpp)
target_include_directories(babu-controller PUBLIC ${CMAKE_SOURCE_DIR}/src/controller)

# Barista Buddy frontend library
add_library(babu-frontend OBJECT ${CMAKE_SOURCE_DIR}/src/frontend/frontendImpl.cpp)
target_include_directories(babu-frontend PUBLIC ${CMAKE_SOURCE_DIR}/src/frontend)

# Barista Buddy relay library
add_library(babu-relay OBJECT ${CMAKE_SOURCE_DIR}/src/relay/relayImpl.cpp)
target_include_directories(babu-relay PUBLIC ${CMAKE_SOURCE_DIR}/src/relay)

# Barista Buddy sensor library
add_library(babu-sensor OBJECT ${CMAKE_SOURCE_DIR}/src/sensor/sensorImpl.cpp)
target_include_directories(babu-sensor PUBLIC ${CMAKE_SOURCE_DIR}/src/sensor)

# create test executables
add_executable(test-controller test-controller.cpp
                               $<TARGET_OBJECTS:arduino-stubs>
                               $<TARGET_OBJECTS:babu-controller>)
add_executable(test-frontend   test-frontend.cpp
                               $<TARGET_OBJECTS:arduino-stubs>
                               $<TARGET_OBJECTS:babu-frontend>)
add_executable(test-relay      test-relay.cpp
                               $<TARGET_OBJECTS:arduino-stubs>
                               $<TARGET_OBJECTS:babu-relay>)
add_executable(test-sensor     test-sensor.cpp
                               $<TARGET_OBJECTS:arduino-stubs>
                               $<TARGET_OBJECTS:babu-sensor>)

# link test executables to GoogleTest
target_link_libraries(test-controller GTest::gtest_main)
target_link_libraries(test-frontend GTest::gtest_main)
target_link_libraries(test-relay GTest::gtest_main)
target_link_libraries(test-sensor GTest::gtest_main)

# enable CMake’s test runner to discover the tests included in the executable
include(GoogleTest)
gtest_discover_tests(test-controller)
gtest_discover_tests(test-frontend)
gtest_discover_tests(test-relay)
gtest_discover_tests(test-sensor)
