
#include "../../include/commande/Commande.h"

namespace CMD
{

    Commande::Commande(bool estReversible) : estReversible_(estReversible) {}

    Commande::~Commande() = default;

    void Commande::redo(Machine::Systeme *) {}

    bool Commande::estReversible() const { return estReversible_; }

}
