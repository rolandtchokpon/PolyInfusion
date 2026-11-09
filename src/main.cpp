#include "console/Console.h"

#include <iostream>
#include <string>

#ifdef _WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

int main(int argc, char* argv[])
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    if (argc != 2 || (std::string(argv[1]) != "compact" && std::string(argv[1]) != "pro")) {
        std::cerr << "Utilisation : PolyInfusion <compact|pro>\n";
        return 1;
    }
    const std::string modele = argv[1];

    // TODO : créer et initialiser les objets de votre conception pour le modèle choisi.
    // Ce gabarit ne fournit aucune logique métier ni implémentation de patron.
    std::cout << "Machine PolyInfusion démarrée : modèle "
              << (modele == "compact" ? "Compact" : "Pro") << ".\n";

    for (std::string ligne; std::cout << "> " << std::flush, std::getline(std::cin, ligne);) {
        const auto instruction = console::analyser(ligne);
        switch (instruction.type) {
        case console::TypeInstruction::Vide:
            break;
        case console::TypeInstruction::Aide:
            console::afficherAide();
            break;
        case console::TypeInstruction::Quitter:
            std::cout << "Arrêt de PolyInfusion.\n";
            return 0;
        case console::TypeInstruction::Invalide:
            std::cout << "Erreur : " << instruction.erreur << '\n';
            break;
        case console::TypeInstruction::Selection:
            // TODO : déléguer la sélection à votre application (instruction.the).
            std::cout << "À implémenter : sélection du thé.\n";
            break;
        case console::TypeInstruction::Infuser:
            // TODO : déléguer la préparation d’une portion à votre application.
            std::cout << "À implémenter : préparation du thé.\n";
            break;
        case console::TypeInstruction::Reserves:
            // TODO : déléguer l’affichage des réserves à votre application.
            std::cout << "À implémenter : affichage des réserves.\n";
            break;
        case console::TypeInstruction::RemplirEau:
            // TODO : déléguer le remplissage (instruction.quantite, en mL).
            std::cout << "À implémenter : remplissage d’eau.\n";
            break;
        case console::TypeInstruction::RemplirThe:
            // TODO : déléguer le remplissage (instruction.the, instruction.quantite en g).
            std::cout << "À implémenter : remplissage de thé.\n";
            break;
        case console::TypeInstruction::Notifications:
            // TODO : déléguer l’abonnement ou le désabonnement (instruction.notificationsActives).
            std::cout << "À implémenter : gestion des notifications à distance.\n";
            break;
        }
    }
    std::cout << "\nArrêt de PolyInfusion.\n";
    return 0;
}
