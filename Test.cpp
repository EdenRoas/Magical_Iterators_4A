#include <iostream>
#include <sstream>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Initialization") {
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(1));//1
    container.addElement(4);//1 4
    container.addElement(15);// 1 4 15
    container.addElement(2);// 1 4 15 2
    container.addElement(10);// 1 4 15 2 10
    CHECK_EQ(container.size(), 5);
    CHECK_NOTHROW(container.removeElement(10));// 1 4 15 2
    CHECK_THROWS(container.removeElement(10));
    CHECK_EQ(container.size(), 4);
    container.addElement(17);// 1 4 15 2 17
    container.addElement(13);// 1 4 15 2 17 13
    container.addElement(9);// 1 4 15 2 17 13 9
    CHECK_NOTHROW(container.removeElement(2));
    CHECK_EQ(container.size(), 6);// 1 4 15 17 13 9



    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(container));//-> 1 4 9 13 15 17
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator sidIter(container));// -> 1 9 4 13 15 17
    CHECK_NOTHROW(MagicalContainer::PrimeIterator priIter(container));// -> 13 17
}

TEST_CASE("AscendingIteratorTest") {
    MagicalContainer container;
    container.addElement(1); 
    container.addElement(4);
    container.addElement(15);
    container.addElement(17);
    container.addElement(13);
    container.addElement(9);
    MagicalContainer::AscendingIterator ascIter(container); //> 1 4 9 13 15 17

    CHECK(ascIter.begin() < ascIter.end());
    CHECK_FALSE(ascIter.begin() > ascIter.end());
    CHECK(ascIter.begin() != ascIter.end());
    CHECK_FALSE(ascIter.begin() == ascIter.end());

    auto num = ascIter.begin();
    CHECK_EQ(*num, 1);
    CHECK_NOTHROW(++num);
    CHECK_EQ(*num, 4);
    CHECK_NOTHROW(++num);
    CHECK_EQ(*num, 9);
    CHECK_THROWS(++num);
    CHECK_EQ(*num, 13);

}


TEST_CASE("SideCrossIteratorTest") {
    MagicalContainer container;
    container.addElement(1); 
    container.addElement(4);
    container.addElement(15);
    container.addElement(17);
    container.addElement(13);
    container.addElement(9);
    MagicalContainer::SideCrossIterator sidCrIter(container); // 1 9 4 13 15 17


    CHECK(sidCrIter.begin() < sidCrIter.end());
    CHECK_FALSE(sidCrIter.begin() > sidCrIter.end());
    CHECK(sidCrIter.begin() != sidCrIter.end());
    CHECK_FALSE(sidCrIter.begin() == sidCrIter.end());

    auto num = sidCrIter.begin();
    CHECK_EQ(*num, 1);
    CHECK_NOTHROW(++num);
    CHECK_EQ(*num, 9);
    CHECK_NOTHROW(++num);
    CHECK_EQ(*num, 4);
    CHECK_THROWS(++num);
    CHECK_EQ(*num, 13);
    CHECK_THROWS(++num);
    CHECK_EQ(*num, 15);
    CHECK_THROWS(++num);
    CHECK_EQ(*num, 17);


}

TEST_CASE("PrimeIteratorTest") {
    MagicalContainer container;
    container.addElement(1); 
    container.addElement(4);
    container.addElement(15);
    container.addElement(17);
    container.addElement(13);
    container.addElement(9);
    MagicalContainer::PrimeIterator primIter(container); // 17 , 13
    CHECK(*primIter.begin() > *primIter.end());
    CHECK_FALSE(*primIter.begin() < *primIter.end());
    CHECK(*primIter.begin() != *primIter.end());
    CHECK_FALSE(*primIter.begin() == *primIter.end());

    auto num = primIter.begin();
    CHECK_EQ(*num, 17);
    CHECK_NOTHROW(++num);
    CHECK_EQ(*num, 13);
    CHECK_THROWS(++num);



    
}
