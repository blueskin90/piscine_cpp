#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "EnergySword.hpp"

#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Cafard.hpp"

#include "Character.hpp"

int			main(void)
{
	Character* moi = new Character("moi");
	std::cout << *moi;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	moi->equip(pr);
	std::cout << *moi;
	moi->equip(pf);
	moi->attack(b);
	std::cout << *moi;
	moi->equip(pr);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;

	std::cout << " ==== GIVEN MAIN DONE === " << std::endl;
	Enemy* scorpion = new RadScorpion();
	Enemy* mutant = new SuperMutant();
	std::cout << "should be mutant: "  << mutant->getType() << " should be scorpion :" << scorpion->getType() << std::endl;
	std::cout << "Scorpion hp : " << scorpion->getHP() << std::endl;
	std::cout << "Mutant hp : " << mutant->getHP() << std::endl;
	moi->equip(pf);
	moi->attack(scorpion);
	moi->attack(mutant);
	std::cout << "Scorpion hp : " << scorpion->getHP() << std::endl;
	std::cout << "Mutant hp : " << mutant->getHP() << std::endl;
	moi->equip(pr);
	moi->attack(scorpion);
	moi->attack(mutant);
	std::cout << "Scorpion hp : " << scorpion->getHP() << std::endl;
	std::cout << "Mutant hp : " << mutant->getHP() << std::endl;
	moi->recoverAP();
	moi->attack(scorpion);
	moi->attack(mutant);
	std::cout << "Scorpion hp : " << scorpion->getHP() << std::endl;
	std::cout << "Mutant hp : " << mutant->getHP() << std::endl;

	moi->recoverAP();
	moi->attack(mutant);
	std::cout << "Mutant hp : " << mutant->getHP() << std::endl;

	*pf = *pr;

	moi->equip(pf);
	moi->recoverAP();
	moi->attack(mutant);
	std::cout << "Mutant hp : " << mutant->getHP() << std::endl;
	
	Character *chartest = new Character("Chartest");
	*chartest = *moi;
	chartest->recoverAP();
	chartest->attack(mutant);
	std::cout << "Mutant hp : " << mutant->getHP() << std::endl;


	std::cout << "testing monster copy" << std::endl;
	scorpion = new RadScorpion();
	std::cout << "Mutant hp : " << mutant->getHP() << std::endl;
	std::cout << "Scorpion hp : " << scorpion->getHP() << std::endl;
	*mutant = *scorpion;
	std::cout << "Scorpion copied in mutant" << std::endl;
	std::cout << "Mutant hp : " << mutant->getHP() << " should be the same as the Scorpion before" << std::endl;

	Enemy *cafard = new Cafard();
	AWeapon *sword = new EnergySword();

	moi->equip(sword);
	moi->attack(cafard);

	return 0;
}
