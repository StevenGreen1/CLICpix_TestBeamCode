#ifndef PHYSICAL_CONSTANTS_H
#define PHYSICAL_CONSTANTS_H 1

#include "SystemOfUnits.h"


namespace PhysicalConstants
{
    using namespace SystemOfUnits;

    static const double pi = 3.14159265358979323846;
    static const double twopi  = 2*pi;
    static const double halfpi = pi/2;
    static const double pi2    = pi*pi;
    // 
    //
    static const double Avogadro = 6.0221367e+23/mole;
    //
    //
    static const double c_light = 2.99792458e+8 * m/s;	// c = 299.792458 mm/ns

    static const double c_squared = c_light * c_light;	// c2 = 898.7404 (mm/ns)**2
    //
    //
    //
    static const double h_Planck = 6.6260755e-34 * joule*s;  // h = 4.13566e-12 MeV*ns

    static const double hbar_Planck = h_Planck/twopi;	 // hbar = 6.58212e-13 MeV*ns

    static const double hbarc = hbar_Planck * c_light;	 // hbarc = 197.32705e-12 MeV*mm

    static const double hbarc_squared = hbarc * hbarc;
    //
    //
    //
    static const double electron_charge = - eplus;	// see G4SystemOFUnits.hh

    static const double e_squared = eplus * eplus;
    //
    //
    //
    static const double electron_mass_c2 = 0.51099906 * MeV;

    static const double proton_mass_c2   = 938.27231 * MeV;

    static const double neutron_mass_c2  = 939.56563 * MeV;
    static const double pion_mass_c2  = 139.57018 * MeV;
    static const double muon_mass_c2  = 105.65836668 * MeV;

    static const double amu_c2 =           931.49432 * MeV;  // atomic equivalent mass unit

    static const double amu    =           amu_c2/c_squared; // atomic mass unit
    //
    //
    //
    static const double mu0 = 4*pi*1.e-7 * henry/m;	// permeability of free space
    // mu0 = 2.01334e-16 Mev*(ns*eplus)**2/mm

    static const double epsilon0 = 1./(c_squared*mu0);	// permittivity of free space
    // epsil0 = 5.52636e+10 eplus**2/(MeV*mm)
    //
    //
    //
    static const double elm_coupling = e_squared/(4*pi*epsilon0); // electromagnetic coupling
    // coupling = 1.43996e-12 MeV*mm/(eplus**2)

    static const double fine_structure_const = elm_coupling/hbarc;

    static const double classic_electr_radius = elm_coupling/electron_mass_c2;

    static const double electron_Compton_length = hbarc/electron_mass_c2;

    static const double Bohr_radius = electron_Compton_length/fine_structure_const;

    static const double alpha_rcl2 = fine_structure_const
        *classic_electr_radius
        *classic_electr_radius;

    static const double twopi_mc2_rcl2 = twopi*electron_mass_c2
        *classic_electr_radius
        *classic_electr_radius;
    //
    //
    //
    static const double k_Boltzmann = 8.617385e-11 * MeV/kelvin;
    //
    //
    //
    static const double STP_Temperature = 295*kelvin;

    static const double STP_Pressure = 1.*atmosphere;

    static const double kGasThreshold = 1.e-2*g/cm3;
}
#endif     /* PHYSICAL_CONSTANTS_H */
