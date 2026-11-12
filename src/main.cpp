#include "Console/Console.h"
#include "../include/fabrique/FabriqueSysteme.h"

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
    Fabrique::FabriqueSysteme* fab = new Fabrique::FabriqueSysteme();

    const std::string modele = argv[1];

    Machine::Systeme* sys = fab->creerSysteme(modele);

    // TODO : créer et initialiser les objets de votre conception pour le modèle choisi.
    // Ce gabarit ne fournit aucune logique métier ni implémentation de patron.

    std::string selection;

    for (std::string ligne; std::cout << "> " << std::flush, std::getline(std::cin, ligne);) {
        try {
            const auto instruction = Console::analyser(ligne);
            switch (instruction.type) {
            case Console::TypeInstruction::Vide:
                break;
            case Console::TypeInstruction::Aide:
                Console::afficherAide();
                break;
            case Console::TypeInstruction::Quitter:
                std::cout << "Arrêt de PolyInfusion.\n";
                return 0;
            case Console::TypeInstruction::Invalide:
                std::cout << "Erreur : " << instruction.erreur << '\n';
                break;
            case Console::TypeInstruction::Selection:
                // TODO : déléguer la sélection à votre application (instruction.the).
                selection = instruction.the;
                std::cout << "sélection du thé " << selection << std::endl;
                break;
            case Console::TypeInstruction::Infuser:
                // TODO : déléguer la préparation d’une portion à votre application.
                sys->infuser(selection);
                break;
            case Console::TypeInstruction::Reserves:
                // TODO : déléguer l’affichage des réserves à votre application.
                sys->afficherReserves();
                break;
            case Console::TypeInstruction::RemplirEau:
                // TODO : déléguer le remplissage (instruction.quantite, en mL).
                sys->remplirEau(instruction.quantite);
                break;
            case Console::TypeInstruction::RemplirThe:
                // TODO : déléguer le remplissage (instruction.the, instruction.quantite en g).
                sys->remplirThe(instruction.the, instruction.quantite);
                break;
            case Console::TypeInstruction::Notifications:
                // TODO : déléguer l’abonnement ou le désabonnement (instruction.notificationsActives).
                sys->activerNotifications(true);
                break;
            }
        }
        catch (Machine::EauInsuffisante e) {
            std::cerr << e.what() << std::endl;
        }
        catch(Machine::TheInsuffisant e) {
            std::cerr << e.what() << std::endl;
        }
        catch(std::exception e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "\nArrêt de PolyInfusion.\n";
    return 0;
}
