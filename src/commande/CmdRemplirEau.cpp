
#include <iostream>
#include "../../include/commande/CmdRemplirEau.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdRemplirEau::CmdRemplirEau(double quantite) : quantite_(quantite) {}

    CmdRemplirEau::~CmdRemplirEau() = default;

    void CmdRemplirEau::executer(Machine::Systeme *sys)
    {
        sys->remplirEau(quantite_);
    }

} // namespace CMD
