#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	FragTrap	robot("Jack");
	FragTrap	test = robot;

	robot.meleeAttack("enemy");
	robot.rangedAttack("enemy");
	robot.takeDamage(30);
	robot.takeDamage(30);
	robot.takeDamage(3);
	robot.takeDamage(30);
	robot.takeDamage(30);
	robot.takeDamage(30);
	robot.beRepaired(40);
	robot.beRepaired(100);
	robot.vaulthunter_dot_exe("enemy");
	robot.vaulthunter_dot_exe("enemy");
	robot.vaulthunter_dot_exe("enemy");
	robot.vaulthunter_dot_exe("enemy");
	robot.vaulthunter_dot_exe("enemy");
	robot.meleeAttack("enemy");

	ScavTrap	robot1("Jack");
	ScavTrap	test1 = robot1;

	robot1.meleeAttack("enemy");
	robot1.rangedAttack("enemy");
	robot1.takeDamage(30);
	robot1.takeDamage(30);
	robot1.takeDamage(3);
	robot1.takeDamage(30);
	robot1.takeDamage(30);
	robot1.takeDamage(30);
	robot1.beRepaired(40);
	robot1.beRepaired(100);
	robot1.challengeNewcomer("enemy");
	robot1.challengeNewcomer("enemy");
	robot1.challengeNewcomer("enemy");
	robot1.challengeNewcomer("enemy");
	robot1.challengeNewcomer("enemy");
	robot1.meleeAttack("enemy");

	return 0;
}
