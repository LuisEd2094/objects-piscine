#ifndef SECRETARIALOFFICE_HPP
#define SECRETARIALOFFICE_HPP

#include <Rooms/Room.hpp>

class SecretarialOffice : public Room
{
private:
	std::vector<Form *> _archivedForms;

public:
};


#endif
