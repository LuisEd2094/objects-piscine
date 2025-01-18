#ifndef ROOM_TPP
#define ROOM_TPP
#include <Rooms/Room.hpp>

template <typename... Args>
Room::Room(Args... types) : Room()
{
    std::type_index typeArray[] = {types...};
    for (const auto &type : typeArray)
    {
        _allowedOccupants.push_back(type);
    }
}

#endif