
#pragma once
#include "IRoutine.h"
#include <unordered_map>

namespace Routine
{

    class RegistreRoutine
    {
    public:
        RegistreRoutine();
        ~RegistreRoutine();
        void enregister(const std::string &nom, const std::unique_ptr<CMD::Commande> &routine);
        bool existe(const std::string &nom);
        void apercu(const std::string &nom);

    private:
        std::unordered_map<std::string, std::unique_ptr<CMD::Commande>>
            routines_;
    };

} // namespace Routine