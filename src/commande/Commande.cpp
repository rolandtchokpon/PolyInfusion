
#include "../../include/commande/Commande.h"

namespace CMD
{

    Commande::Commande(bool estReversible) : estReversible_(estReversible) {}

    Commande::~Commande() = default;

    void Commande::redo(Machine::Systeme *) {}

    void Commande::apercu(std::vector<std::string> &) const {}

    std::shared_ptr<Commande> Commande::cloner() const { return nullptr; }

    bool Commande::estReversible() const { return estReversible_; }

}
