
#pragma once

#include <exception>
#include <string>
#include "The.h"

namespace Machine {

    class TheInsuffisant : public std::exception {
        public:
            TheInsuffisant(const std::string& the, double quantiteRequise, double quantiteDisponible);
            virtual const char* what() const noexcept override;

        private:
            std::string the_;
            double quantiteRequise_;
            double quantiteDisponible_;
            std::string message_;
    };

} // namespace Machine