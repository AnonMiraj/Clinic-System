cmake_minimum_required(VERSION 3.5)

project(Clinc)

############################################################
# Create a library    
############################################################

# Generate the library from the library sources
add_library(main_library  
  src/admin.cpp
  src/appointment.cpp
  src/Cash.cpp
  src/Check.cpp 
  src/Credit.cpp
  src/doctor.cpp
  src/List_Of_Orders.cpp
  src/Medcin.cpp
  src/Medical_Specialization.cpp
  src/Medical_Insurance.cpp
  src/Order.cpp
  src/OrderItem.cpp
  src/other.cpp
  src/patient.cpp
  src/Payment.cpp
  src/person.cpp
  src/prescription.cpp
  src/Stock.cpp
  src/Transaction.cpp

  
)

target_include_directories(main_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(main 
    main.cpp
)

# link the new main_library target with the main target
target_link_libraries( main
    PRIVATE 
        main_library
)

