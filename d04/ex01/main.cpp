#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

int			main(void)
{
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	Enemy* ennemy = new SuperMutant();
	Enemy* ennemy1 = new RadScorpion();

	pr->attack();
	pf->attack();
	delete ennemy;
	delete ennemy1;
	return (0);
}
