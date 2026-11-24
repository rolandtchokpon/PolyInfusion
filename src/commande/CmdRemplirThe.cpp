
#include <iostream>
#include "../../include/commande/CmdRemplirThe.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdRemplirThe::CmdRemplirThe(const std::string &the, double quantite) : the_(the), quantite_(quantite) {}

    CmdRemplirThe::~CmdRemplirThe() = default;

    void CmdRemplirThe::executer(Machine::Systeme *sys)
    {
        sys->remplirThe(the_, quantite_);
    }

} // namespace CMD
