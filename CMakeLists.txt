cmake_minimum_required(VERSION 3.12)
project(UnToitPourTous)

set(CMAKE_CXX_STANDARD 14)

add_executable(UnToitPourTous main.cpp Sources/Goods/Good.cpp Sources/Goods/Residential.cpp Sources/Goods/Professional.cpp Sources/Goods/Ground.cpp Sources/Goods/Flat.cpp Sources/Goods/House.cpp Sources/Clients/Client.cpp Sources/Clients/Seller.cpp Sources/Clients/Buyer.cpp Sources/Agency.cpp Sources/Utils.cpp)
