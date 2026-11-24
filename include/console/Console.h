#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "Mot.h"
#include "Instruction.h"
namespace Console
{
    class InterfaceConsole
    {
    public:
        // `thes` : noms des thés que la machine sait préparer (fournis par la machine, pas par la console).
        explicit InterfaceConsole(const std::vector<std::string> &thes);
        ~InterfaceConsole();

        Instruction analyser(const std::string &ligne);

    private:
        bool estUnThe(const std::string &valeur) const;
        std::string listeThes() const;
        Instruction invalide(const std::string &message);
        bool lireQuantite(const std::string &texte, double &quantite);
        Mot lireMot(const std::string &nom);

        std::vector<std::string> thes_;
    };

} // namespace console
