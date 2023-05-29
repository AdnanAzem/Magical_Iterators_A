#include <iostream>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Check MagicalContainer Method Size"){
    MagicalContainer mc;
    CHECK(mc.size() == 0);

    CHECK_NOTHROW(mc.addElement(2));
    CHECK(mc.size() == 1);

    CHECK_NOTHROW(mc.addElement(5));
    CHECK(mc.size() == 2);

    CHECK_NOTHROW(mc.removeElement(5));
    CHECK_NOTHROW(mc.removeElement(2));
    CHECK(mc.size() == 0);

}

TEST_CASE("Check MagicalContainer Method addElement"){
    MagicalContainer mc;
    CHECK_NOTHROW(mc.addElement(2));
    CHECK_NOTHROW(mc.addElement(5));
    CHECK_NOTHROW(mc.addElement(7));
    CHECK_NOTHROW(mc.addElement(1));
}

TEST_CASE("Check MagicalContainer Method removeElement"){
    MagicalContainer mc;
    CHECK_NOTHROW(mc.addElement(2));
    CHECK_NOTHROW(mc.addElement(5));
    CHECK_NOTHROW(mc.addElement(7));
    CHECK_NOTHROW(mc.addElement(1));

    CHECK_NOTHROW(mc.removeElement(2));
    CHECK_NOTHROW(mc.removeElement(5));
    CHECK_NOTHROW(mc.removeElement(7));
    CHECK_NOTHROW(mc.removeElement(1));
}

TEST_CASE("init Iterators"){  
    MagicalContainer mc;
    CHECK_NOTHROW(mc.addElement(2));
    CHECK_NOTHROW(mc.addElement(5));
    CHECK_NOTHROW(mc.addElement(7));
    CHECK_NOTHROW(mc.addElement(1));

    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(mc));
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator sidIter(mc));
    CHECK_NOTHROW(MagicalContainer::PrimeIterator priIter(mc));
}

TEST_CASE("Check AscendingIterator"){
    MagicalContainer mc;
    CHECK_NOTHROW(mc.addElement(57));
    CHECK_NOTHROW(mc.addElement(13));
    CHECK_NOTHROW(mc.addElement(99));
    CHECK_NOTHROW(mc.addElement(1));

    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(mc));

    MagicalContainer::AscendingIterator ascIter(mc);
    auto it = ascIter.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 13);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 57);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 99);
    CHECK_THROWS(++it);

}

TEST_CASE("Check SideCrossIterator"){
    MagicalContainer mc;
    CHECK_NOTHROW(mc.addElement(57));
    CHECK_NOTHROW(mc.addElement(13));
    CHECK_NOTHROW(mc.addElement(99));
    CHECK_NOTHROW(mc.addElement(1));

    CHECK_NOTHROW(MagicalContainer::SideCrossIterator ascIter(mc));

    MagicalContainer::SideCrossIterator ascIter(mc);
    auto it = ascIter.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 99);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 13);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 57);
    CHECK_THROWS(++it);

}

TEST_CASE("Check SideCrossIterator"){
    MagicalContainer mc;
    CHECK_NOTHROW(mc.addElement(57));
    CHECK_NOTHROW(mc.addElement(13));
    CHECK_NOTHROW(mc.addElement(99));
    CHECK_NOTHROW(mc.addElement(1));

    CHECK_NOTHROW(MagicalContainer::PrimeIterator ascIter(mc));

    MagicalContainer::PrimeIterator ascIter(mc);
    auto it = ascIter.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 13);
    CHECK_NOTHROW(++it);
}



