#include <fstream>
#include <iostream>
#include "LevelBalancedTree.hpp"

int main()
{
    LevelBalancedTree<std::string, int> tree;
    //left insert

	tree.insert("20", 20);
	tree.insert("19", 19);
	tree.insert("18", 18);
    // tree.insert(12, 12);
    // tree.insert(9,9);
    // tree.insert(17,17);
    // tree.insert(7,7);
    // tree.insert(5,5);
    // tree.insert(13,13);
    // tree.insert(15,15);
    // tree.insert(6,6);
    // tree.insert(16,16);
    // tree.insert(14,14);

    //right insert
    
    // tree.insert(18, 20);
	// tree.insert(19, 19);
	// tree.insert(20, 18);
    // tree.insert(26, 12);
    // tree.insert(29,9);
    // tree.insert(21,17);
    // tree.insert(31,7);
    // tree.insert(33,5);
    // tree.insert(25,13);
    // tree.insert(23,15);
    // tree.insert(32,6);
    // tree.insert(22,16);
    // tree.insert(24,14);

    //deletion left side
    
    // tree.insert(78,78);
    // tree.insert(44,44);
    // tree.insert(17,17);
    // tree.insert(62,62);
    // tree.insert(32,32);
    // tree.insert(87,87);
    // tree.insert(50,50);
    // tree.insert(48,48);

    //deletion right side

    // tree.insert(78,78);
    // tree.insert(112,44);
    // tree.insert(139,17);
    // tree.insert(94,62);
    // tree.insert(114,32);
    // tree.insert(59,87);
    // tree.insert(96,50);
    // tree.insert(98,48);

    //deletion question 14 delete 2 right

    // tree.insert(5,5);
    // tree.insert(10,10);
    // tree.insert(15,15);
    // tree.insert(12,12);
    // tree.insert(18,18);
    // tree.insert(2,2);
    // tree.insert(20,20);

    //deletion question 14 delete 2 left

    // tree.insert(25,5);
    // tree.insert(20,10);
    // tree.insert(15,15);
    // tree.insert(18,12);
    // tree.insert(12,18);
    // tree.insert(28,2);
    // tree.insert(10,20);

    //deletion question 15 delete 2

    // tree.insert(10,10);
    // tree.insert(2,2);
    // tree.insert(5,5);
    // tree.insert(15,15);
    // tree.insert(20,20);
    // tree.insert(11,11);
    // tree.insert(13,200);
    // tree.insert(12,12);
    const LevelBalancedTree<std::string, int> & treeRef= tree;
    // tree.remove(28);
    // tree.remove(98);
    // tree.remove(59);
    // tree.remove(96);
    // tree.remove(50);
    std::cout<<treeRef.contains("121")<<std::endl;
    // tree.remove(12);
    // std::cout<<tree.size()<<std::endl;
    // tree.insert(12,12);
    // std::cout<<tree.size()<<std::endl;

    // std::cout<<tree.isEmpty()<<std::endl;
    // std::cout<<tree.contains(4)<<std::endl;
    // std::cout<<tree.find(44)<<std::endl;
    // std::vector<std::string> v = tree.preOrder();
    // for(auto i: v){
    //     std::cout << i << std::endl;
    // }
    // return 0;
}