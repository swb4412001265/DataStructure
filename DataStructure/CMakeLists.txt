cmake_minimum_required(VERSION 3.5)
project(DataStructureCppBU)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Array3.cpp
    ArrayAccess.cpp
    ArrayListProg4_wClass.cpp
    ASCII.cpp
    BagMenuProg3-withContainer.cpp
    BagMenuProg3-withContainer1.cpp
    BagProg3B.cpp
    BagProg3BContainer.cpp
    BagProg_nocontainer.cpp
    break1.cpp
    DoubleLinkedList.cpp
    DoubleLinkedList4.cpp
    DynArray_HW2_WenboSu.cpp
    hashprog1a.cpp
    HashProgRef1.cpp
    HW1_ShangSanJiaoJuZhen.cpp
    HW1_Xiaohe.cpp
    LindaSayHW1.cpp
    MidTermPro1CalculatorWenboSu.cpp
    MidTermPro2AscendingOrderWenboSu.cpp
    MidTermPro2AscendingOrderWenboSuV2.cpp
    MidTermPro3AddRemoveWenboSu.cpp
    MidTermPro4MemManageWenboSu.cpp
    QuadricWithContainerClassHW3_WenboSu.cpp
    QuadrticWithClass.cpp
    QuadrticWithContainerClassHW3_WenboSu.cpp
    Queue3A.cpp
    Stack.cpp
    StackWithContainer.cpp
    suplimentary_homework_1_WenboSu.cpp
    SupplementHW1_WenboSu.cpp)

add_executable(DataStructureCppBU ${SOURCE_FILES})