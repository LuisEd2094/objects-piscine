#include <SecretarialOffice.hpp>
#include <Secretary.hpp>

SecretarialOffice::SecretarialOffice() : Room(std::type_index(typeid(Secretary)))
{
    addToList(this);
};
SecretarialOffice::~SecretarialOffice() {};