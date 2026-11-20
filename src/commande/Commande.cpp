
#include "../../include/commande/Commande.h"

namespace CMD
{

    Commande::Commande(bool estReversible) : estReversible_(estReversible) {}

    Commande::~Commande() = default;

    bool Commande::estReversible() const { return estReversible_; }

    const Console::Instruction &Commande::sauvgarde() { return instruction_; }

}