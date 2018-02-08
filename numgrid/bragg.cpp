#include "bragg.h"
#include "error_handling.h"

// we use the same values as the DIRAC15 code
double get_bragg_angstrom(const int charge) {
    std::ostringstream err_msg;
    err_msg << "Bragg-Angstrom radius not found for element ";

    if (charge<1 || charge>86) {
        err_msg << charge;
	    NUMGRID_ERROR(err_msg);
    }

    const double radii[] = {0.35,                                                                                                                                                                                     0.35,
                            1.45, 1.05,                                                                                                                                                 0.85, 0.70, 0.65, 0.60, 0.50, 0.45,
                            1.80, 1.50,                                                                                                                                                 1.25, 1.10, 1.00, 1.00, 1.00, 1.00,
                            2.20, 1.80,                                                                                     1.60, 1.40, 1.35, 1.40, 1.40, 1.40, 1.35, 1.35, 1.35, 1.35, 1.30, 1.25, 1.15, 1.15, 1.15, 1.10,
                            2.35, 2.00,                                                                                     1.80, 1.55, 1.45, 1.45, 1.35, 1.30, 1.35, 1.40, 1.60, 1.55, 1.55, 1.45, 1.45, 1.40, 1.40, 1.40,
                            2.60, 2.15, 1.95, 1.85, 1.85, 1.85, 1.85, 1.85, 1.85, 1.80, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, 1.55, 1.45, 1.35, 1.30, 1.30, 1.35, 1.35, 1.35, 1.50, 1.90, 1.75, 1.60, 1.90, 1.50, 1.50};

    return radii[charge-1];
}
