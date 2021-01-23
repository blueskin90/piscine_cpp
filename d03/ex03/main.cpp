#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main(void) {
	FragTrap	robot("FragJack");
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

	ScavTrap	robot1("ScavJack");
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


	NinjaTrap	robot2("NinjaJack");
	NinjaTrap	test2 = robot2;

	robot2.meleeAttack("enemy");
	robot2.rangedAttack("enemy");
	robot2.takeDamage(30);
	robot2.takeDamage(30);
	robot2.takeDamage(3);
	robot2.takeDamage(30);
	robot2.takeDamage(30);
	robot2.takeDamage(30);
	robot2.beRepaired(40);
	robot2.beRepaired(100);
	robot2.ninjaShoebox(robot);
	robot2.ninjaShoebox(robot1);
	robot2.ninjaShoebox(test2);

	return 0;
}
