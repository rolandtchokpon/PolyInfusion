
#include "../../include/routine/RegistreRoutine.h"

namespace Routine
{
    RegistreRoutine::RegistreRoutine() { routines_.clear(); };

    RegistreRoutine::~RegistreRoutine() = default;

    void RegistreRoutine::enregister(const std::string &nom, const std::unique_ptr<CMD::Commande> &routine)
    {
        routines_[nom] = std::unique_ptr<CMD::Commande>(routine.get());
    }

    bool RegistreRoutine::existe(const std::string &nom)
    {
        return routines_[nom] != nullptr;
    }

    void RegistreRoutine::apercu(const std::string &nom)
    {
        routines_[nom]->apercu();
    }

}