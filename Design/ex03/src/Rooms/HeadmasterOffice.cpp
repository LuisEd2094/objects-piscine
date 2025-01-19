#include <Rooms/HeadmasterOffice.hpp>
#include <Person/Headmaster.hpp>
#include <Person/Secretary.hpp>

HeadmasterOffice::HeadmasterOffice() : Room(std::type_index(typeid(Headmaster)),
                                            std::type_index(typeid(Secretary)))
{
    addToList(this);
};
HeadmasterOffice::~HeadmasterOffice() {};