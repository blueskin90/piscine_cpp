#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

#include "SuperMutant.hpp"

int			main(void)
{
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	Enemy* ennemy = new SuperMutant();

	pr->attack();
	pf->attack();
	return (0);
}
